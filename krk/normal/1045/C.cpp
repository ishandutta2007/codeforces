#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxm = 500005;
const int Maxk = 21;

int n, m, q;
set <ii> S;
vector <int> tmp[Maxn];
bool tk[Maxn];
int L[Maxn], P[Maxn][Maxk];

void Traverse(int v)
{
    tk[v] = true;
    int mn = Maxn, wth;
    for (int i = 0; i < tmp[v].size(); i++) {
        int u = tmp[v][i];
        if (tk[u])
            if (L[u] < mn) { mn = L[u]; wth = u; }
    }
    L[v] = L[wth] + 1; P[v][0] = wth;
    for (int j = 1; j < Maxk; j++)
        P[v][j] = P[P[v][j - 1]][j - 1];
    for (int i = 0; i < tmp[v].size(); i++) {
        int u = tmp[v][i];
        if (!tk[u]) Traverse(u);
    }
}

bool checkEdge(int a, int b)
{
    if (a > b) swap(a, b);
    return S.find(ii(a, b)) != S.end();
}

int Solve(int a, int b)
{
    if (L[a] < L[b]) swap(a, b);
    int res = 0;
    for (int i = Maxk - 1; i >= 0; i--)
        if (L[a] - (1 << i) >= L[b]) {
            a = P[a][i];
            res += 1 << i;
        }
    if (a == b) return res;
    if (checkEdge(a, b)) return res + 1;
    for (int i = Maxk - 1; i >= 0; i--)
        if (P[a][i] != P[b][i]) {
            res += 1 << i + 1;
            a = P[a][i]; b = P[b][i];
        }
    if (checkEdge(a, b)) return res + 1;
    return res + 2;
}

int main()
{
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        S.insert(ii(a, b));
        tmp[a].push_back(b);
        tmp[b].push_back(a);
    }
    tk[1] = true;
    for (int i = 0; i < tmp[1].size(); i++) {
        int u = tmp[1][i];
        if (!tk[u]) Traverse(u);
    }
    while (q--) {
        int a, b; scanf("%d %d", &a, &b);
        printf("%d\n", Solve(a, b));
    }
    return 0;
}