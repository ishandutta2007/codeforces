#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1005;
typedef long long LL;
int n, m;
char s[N][N];
int Right[N][N], Down[N][N];
bool st[N][N];
LL ans = 0;
/*
Right[i][j]  (i, j) 
Down 

*/

int work(int x, int y, int len){
    int res = 2e9;
    for(int i = x; i <= x + len - 1; i++)
        res = min(res, Right[i][y]);
    return res;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%s", s[i] + 1);
    }
    for(int i = 1; i <= n; i++){
        for(int j = m; j; j--){
            Right[i][j] = s[i][j] == s[i][j + 1] ? Right[i][j + 1] + 1 : 1;
        }
    }

    for(int j = 1; j <= m; j++){
        for(int i = n; i; i--){
            Down[i][j] = s[i][j] == s[i + 1][j] ? Down[i + 1][j] + 1 : 1;
        }
    }
    
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if(st[i][j]) continue;
            int DL = Down[i][j], L1 = i - DL, L3 = i + DL;
            if(L1 < 1 || L3 + DL - 1 > n) continue;
            if(s[L1][j] == s[i][j] || s[L3][j] == s[i][j]) continue;
            if(Down[L1][j] < DL || Down[L3][j] < DL) continue;
            int RL = min(min(work(L1, j, DL), work(i, j, DL)), work(L3, j, DL));
            for(int k = j; k <= j + RL - 1; k++)
                st[i][k] = true;
            ans += (1 + RL) * RL / 2;
        }
    }
    printf("%lld\n", ans);
    return 0;
}