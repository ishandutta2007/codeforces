#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MaxN = 55;

char board[MaxN][MaxN];
bool attacked[MaxN][MaxN];
int N;

void input(){
	scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%s", board[i]);
    }
}

char result[MaxN*2][MaxN*2];

int main(){
	input();

    for(int i = 0; i <= 2*N; i++){
        for(int j = 0; j <= 2*N; j++){
            result[i][j] = '.';
        }
        result[i][2*N+1] = 0;
    }
    
    for(int movey = -N; movey <= N; movey++){
        for(int movex = -N; movex <= N; movex++){
            if(movey == 0 && movex == 0) continue;

            bool ok = true;

            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    if(board[i][j] != 'o') continue;

                    int newI = i + movey,
                        newJ = j + movex;

                    if(newI < 0 || newI >= N || newJ < 0 || newJ >= N) continue;
                    if(board[newI][newJ] == '.'){ ok = false; break; }
                }
            }

            if(!ok) continue;
            result[movey+N][movex+N] = 'x';

            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    if(board[i][j] != 'o') continue;

                    int newI = i + movey,
                        newJ = j + movex;
                    if(newI < 0 || newI >= N || newJ < 0 || newJ >= N) continue;

                    attacked[newI][newJ] = true;
                }
            }
        }
    }

    bool wholeOk = true;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(board[i][j] == 'x' && !attacked[i][j]){
                wholeOk = false;
            }
        }
    }

    if(!wholeOk){
        printf("NO\n");
        return 0;
    }

    result[N][N] = 'o';
   

    printf("YES\n");
    for(int i = 1; i < 2*N; i++){
        result[i][2*N] = 0;
        printf("%s\n", result[i]+1);
    }
}