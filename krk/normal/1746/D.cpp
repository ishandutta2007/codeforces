#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n, k;
vector <int> neigh[Maxn];
int s[Maxn];
map <int, ll> M[Maxn];

ll Solve(int v, int k)
{
    auto it = M[v].find(k);
    if (it != M[v].end()) return it->second;
    ll res = ll(k) * s[v];
    if (neigh[v].empty()) {
        M[v].insert(make_pair(k, res));
        return res;
    }
    vector <ll> seq;
    int nd = k / int(neigh[v].size());
    int tk = k % int(neigh[v].size());
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        ll w1 = Solve(u, nd);
        res += w1;
        if (tk) {
            ll w2 = Solve(u, nd + 1);
            seq.push_back(w2 - w1);
        }
    }
    if (tk) {
        sort(seq.rbegin(), seq.rend());
        for (int i = 0; i < tk; i++)
            res += seq[i];
    }
    M[v].insert(make_pair(k, res));
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++) {
            neigh[i].clear();
            M[i].clear();
        }
        for (int i = 2; i <= n; i++) {
            int p; scanf("%d", &p);
            neigh[p].push_back(i);
        }
        for (int i = 1; i <= n; i++)
            scanf("%d", &s[i]);
        printf("%I64d\n", Solve(1, k));
    }
    return 0;
}