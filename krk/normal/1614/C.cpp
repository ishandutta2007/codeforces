#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int mod = 1000000007;

int pw2[Maxn];
int T;
int n, m;
int l, r, x;

int main()
{
    pw2[0] = 1;
    for (int i = 1; i < Maxn; i++)
        pw2[i] = 2ll * pw2[i - 1] % mod;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        int all = 0;
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &l, &r, &x);
            all |= x;
        }
        int res = ll(all) * pw2[n - 1] % mod;
        printf("%d\n", res);
    }
    return 0;
}