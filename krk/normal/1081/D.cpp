#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 100005;

int n, m, k;
iii E[Maxn];
int spec[Maxn], siz[Maxn], par[Maxn];
bool fin;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    spec[a] += spec[b];
    if (spec[a] == k) fin = true;
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        siz[i] = 1, par[i] = i;
    for (int i = 0; i < k; i++) {
        int x; scanf("%d", &x);
        spec[x]++;
    }
    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &E[i].second.first, &E[i].second.second, &E[i].first);
    sort(E, E + m);
    for (int i = 0; i < m; i++) {
        unionSet(E[i].second.first, E[i].second.second);
        if (fin) {
            for (int j = 0; j < k; j++)
                printf("%d%c", E[i].first, j + 1 < k? ' ': '\n');
            return 0;
        }
    }
    return 0;
}