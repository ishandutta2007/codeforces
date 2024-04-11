#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n, m;
set <int> neigh[Maxn];
vector <int> my[Maxn];
int par[Maxn];
vector <int> seq, nseq;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return;
    if (my[a].size() < my[b].size()) swap(a, b);
    for (int i = 0; i < my[b].size(); i++)
        my[a].push_back(my[b][i]);
    my[b].clear(); par[b] = a;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        my[i].push_back(i);
        par[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].insert(b);
        neigh[b].insert(a);
    }
    for (int i = 1; i <= n; i++) {
        nseq.clear();
        for (int j = 0; j < seq.size(); j++) {
            int v = getPar(seq[j]);
            bool ok = false;
            for (int k = 0; k < my[v].size() && !ok; k++) {
                int u = my[v][k];
                if (neigh[i].find(u) == neigh[i].end()) ok = true;
            }
            if (ok) unionSet(i, v);
            else nseq.push_back(v);
        }
        nseq.push_back(getPar(i));
        seq = nseq;
    }
    printf("%d\n", int(seq.size()) - 1);
    return 0;
}