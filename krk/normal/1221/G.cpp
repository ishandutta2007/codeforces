#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 42;

int n, m;
ll neighs[Maxn];
int tk[Maxn];
bool bic = true;
vector <vector <int> > comps;
vector <int> seq;

void Traverse(int v, int c)
{
    if (tk[v]) {
        if (tk[v] != c) bic = false;
        return;
    }
    tk[v] = c;
    seq.push_back(v);
    for (int i = 1; i <= n; i++) if (neighs[v] & 1ll << ll(i))
        Traverse(i, -c);
}

ll Gen(const vector <int> &seq, int lvl, ll mask)
{
    if (lvl >= seq.size()) return 1;
    else {
        ll res = Gen(seq, lvl + 1, mask);
        if (!(mask & 1ll << ll(seq[lvl])))
            res += Gen(seq, lvl + 1, mask | neighs[seq[lvl]]);
        return res;
    }
}

ll Solve()
{
    ll res = 1;
    for (int i = 0; i < comps.size(); i++)
        res *= Gen(comps[i], 0, 0);
    return res;
}

int Empty()
{
    int res = 0;
    for (int i = 0; i < comps.size(); i++)
        if (comps[i].size() == 1) res++;
    return res;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y; scanf("%d %d", &x, &y);
        neighs[x] |= 1ll << ll(y);
        neighs[y] |= 1ll << ll(x);
    }
    for (int i = 1; i <= n; i++) if (!tk[i]) {
        seq.clear();
        Traverse(i, 1);
        comps.push_back(seq);
    }
    ll res = 1ll << ll(n);
    res -= 2ll * ll(Solve());
    res -= 1ll << ll(comps.size());
    if (bic) res += 1ll << ll(comps.size());
    res += 2 * (1ll << ll(Empty()));
    if (m == 0) res -= 1ll << ll(n);
    printf("%I64d\n", res);
    return 0;
}