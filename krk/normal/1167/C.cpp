#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;

int n, m;
vector <int> my[Maxn];
set <int> group[Maxn];
int par[Maxn], siz[Maxn];

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    for (set <int>::iterator it = group[b].begin(); it != group[b].end(); it++)
        group[a].insert(*it);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int k; scanf("%d", &k);
        par[i] = i, siz[i] = k;
        while (k--) {
            int a; scanf("%d", &a);
            my[a].push_back(i);
            group[i].insert(a);
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j + 1 < my[i].size(); j++)
            unionSet(my[i][j], my[i][j + 1]);
    for (int i = 1; i <= n; i++) {
        int res = my[i].empty()? 1: group[getPar(my[i][0])].size();
        printf("%d%c", res, i + 1 <= n? ' ': '\n');
    }
    return 0;
}