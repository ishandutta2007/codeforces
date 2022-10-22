#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n, m;
vector <int> neigh[Maxn];
int cur, lef[Maxn], rig[Maxn];
int P[Maxn];

void Traverse(int v, int p)
{
    lef[v] = ++cur;
    P[v] = p;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v);
    }
    rig[v] = cur;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse(1, 1);
    while (m--) {
        int k; scanf("%d", &k);
        vector <ii> seq;
        for (int i = 0; i < k; i++) {
            int v; scanf("%d", &v);
            v = P[v];
            seq.push_back(ii(lef[v], rig[v]));
        }
        sort(seq.begin(), seq.end());
        bool ok = true;
        for (int i = 0; i + 1 < seq.size() && ok; i++)
            ok = seq[i].first <= seq[i + 1].first && seq[i + 1].second <= seq[i].second;
        printf("%s\n", ok? "YES": "NO");
    }
    return 0;
}