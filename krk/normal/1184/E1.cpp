#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 1000005;

int n, m;
int par[Maxn], siz[Maxn];
int A[Maxn], B[Maxn], C[Maxn];
vector <iii> E;
vector <ii> neigh[Maxn];

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

bool unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return false;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    return true;
}

int getMax(int a, int p, int b, int cur)
{
    if (a == b) return cur;
    else {
        for (int i = 0; i < neigh[a].size(); i++) {
            int u = neigh[a][i].first;
            if (u == p) continue;
            int cost = neigh[a][i].second;
            int got = getMax(u, a, b, max(cur, cost));
            if (got != -1) return got;
        }
        return -1;
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        par[i] = i, siz[i] = 1;
    for (int i = 0; i < m; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        A[i] = a; B[i] = b; C[i] = c;
        if (i != 0)
            E.push_back(iii(c, ii(a, b)));
    }
    sort(E.begin(), E.end());
    for (int i = 0; i < E.size(); i++) {
        int a = E[i].second.first, b = E[i].second.second;
        if (unionSet(a, b)) {
            neigh[a].push_back(ii(b, E[i].first));
            neigh[b].push_back(ii(a, E[i].first));
        }
    }
    int res = getMax(A[0], 0, B[0], 0);
    printf("%d\n", res == -1? 1000000000: res);
    return 0;
}