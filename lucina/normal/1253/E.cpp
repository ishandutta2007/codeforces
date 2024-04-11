#include<bits/stdc++.h>
using namespace std;
int m;
struct seg{
    int l, r;
    bool operator < (const seg &x) const{
        return l < x.l;
    }
    void read(){
        int x, y;
        scanf("%d %d", &x, &y);
        l = max(0, x - y); r = min(m, x + y);
    }
};
int const nax = 1e5 + 10;
int n, dp[nax]; /// minimum cost to cover from 1 ... i
seg a[105];

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1 ;i <= n ;i ++){
        a[i].read();
    }
    sort(a + 1 ,  a + 1 + n);
    int const inf = 1e9;
    for(int i = 1 ;i <= m ; i++)
        dp[i] = inf;
    for(int i = 1 ;i <= n ; i++){
        for(int j = 0 ; j <= m ; j ++){
            int l = max(0 , a[i].l - j - 1);
            int r = min(m , a[i].r + j);
            dp[r] = min(dp[r], dp[l] + j);
        }
        for(int j = m ;j >= 1 ; j --)
            dp[j - 1] = min(dp[j - 1], dp[j]);
    }
    printf("%d\n", dp[m]);
}