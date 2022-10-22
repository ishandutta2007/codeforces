#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n, m, D;
vector <int> neigh[Maxn];
int par[Maxn], siz[Maxn];
bool mark[Maxn];
int comp;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

bool unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return false;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    if (mark[a] && mark[b]) comp--;
    mark[a] |= mark[b];
    return true;
}

int main()
{
    scanf("%d %d %d", &n, &m, &D);
    for (int i = 1; i <= n; i++)
        par[i] = i, siz[i] = 1;
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        if (a > b) swap(a, b);
        if (a == 1) {
            neigh[a].push_back(b);
            mark[b] = true;
        } else {
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
    }
    comp = neigh[1].size();
    if (comp < D) { printf("NO\n"); return 0; }
    vector <ii> seq;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j < neigh[i].size(); j++) {
            int u = neigh[i][j];
            int a = getPar(i), b = getPar(u);
            if (a != b && (!mark[a] || !mark[b] || comp > D)) {
                unionSet(i, u);
                seq.push_back(ii(i, u));
            }
        }
    if (comp > D) { printf("NO\n"); return 0; }
    for (int j = 0; j < neigh[1].size(); j++) {
        int u = neigh[1][j];
        if (unionSet(1, u)) seq.push_back(ii(1, u));
    }
    printf("YES\n");
    for (int i = 0; i < seq.size(); i++)
        printf("%d %d\n", seq[i].first, seq[i].second);
    return 0;
}