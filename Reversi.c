#include<stdio.h>

#define BOARD_SIZE 8

typedef enum {WHT=-1, EMP=0, BLK=1, OUT=2} Piece;

void Board_Init(void);          //盤面の初期化
void Board_Output(void);        //盤面の出力
int Board_Scan_Pass(int player);    //パスの有無調査
void Board_Input(int player);   //入力処理
int Board_Suffice(void);        //盤面が全て埋まったかどうかの判定
void Game_Finish(void);         //ゲーム終了

void Umetarou(int player);      //盤面埋め太郎_(:3」∠)_


Piece board[BOARD_SIZE][BOARD_SIZE];



//−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
//メイン関数
//−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
int main(void){
    int player = BLK;
    
    Board_Init();
    Board_Output();
    
    while(1){
        
        switch(player){
            case BLK : printf("黒の番です。\n"); break;
            case WHT : printf("白の番です。\n"); break;
        }
        
        Board_Input(player);
        //Umetarou(player);       //_(:3」∠)_
        Board_Output();
        
        if( Board_Suffice() == 0 ){       //ゲーム終了判定(盤面が全て埋まった)
            
            break;
        }
        
        player *= -1;
        
    }
    
    Game_Finish();
    
    return 0;
}



//−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
//盤面の初期化
//−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
void Board_Init(void){
    int i, j;
    for( i = 0; i < BOARD_SIZE; i++ ){
        for( j = 0; j < BOARD_SIZE; j++ ){
            board[i][j] = EMP;
        }
    }
    board[3][3] = board[4][4] = BLK;
    board[3][4] = board[4][3] = WHT;
}



//−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
//盤面の出力
//−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
void Board_Output(void){
    int i, j;
    
    printf("  Y1Y2Y3Y4Y5Y6Y7Y8\n");
    for( i = 0; i < 8; i++ ){
        printf("X%d",i+1);
        for( j = 0; j < 8; j++ ){
            switch(board[i][j]){
                case EMP: printf("・"); break;
                case BLK: printf("○"); break;
                case WHT: printf("●"); break;
            }
        }
        puts("");
    }
}



//−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
//パスの有無調査
//−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
int Board_Scan_Pass(int player){
    int i, j;
    int n, m;
    int k;
    int flag;
    for( i = 0; i < BOARD_SIZE; i++ ){
        for( j = 0; j < BOARD_SIZE; j++ ){
            if( board[i][j] != EMP ) continue;
            
            for( n = -1; n <= 1; n++ ){
                for( m = -1; m <= 1; m++ ){
                    if( n == 0 && m == 0 ) continue;
                    flag = 0;
                    k = 1;
                    while(1){
                        
                        k++;
                    }
                    
                    
                }
            }
            
        }
    }
}



//−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
//入力処理
//−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
void Board_Input(int player){
    int x, y;
    while(1){
        printf("X > "); scanf("%d", &x); x--;
        printf("Y > "); scanf("%d", &y); y--;
        if( x >= 0 && x < 8 && y >= 0 && y < 8 ){
            if( board[x][y] == EMP ) break;
        }
        printf("\aそこには置けません！\n");
    }
    board[x][y] = player;
}



//−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
//盤面が全て埋まったかどうかの判定
//−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
int Board_Suffice(void){
    int i, j;
    int f = 0;
    
    for( i = 0; i < BOARD_SIZE; i++ ){
        for( j = 0; j < BOARD_SIZE; j++ ){
            if( board[i][j] == EMP ) f = 1;
        }
    }
    
    
    return f;
}



//−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
//ゲーム終了処理
//−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
void Game_Finish(void){
    int b,w;
    b = w = 0;
    int i, j;
    for( i = 0; i < BOARD_SIZE; i++ ){
        for( j = 0; j < BOARD_SIZE; j++ ){
            switch( board[i][j] ){
            case BLK: b += 1; break;
            case WHT: w += 1; break;
            }
        }
    }
    printf("黒：%d  白：%d\n",b,w);
    if( b > w )         printf("黒の勝利です！\n");
    else if( b < w )    printf("白の勝利です！\n");
    else                printf("引き分け\n");
}



//−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
//盤面埋め太郎_(:3」∠)_
//−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
void Umetarou(int player){
    int i, j;
    
    for( i = 0; i < BOARD_SIZE; i++ ){
        for( j = 0; j < BOARD_SIZE; j++ ){
            if( board[i][j] == EMP ){
                board[i][j] = player;
                return;
            }
        }
    }
}
