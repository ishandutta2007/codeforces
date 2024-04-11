#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N, M;
char tab[105][105];
int need[105][105];

void input(){
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++){
        scanf("%s", tab[i]);
        for(int j = 0; j < M; j++){
            need[i][j] = (tab[i][j] == 'B' ? -1 : 1);
        }
    }
}

int current[105][105];

int main(){
    input();

    int result = 0;
    for(int i = N-1; i >= 0; i--){
        for(int j = M-1; j >= 0; j--){
            if(need[i][j] != current[i][j]){
                int coef = need[i][j] - current[i][j];
                for(int a = 0; a <= i; a++){
                    for(int b = 0; b <= j; b++){
                        current[a][b] += coef;
                    }
                }
                result++;
            }
        }
    }
    printf("%d\n", result);
}