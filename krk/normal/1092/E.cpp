#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1005;

int n, m;
vector <int> neigh[Maxn];
bool tk[Maxn];
int mx[Maxn][2];
int diam;
int best, bi;
vector <ii> cons;

void Update(int mx[], int val)
{
    if (val > mx[0]) mx[1] = mx[0], mx[0] = val;
    else if (val > mx[1]) mx[1] = val;
}

int Get(int mx[], int val)
{
    return mx[0] == val? mx[1]: mx[0];
}

void Traverse1(int v, int p = 0)
{
    tk[v] = true;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse1(u, v);
        Update(mx[v], mx[u][0] + 1);
    }
}

void Traverse2(int v, int p, int tp)
{
    diam = max(diam, mx[v][0] + max(mx[v][1], tp));
    int cand = max(mx[v][0], tp);
    if (cand < best) { best = cand; bi = v; }
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse2(u, v, max(Get(mx[v], mx[u][0] + 1), tp) + 1);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    vector <ii> seq;
    for (int i = 1; i <= n; i++) if (!tk[i]) {
        best = Maxn, bi = -1;
        Traverse1(i);
        Traverse2(i, 0, 0);
        seq.push_back(ii(best, bi));
    }
    sort(seq.begin(), seq.end());
    if (seq.size() >= 2)
        diam = max(diam, seq[int(seq.size()) - 2].first + seq[int(seq.size()) - 1].first + 1);
    if (seq.size() >= 3)
        diam = max(diam, seq[int(seq.size()) - 3].first + seq[int(seq.size()) - 2].first + 2);
    for (int i = 0; i + 1 < seq.size(); i++)
        cons.push_back(ii(seq[i].second, seq.back().second));
    printf("%d\n", diam);
    for (int i = 0; i < cons.size(); i++)
        printf("%d %d\n", cons[i].first, cons[i].second);
    return 0;
}