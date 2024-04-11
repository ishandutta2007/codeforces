#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n, m;
int a[Maxn], b[Maxn];
int lef[Maxn], rig[Maxn];
int eata[Maxn], eatb[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        ll cur = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &a[i], &b[i]);
            lef[i] = max(0, a[i] - m) - (b[i] - max(0, m - a[i]));
            rig[i] = (a[i] - max(0, m - b[i])) - max(0, b[i] - m);
            cur += lef[i];
        }
        for (int i = 0; i < n; i++) {
            ll tk = min(max(0ll, -cur / 2 * 2), ll(rig[i] - lef[i]));
            cur += tk;
            int x = lef[i] + tk;
            int y = a[i] + b[i] - m;
            int mya = (x + y) / 2;
            eata[i] = a[i] - mya;
            eatb[i] = m - eata[i];
        }
        printf("%I64d\n", abs(cur));
        for (int i = 0; i < n; i++)
            printf("%d %d\n", eata[i], eatb[i]);
    }
    return 0;
}