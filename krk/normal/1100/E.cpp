#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n, m;
int u[Maxn], v[Maxn], c[Maxn];
vector <ii> neigh[Maxn];
int tk[Maxn];
int cur, seq[Maxn];
vector <int> res;

bool Cycle(int v, int x)
{
    if (tk[v] == 2) return false;
    if (tk[v] == 1) return true;
    tk[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        ii u = neigh[v][i];
        if (u.second > x)
            if (Cycle(u.first, x)) return true;
    }
    seq[v] = cur++;
    tk[v] = 2;
    return false;
}

bool Check(int x)
{
    fill(tk, tk + Maxn, 0);
    cur = 0;
    for (int i = 1; i <= n; i++) if (!tk[i])
        if (Cycle(i, x)) return false;
    return true;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u[i], &v[i], &c[i]);
        neigh[u[i]].push_back(ii(v[i], c[i]));
    }
    int lef = 0, rig = 1000000007;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        if (Check(mid)) rig = mid - 1;
        else lef = mid + 1;
    }
    rig++;
    Check(rig);
    for (int i = 0; i < m; i++)
        if (seq[u[i]] < seq[v[i]]) res.push_back(i + 1);
    printf("%d %d\n", rig, int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}