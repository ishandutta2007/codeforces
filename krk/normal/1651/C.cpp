#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000000ll;
const int Maxn = 200005;
const int Maxd = 4;

typedef pair <int, int> ii;

int T;
int n;
int a[Maxn], b[Maxn];
ii seq[Maxd];
bool tk[Maxd];
ll res;

ll getBestArray(int a[], ll val)
{
    int ind = lower_bound(a, a + n, val) - a;
    ll best = Inf;
    if (ind < n) best = min(best, a[ind] - val);
    if (ind > 0) {
        ind--;
        best = min(best, val - a[ind]);
    }
    return best;
}

ll getBest(const ii &p)
{
    if (p.first == 0) return getBestArray(b, p.second);
    return getBestArray(a, p.second);
}

void Gen(int lvl, ll cur)
{
    if (lvl >= Maxd) {
        res = min(res, cur);
        return;
    }
    if (tk[lvl]) {
        Gen(lvl + 1, cur);
        return;
    }
    Gen(lvl + 1, cur + getBest(seq[lvl]));
    for (int i = lvl + 1; i < Maxd; i++) if (!tk[i] && seq[lvl].first != seq[i].first) {
        ll add = abs(seq[lvl].second - seq[i].second);
        tk[i] = true;
        Gen(lvl + 1, cur + add);
        tk[i] = false;
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &b[i]);
        seq[0] = ii(0, a[0]);
        seq[1] = ii(0, a[n - 1]);
        seq[2] = ii(1, b[0]);
        seq[3] = ii(1, b[n - 1]);
        sort(a, a + n);
        sort(b, b + n);
        res = Inf;
        Gen(0, 0);
        printf("%I64d\n", res);
    }
    return 0;
}