#include<bits/stdc++.h>
using namespace std;
int const nax = 102;

using ll = long long ;
ll dp[2][nax][nax][nax];
ll ans[nax][nax];
int n, a[nax];
char s[nax];

ll const inf = 1e17;

ll rec_ans (int l, int r);

ll rec (int dig, int l, int r, int cnt) {

    if (cnt == 0) return rec_ans(l, r);

    ll &res = dp[dig][l][r][cnt];
    if (res != -1) return res;


    res = -inf;

    for (int x = l; x <= r ; ++ x) {
        if (s[x] - '0' == dig) {
            res = max(res, rec_ans(l, x - 1) + rec(dig, x + 1, r, cnt - 1));
        }
    }

    return res;
}

ll rec_ans (int l, int r) {

    if (l > r) return 0LL;
    if (ans[l][r] != -1) return ans[l][r];

    ll &res = ans[l][r];
    if (res != -1) return res;

    for (int cnt = 1 ; cnt <= r - l + 1 ; ++ cnt) {
        res = max(res, rec(0, l, r, cnt) + a[cnt]);
        res = max(res, rec(1, l, r, cnt) + a[cnt]);
    }

    return res;
}

int main () {

    scanf("%d", &n);
    scanf("%s", s + 1);

    for (int i = 1 ; i <= n ; ++ i)
        scanf("%d", a + i);

    memset(dp, -1, sizeof(dp));
    memset(ans, -1, sizeof(ans));

    fprintf(stderr, "%.4f\n", clock() / (double) CLOCKS_PER_SEC);

    printf("%lld\n", rec_ans(1, n));

}