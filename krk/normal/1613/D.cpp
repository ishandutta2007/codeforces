#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 500005;
const int mod = 998244353;

int T;
int n;
int a[Maxn];
int good[Maxn], mnbad[Maxn], mxbad[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        fill(good, good + n + 4, 0);
        fill(mnbad, mnbad + n + 4, 0);
        fill(mxbad, mxbad + n + 4, 0);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            mnbad[a[i]] = 2 * mnbad[a[i]] % mod;
            mxbad[a[i]] = 2 * mxbad[a[i]] % mod;
            if (a[i] == 1) mxbad[a[i]] = (mxbad[a[i]] + 1) % mod;
            if (a[i] >= 2) {
                mxbad[a[i]] = (mxbad[a[i]] + good[a[i] - 2]) % mod;
                mxbad[a[i]] = (mxbad[a[i]] + mnbad[a[i] - 2]) % mod;
            }
            mnbad[a[i]] = (mnbad[a[i]] + mxbad[a[i] + 2]) % mod;
            good[a[i]] = 2 * good[a[i]] % mod;
            if (a[i] >= 1) good[a[i]] = (good[a[i]] + good[a[i] - 1]) % mod;
            if (a[i] == 0) good[a[i]] = (good[a[i]] + 1) % mod;
        }
        int res = 0;
        for (int i = 0; i <= n; i++)
            res = (ll(res) + ll(good[i]) + ll(mnbad[i]) + ll(mxbad[i])) % mod;
        printf("%d\n", res);
    }
    return 0;
}