#include <bits/stdc++.h>
using namespace std;

const int Maxb = 31;
const int Maxn = 100005;

int n;
int p[Maxb][Maxn];
int cur[Maxn];
int a[Maxn];
bool was[Maxn];
int nw;
set <int> S;
int res[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[0][i]);
        if (was[p[0][i]]) nw++;
        else was[p[0][i]] = true;
    }
    for (int b = 1; b < Maxb; b++)
        for (int i = 1; i <= n; i++)
            p[b][i] = p[b - 1][p[b - 1][i]];
    for (int i = 1; i <= n; i++)
        cur[i] = i;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        mx = max(mx, a[i]);
    }
    int k = (mx - n) / nw;
    for (int b = Maxb - 1; b >= 0; b--) if (1 << b <= k) {
        for (int i = 1; i <= n; i++)
            cur[i] = p[b][cur[i]];
        k -= 1 << b;
    }
    for (int i = 1; i <= n; i++)
        S.insert(i);
    fill(was, was + n + 1, false);
    for (int i = 1; i <= n; i++) {
        int nd = a[cur[i]];
        if (!was[nd]) {
            res[i] = nd;
            was[nd] = true;
            S.erase(nd);
        }
    }
    for (int i = 1; i <= n; i++) if (!res[i]) {
        int nd = a[cur[i]];
        auto it = S.lower_bound(nd);
        res[i] = *it;
        S.erase(it);
    }
    for (int i = 1; i <= n; i++)
        printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    return 0;
}