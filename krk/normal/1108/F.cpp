#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 200005;
const int Maxm = 21;

int n, m;
iii E[Maxn];
bool usd[Maxn];
int par[Maxn], siz[Maxn];
vector <ii> neigh[Maxn];
int L[Maxn], P[Maxn][Maxm], M[Maxn][Maxm];
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
        ii u = neigh[v][i];
        if (P[v][0] == u.first) continue;
        L[u.first] = L[v] + 1;
        P[u.first][0] = v; M[u.first][0] = u.second;
        Traverse(u.first);
    }
}

int getMax(int a, int b)
{
    if (L[a] < L[b]) swap(a, b);
    int res = 0;
    for (int i = Maxm - 1; i >= 0; i--) if (L[a] - (1 << i) >= L[b]) {
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

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        siz[i] = 1;
    }
    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &E[i].second.first, &E[i].second.second, &E[i].first);
    sort(E, E + m);
    for (int i = 0; i < m; i++) {
        int a = E[i].second.first, b = E[i].second.second, c = E[i].first;
        usd[i] = unionSet(a, b);
        if (usd[i]) {
            neigh[a].push_back(ii(b, c));
            neigh[b].push_back(ii(a, c));
        }
    }
    Traverse(1);
    for (int j = 1; j < Maxm; j++)
        for (int i = 1; i <= n; i++) {
            P[i][j] = P[P[i][j - 1]][j - 1];
            M[i][j] = max(M[i][j - 1], M[P[i][j - 1]][j - 1]);
        }
    for (int i = 0; i < m; i++) if (!usd[i])
        if (getMax(E[i].second.first, E[i].second.second) == E[i].first)
            ans++;
    printf("%d\n", ans);
    return 0;
}