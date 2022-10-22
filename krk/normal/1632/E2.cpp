#include <bits/stdc++.h>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 300005;

int T;
int n;
vector <int> neigh[Maxn];
int dist[Maxn][2], mx[Maxn];
vector <int> add[Maxn], rem[Maxn];
multiset <int> S;
int mxlvl;

void Insert(int dist[], int val)
{
    if (val > dist[0]) dist[1] = dist[0], dist[0] = val;
    else if (val > dist[1]) dist[1] = val;
}

int getOther(int dist[], int val)
{
    return dist[0] == val? dist[1]: dist[0];
}

void Traverse(int v, int p)
{
    dist[v][0] = dist[v][1] = mx[v] = 0;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v);
        Insert(dist[v], dist[u][0] + 1);
        mx[v] = max(mx[v], mx[u]);
    }
    mx[v] = max(mx[v], dist[v][0] + dist[v][1]);
}

void Solve(int v, int p, int lvl, int tp)
{
    int a = (mx[v] + 1) / 2;
    int d = max(tp, a + 1);
    add[1].push_back(d);
    rem[d - a].push_back(d);
    mxlvl = max(mxlvl, lvl);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Solve(u, v, lvl + 1, max(tp, lvl + getOther(dist[v], dist[u][0] + 1)));
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            neigh[i].clear();
            add[i].clear();
            rem[i].clear();
        }
        S.clear();
        for (int i = 0; i < n - 1; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        Traverse(1, 0);
        mxlvl = 0;
        Solve(1, 0, 0, 0);
        add[1].push_back(mxlvl);
        rem[n].push_back(mxlvl);
        int cur = Inf;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < add[i].size(); j++)
                S.insert(add[i][j]);
            cur = min(cur + 1, *S.begin());
            for (int j = 0; j < rem[i].size(); j++) {
                auto it = S.find(rem[i][j]);
                S.erase(it);
            }
            printf("%d%c", cur, i + 1 <= n? ' ': '\n');
        }
    }
    return 0;
}