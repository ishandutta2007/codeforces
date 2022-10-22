#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 200005;

int n, m;
int siz[Maxn], par[Maxn];
ll cur;
vector <ii> E[Maxn];
ll my[Maxn];

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (siz[a] < siz[b]) swap(a, b);
    cur -= ll(siz[a]) * (siz[a] - 1) / 2;
    cur -= ll(siz[b]) * (siz[b] - 1) / 2;
    siz[a] += siz[b]; par[b] = a;
    cur += ll(siz[a]) * (siz[a] - 1) / 2;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        siz[i] = 1, par[i] = i;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        E[c].push_back(ii(a, b));
    }
    for (int i = 0; i < Maxn; i++) {
        for (int j = 0; j < E[i].size(); j++)
            unionSet(E[i][j].first, E[i][j].second);
        my[i] = cur;
    }
    for (int i = 0; i < m; i++) {
        int a; scanf("%d", &a);
        printf("%I64d%c", my[a], i + 1 < m? ' ': '\n');
    }
    return 0;
}