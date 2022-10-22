#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
vector <int> neigh[Maxn];
ll my[Maxn];
int siz[Maxn];
ll res;

void Traverse1(int v, int p)
{
    siz[v]++;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse1(u, v);
        my[v] += my[u];
        siz[v] += siz[u];
    }
    my[v] += siz[v];
}

void Traverse2(int v, int p, ll tp)
{
    res = max(res, my[v] + ll(n - siz[v]) + tp);
    ll sum = tp;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        sum += my[u];
    }
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse2(u, v, sum - my[u] + ll(n - siz[u]));
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse1(1, 0);
    Traverse2(1, 0, 0ll);
    cout << res << endl;
    return 0;
}