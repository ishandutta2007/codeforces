#include<bits/stdc++.h>
using namespace std;
int const maxn = 3e5+10, inf = 1e9;
int n,m;
int cnt[30][30], dp[(1 << 20) + 10];
char s[maxn];
/**
    Let's see when we add new letter x to mask
    OOOOOO   x
    for y in mask we must add cnt[y][x] * (pos[x] - pos[y])
    = cnt[y][x] * pos[x] - (cnt[y][x] * pos[y])
    We don't know pos[y]? Just think like
    when x is added, x is affected other new later C mask
    by  cnt[x][c] * pos[x] , then just minus it to calculate
    contribution correctly
*/
void upd(int &x, int y){
    if(x > y) x = y;
}
int main(){
    scanf("%d%d%s",&n, &m ,s + 1);
    for(int i = 1 ;i < n; i++){
        int x = s[i] - 'a' , y = s[i + 1] - 'a';
        if(x > y) swap(x , y);
        cnt[x][y] ++;
    }
    int const mm = (1 << m) - 1;
    for(int i = 1 ; i <= mm ; i++)
        dp[i] = inf;
    for(int i = 0 ; i <= mm ; i++){
        for(int j = 0 ;j < m ; j++){
            if(i & (1 <<j)) continue;
            int nmask = i | (1 << j), cost = 0, pos = __builtin_popcount(i);
            for(int v = 0 ; v < m ; v++){
                if(v != j)
                cost += ((i & (1 << v) )? 1 : -1) * cnt[min(v,j)][max(v,j)] * pos;
            }
            upd(dp[nmask] , dp[i] + cost);
        }
    }
    printf("%d\n",dp[mm]);
}