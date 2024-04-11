#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

int n, m;
int par[Maxn], siz[Maxn];
vector <int> neigh[Maxn];
int P[Maxn], L[Maxn];
bool cur[Maxn];
vector <vector <int> > res;
int ans;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

bool unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return false;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    return true;
}

void Traverse(int v)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (P[v] == u) continue;
        P[u] = v; L[u] = L[v] + 1;
        Traverse(u);
    }
}

void Add(int a, int b)
{
    vector <int> A, B;
    while (a != b)
        if (L[a] > L[b]) {
            A.push_back(a);
            cur[a] ^= true;
            a = P[a];
        } else {
            B.push_back(b);
            cur[b] ^= true;
            b = P[b];
        }
    A.push_back(a);
    for (int i = int(B.size()) - 1; i >= 0; i--)
        A.push_back(B[i]);
    res.push_back(A);
}

bool Solve(int v)
{
    int all = 0;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (P[v] == u) continue;
        bool g = Solve(u);
        if (g && !cur[u]) ans++;
        if (cur[u]) all++;
    }
    ans += all / 2;
    return all % 2;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        par[i] = i; siz[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        if (unionSet(a, b)) {
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
    }
    Traverse(1);
    int q; scanf("%d", &q);
    while (q--) {
        int a, b; scanf("%d %d", &a, &b);
        Add(a, b);
    }
    if (Solve(1)) ans++;
    if (ans > 0) {
        printf("NO\n");
        printf("%d\n", ans);
    } else {
        printf("YES\n");
        for (int i = 0; i < res.size(); i++) {
            printf("%d\n", int(res[i].size()));
            for (int j = 0; j < res[i].size(); j++)
                printf("%d%c", res[i][j], j + 1 < res[i].size()? ' ': '\n');
        }
    }
    return 0;
}