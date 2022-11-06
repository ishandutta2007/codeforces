#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 5e3 + 10 , mod = 998244353 ;

int T , n , a[MAX_N] , cnt[MAX_N] , sum[MAX_N] , sumf[MAX_N] , jc[MAX_N] , f[MAX_N][MAX_N] ;

int qpow(int a , int t) {
    int s = 1 ;
    for (; t ; t >>= 1 , a = (ll)a * a % mod)
        if (t & 1) s = (ll)s * a % mod ;
    return s ;
}

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ; jc[0] = 1 ;
        for (int i = 0 ; i <= n ; ++i) cnt[i] = 0 ;
        for (int i = 1 ; i <= n ; ++i) jc[i] = (ll)jc[i - 1] * i % mod ;

        for (int i = 0 ; i < n ; ++i) {
            scanf("%d" , &a[i]) ;
            ++cnt[a[i]] ;
        }

        ///

        int ny = 1 ;
        for (int i = 1 ; i <= n ; ++i) ny = (ll)ny * qpow(jc[cnt[i]] , mod - 2) % mod ;
        for (int i = 1 ; i <= n ; ++i) cnt[i] += cnt[i - 1] ;
        for (int i = n ; i ; --i) cnt[i] = cnt[i - 1] ;

        int m = n >> 1 ;
        for (int i = 0 ; i < n ; ++i) f[0][i] = cnt[a[i]] ;
        for (int i = 1 ; i < m ; ++i) {
            sumf[0] = f[i - 1][0] ;
            for (int j = 1 ; j < n ; ++j) sumf[j] = (f[i - 1][j] + sumf[j - 1]) % mod ;
            for (int j = 0 ; j < n ; ++j) sum[j] = (ll)f[i - 1][j] * cnt[a[j]] % mod ;
            for (int j = 1 ; j < n ; ++j) (sum[j] += sum[j - 1]) %= mod ;

            int L = 0 , rd = ((i - 1) << 1) + 1 ;
            for (; cnt[L] < rd && L < n ; ++L) ;
            if (L < n) L = cnt[L] ;

            for (int j = 0 ; j < n ; ++j) {
                int R = cnt[a[j]] - 1 ;
                if (L > R) {f[i][j] = 0 ; continue ;}
                int p1 = L ? (sum[R] - sum[L - 1] + mod) % mod : sum[R] , p2 = L ? (sumf[R] - sumf[L - 1] + mod) % mod : sumf[R] ;
                p2 = (ll)p2 * rd % mod ; f[i][j] = (p1 + mod - p2) % mod ;
            }
        }

        int ans = 0 ;
        for (int i = 0 ; i < n ; ++i) (ans += f[m - 1][i]) %= mod ;
        ans = (ll)ans * ny % mod ;
        printf("%d\n" , ans) ;
    }

    return 0 ;
}