#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int Mod = 1000000007;
const int MaxN = 4005;

int N;
int pascal[MaxN][MaxN];

void input(){
    scanf("%d", &N);
}

void mkpascal(){
    pascal[0][0] = 1;
    for(int r = 1; r <= N+1; r++){
        pascal[r][0] = 1;
        for(int c = 1; c <= r; c++){
            pascal[r][c] = (pascal[r-1][c-1] + pascal[r-1][c]) % Mod;
        }
    }
}

int bad[MaxN], good[MaxN];

int main(){
    input();
    mkpascal();
    
    good[0] = 1;
    bad[0] = 0;

    for(int s = 1; s <= N; s++){
        good[s] = bad[s] = 0;

        for(int m = 1; m <= s; m++){
            good[s] = (good[s] + (LL)pascal[s-1][m-1] * good[s-m]) % Mod;
            bad[s]  = (bad[s]  + (LL)pascal[s-1][m-1] * bad[s-m]) % Mod;
        }

        bad[s] = (bad[s] + good[s-1]) % Mod;
        bad[s] = (bad[s] + bad[s-1]) % Mod;
    }

    printf("%d\n", bad[N]);

}