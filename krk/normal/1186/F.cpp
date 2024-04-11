#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1000005;

int n, m;
set <int> neigh[Maxn];
vector <ii> res;
vector <int> S, pth;

void Remove(int a, int b)
{
    neigh[a].erase(b);
    neigh[b].erase(a);
}

void Presolve(int v)
{
    bool tk = true;
    while (true) {
        int u = *neigh[v].begin();
        if (neigh[u].size() % 2) {
            res.push_back(ii(v, u));
            Remove(v, u);
            return;
        }
        if (tk) res.push_back(ii(v, u));
        Remove(v, u);
        tk = !tk;
        v = u;
    }
}

void Solve(int v)
{
    S.clear(); pth.clear();
    while (!neigh[v].empty() || !S.empty())
        if (neigh[v].empty()) {
            pth.push_back(v);
            v = S.back(); S.pop_back();
        } else {
            S.push_back(v);
            int u = *neigh[v].begin();
            Remove(v, u);
            v = u;
        }
    if (!pth.empty()) pth.push_back(pth[0]);
    for (int i = 0; i + 1 < pth.size(); i += 2)
        res.push_back(ii(pth[i], pth[i + 1]));
}

int main()
{
    scanf("%d %d", &n, &m);
    while (m--) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].insert(b);
        neigh[b].insert(a);
    }
    for (int i = 1; i <= n; i++) if (neigh[i].size() % 2)
        Presolve(i);
    for (int i = 1; i <= n; i++) if (neigh[i].size() > 0)
        Solve(i);
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d %d\n", res[i].first, res[i].second);
    return 0;
}