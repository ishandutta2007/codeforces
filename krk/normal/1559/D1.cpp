#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1005;

int n, m1, m2;
int par[2][Maxn], siz[2][Maxn];

int getPar(int t, int x) { return par[t][x] == x? x: par[t][x] = getPar(t, par[t][x]); }

bool unionSet(int t, int a, int b)
{
    a = getPar(t, a), b = getPar(t, b);
    if (a == b) return false;
    if (siz[t][a] < siz[t][b]) swap(a, b);
    siz[t][a] += siz[t][b];
    par[t][b] = a;
    return true;
}

int main()
{
    scanf("%d %d %d", &n, &m1, &m2);
    for (int i = 1; i <= n; i++) {
        par[0][i] = par[1][i] = i;
        siz[0][i] = siz[1][i] = 1;
    }
    for (int i = 0; i < m1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        unionSet(0, a, b);
    }
    for (int i = 0; i < m2; i++) {
        int a, b; scanf("%d %d", &a, &b);
        unionSet(1, a, b);
    }
    vector <ii> res;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (getPar(0, i) != getPar(0, j) && getPar(1, i) != getPar(1, j)) {
                unionSet(0, i, j);
                unionSet(1, i, j);
                res.push_back(ii(i, j));
            }
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d %d\n", res[i].first, res[i].second);
    return 0;
}