#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n, q;
vector <int> neigh[Maxn];
int cur, lef[Maxn], rig[Maxn];
vector <int> seq;

void Traverse(int v)
{
    sort(neigh[v].begin(), neigh[v].end());
    lef[v] = cur++;
    seq.push_back(v);
    for (int i = 0; i < neigh[v].size(); i++)
        Traverse(neigh[v][i]);
    rig[v] = cur;
}

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 2; i <= n; i++) {
        int p; scanf("%d", &p);
        neigh[p].push_back(i);
    }
    Traverse(1);
    while (q--) {
        int u, ind; scanf("%d %d", &u, &ind);
        int got = lef[u] + ind - 1;
        printf("%d\n", got < rig[u]? seq[got]: -1);
    }
    return 0;
}