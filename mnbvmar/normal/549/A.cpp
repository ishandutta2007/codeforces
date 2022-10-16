#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

char tab[55][55];
int N, M;

void input(){
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++){
        scanf("%s", tab[i]);
    }
}

int main(){
    input();

    int result = 0;
    for(int r = 0; r < N-1; r++){
        for(int c = 0; c < M-1; c++){
            vector<char> data{tab[r][c],tab[r][c+1],tab[r+1][c],tab[r+1][c+1]};
            sort(data.begin(), data.end());

            if(data == vector<char>{'a','c','e','f'}){
                result++;
            }
        }
    }
    printf("%d\n", result);
}