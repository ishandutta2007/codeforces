#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;

int T;
int n;
int p[Maxn];
vector <int> neigh[Maxn];
int par[Maxn];
set <int> S[Maxn];
vector <int> D[Maxn];

void Merge(vector <int> &A, set <int> &S, const vector <int> &B)
{
    S.clear();
    for (int i = 1; i <= A.size(); i++) {
        A[int(A.size()) - i] ^= B[int(B.size()) - i];
        S.insert(A[int(A.size()) - i]);
    }
}

int Get(set <int> &S, int from)
{
    auto it = S.lower_bound(from);
    while (it != S.end() && from == *it) { from++; it++; }
    return from;
}

void Solve(int v)
{
    if (!neigh[v].empty()) {
        int u = neigh[v][0];
        Solve(u);
        par[v] = par[u];
        for (int i = 1; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            Solve(u);
            if (D[par[v]].size() > D[par[u]].size())
                swap(par[v], par[u]);
            Merge(D[par[v]], S[par[v]], D[par[u]]);
            D[par[u]].clear(); S[par[u]].clear();
        }
    }
    int from = neigh[v].size() == 1? D[par[v]].back(): 0;
    int my = Get(S[par[v]], from);
    D[par[v]].push_back(my); S[par[v]].insert(my);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            neigh[i].clear();
            par[i] = i;
            D[i].clear();
            D[i].push_back(0);
            S[i].clear();
            S[i].insert(0);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &p[i]);
            if (p[i]) neigh[p[i]].push_back(i);
        }
        int res = 0;
        for (int i = 1; i <= n; i++)
            if (p[i] == 0) {
                Solve(i);
                res ^= D[par[i]].back();
            }
        printf("%s\n", res? "YES": "NO");
    }
    return 0;
}