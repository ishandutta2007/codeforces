#include<bits/stdc++.h>
using namespace std;
const int nax = 3000 + 10;
using ll = int64_t;
int n;
int a[nax];
int ct_f[nax];
int ct_s[nax];

void solve() {
    scanf("%d", &n);

    for (int i = 1 ; i <= n; ++ i)
        scanf("%d", a + i);

    memset(ct_f, 0, sizeof(ct_f));
    memset(ct_s, 0, sizeof(ct_s));

    ll ans = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        for (int j = i + 2 ; j <= n; ++ j) {
            ct_s[a[j]] += 1 ;
        }
        ll cur = 0;
        for (int j = i + 2 ; j <= n ; ++ j) {
            ct_s[a[j]] -= 1;
            cur -= ct_f[a[j]];
            ct_f[a[j - 1]] += 1;
            cur += ct_s[a[j - 1]];
            if (a[i] == a[j]) {
           ///     printf("i j %d %d %lld\n", i, j, cur);

                ans += cur;
            }
        }

        for (int j = 1 ; j <= n ; ++ j)
            ct_s[j] = ct_f[j] = 0;
    }
    printf("%lld\n", ans);
}

int main() {
    int T;
    for (scanf("%d", &T) ; T -- ;) {
        solve();
    }
}