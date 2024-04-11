#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 100005;
const int Maxm = 20;
const int Maxe = 1000000;
const int lim = 1000000000;

int n, m;
int par[Maxn], siz[Maxn];
int A[Maxe], B[Maxe], C[Maxe];
bool tk[Maxe];
vector <iii> E;
vector <ii> neigh[Maxn];
int L[Maxn], P[Maxn][Maxm], M[Maxn][Maxm];
int G[Maxn][Maxm];

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

bool unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return false;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    return true;
}

bool Less(const iii &a, const iii &b)
{
    return C[a.first] < C[b.first];
}

void Traverse(int v)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        ii u = neigh[v][i];
        if (P[v][0] == u.first) continue;
        L[u.first] = L[v] + 1;
        P[u.first][0] = v;
        M[u.first][0] = u.second;
        Traverse(u.first);
    }
}

int getMax(int a, int b)
{
    if (L[a] < L[b]) swap(a, b);
    int res = 0;
    for (int i = Maxm - 1; i >= 0; i--)
        if (L[a] - (1 << i) >= L[b]) {
            res = max(res, M[a][i]);
            a = P[a][i];
        }
    if (a == b) return res;
    for (int i = Maxm - 1; i >= 0; i--)
        if (P[a][i] != P[b][i]) {
            res = max(res, max(M[a][i], M[b][i]));
            a = P[a][i]; b = P[b][i];
        }
    res = max(res, max(M[a][0], M[b][0]));
    return res;
}

void updateMax(int a, int b, int val)
{
    if (L[a] < L[b]) swap(a, b);
    for (int i = Maxm - 1; i >= 0; i--)
        if (L[a] - (1 << i) >= L[b]) {
            G[a][i] = min(G[a][i], val);
            a = P[a][i];
        }
    if (a == b) return;
    for (int i = Maxm - 1; i >= 0; i--)
        if (P[a][i] != P[b][i]) {
            G[a][i] = min(G[a][i], val);
            G[b][i] = min(G[b][i], val);
            a = P[a][i]; b = P[b][i];
        }
    G[a][0] = min(G[a][0], val);
    G[b][0] = min(G[b][0], val);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        par[i] = i, siz[i] = 1;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &A[i], &B[i], &C[i]);
        E.push_back(iii(i, ii(A[i], B[i])));
    }
    sort(E.begin(), E.end(), Less);
    for (int i = 0; i < E.size(); i++) {
        int a = E[i].second.first, b = E[i].second.second;
        if (unionSet(a, b)) {
            neigh[a].push_back(ii(b, C[E[i].first]));
            neigh[b].push_back(ii(a, C[E[i].first]));
            tk[E[i].first] = true;
        }
    }
    Traverse(1);
    for (int j = 1; j < Maxm; j++)
        for (int i = 1; i <= n; i++) {
            P[i][j] = P[P[i][j - 1]][j - 1];
            M[i][j] = max(M[i][j - 1], M[P[i][j - 1]][j - 1]);
        }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < Maxm; j++)
            G[i][j] = lim;
    for (int i = 0; i < m; i++)
        if (!tk[i]) updateMax(A[i], B[i], C[i]);
    for (int j = Maxm - 1; j > 0; j--)
        for (int i = 1; i <= n; i++) {
            G[i][j - 1] = min(G[i][j - 1], G[i][j]);
            G[P[i][j - 1]][j - 1] = min(G[P[i][j - 1]][j - 1], G[i][j]);
        }
    for (int i = 0; i < m; i++)
        if (!tk[i]) printf("%d\n", getMax(A[i], B[i]));
        else if (P[A[i]][0] == B[i]) printf("%d\n", G[A[i]][0]);
             else printf("%d\n", G[B[i]][0]);
    return 0;
}