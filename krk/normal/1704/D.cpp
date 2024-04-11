#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 4000000000000000000ll;
const int Maxn = 300005;

int T;
int n, m;

ll Read()
{
    ll res = 0;
    for (int i = 0; i < m; i++) {
        ll a; scanf("%I64d", &a);
        res += a * i;
    }
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        ll mn = Inf, mx = -Inf;
        int wth = -1;
        for (int i = 1; i <= n; i++) {
            ll got = Read();
            mn = min(mn, got);
            if (got > mx) {
                mx = got;
                wth = i;
            }
        }
        printf("%d %I64d\n", wth, mx - mn);
    }
    return 0;
}