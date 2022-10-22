#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 2000005;

int t;
int n;
int a[Maxn];
vector <int> neigh[Maxn];
int tk[Maxn], par[Maxn];
vector <int> res;

void Add(int v) { if (v <= n) res.push_back(v); }

bool getCycle(int v, int p = 0)
{
    if (tk[v] == 2) return false;
    if (tk[v] == 1) {
        Add(p);
        do {
            p = par[p];
            Add(p);
        } while (p != v);
        return true;
    }
    tk[v] = 1;
    par[v] = p;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        if (getCycle(u, v)) return true;
    }
    tk[v] = 2;
    return false;
}

void Solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; i++) {
        neigh[i].clear();
        tk[i] = par[i] = 0;
    }
    res.clear();
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        a[i] = i - a[i];
        if (i == a[i]) {
            printf("1\n");
            printf("%d\n", i);
            return;
        }
        neigh[i].push_back(n + i);
        neigh[n + i].push_back(i);
        neigh[i].push_back(n + a[i]);
        neigh[n + a[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) if (!tk[i])
        if (getCycle(i)) {
            sort(res.begin(), res.end());
            printf("%d\n", int(res.size()));
            for (int i = 0; i < res.size(); i++)
                printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
            return;
        }
    assert(false);
}

int main()
{
    scanf("%d", &t);
    while (t--)
        Solve();
    return 0;
}