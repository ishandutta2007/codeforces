#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1000005;
const int Maxm = 20;

int n, q;
vector <int> neigh[Maxn];
int res[Maxn];
int gmn = Maxn;
vector <int> has[Maxn];

void Propagate(int v, int p, int val)
{
    val = min(val, v);
    res[v] = val;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Propagate(u, v, val);
    }
}

void Update(int v, int from)
{
    if (has[v].empty()) has[v].push_back(from);
    else if (has[v].size() == 1)
            if (has[v][0] == from) return;
            else { has[v].push_back(from); gmn = min(gmn, v); }
        else return;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == from) continue;
        Update(u, v);
    }
}

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    int lst = 0, any = -1;
    while (q--) {
        int t, z; scanf("%d %d", &t, &z);
        int x = (z + lst) % n + 1;
        if (t == 1) {
            Update(x, x);
            if (any == -1) {
                any = x;
                Propagate(any, 0, Maxn);
            }
        } else {
            lst = min(gmn, res[x]);
            printf("%d\n", lst);
        }
    }
    return 0;
}