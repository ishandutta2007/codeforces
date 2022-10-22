#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Maxm = 20;

int T;
int n;
ll a[Maxn];
ll G[Maxn][Maxm];

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%I64d", &a[i]);
        for (int i = 0; i + 1 < n; i++)
            G[i][0] = abs(a[i] - a[i + 1]);
        for (int j = 1; j < Maxm; j++)
            for (int i = 0; i + (1 << j) <= n - 1; i++)
                G[i][j] = gcd(G[i][j - 1], G[i + (1 << j - 1)][j - 1]);
        int res = 1;
        for (int i = 0; i < n; i++) {
            ll g = 0;
            int cur = i;
            for (int j = Maxm - 1; j >= 0; j--) if (cur + (1 << j) <= n - 1) {
                ll cand = gcd(g, G[cur][j]);
                if (cand > 1) {
                    g = cand;
                    cur += 1 << j;
                }
            }
            res = max(res, cur - i + 1);
        }
        printf("%d\n", res);
    }
    return 0;
}