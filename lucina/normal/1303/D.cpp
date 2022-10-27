#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10 ;
using ll = long long ;
int f[64] ;


int solve () {
    ll n, sum = 0;
    int  m;
    scanf("%lld %d", &n, &m);
    fill(f, f + 32 , 0);
    for (int i = 1 ; i <= m ; i ++) {
        int x;
        scanf("%d", &x);
        f[__lg(x)] ++ ;
        sum += x;
    }
    int ans = 0;
    if (sum < n) return -1 ;
    for (int i = 0 ; i <= 60 ; i ++) {
        if (n >> i & 1 ) {
            int j = i;
            while (f[j] == 0) ++ j;
            -- f[j];
            while(j > i) {
                -- j;
                f[j] ++ ;
                ++ ans;
            }
        }
        f[i + 1] += (f[i]) / 2;
    }
    return ans;
}

int main () {
    int T;
    for(scanf("%d", &T); T -- ; printf("%d\n", solve()));

}