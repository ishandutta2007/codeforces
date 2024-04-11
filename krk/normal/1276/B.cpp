#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n, m, a, b;
vector <int> neigh[Maxn];
bool tk[Maxn], tka[Maxn], tkb[Maxn];

int getSize(int v, bool tk[], int forb1, int forb2)
{
    if (v == forb1 || v == forb2) return 0;
    if (tk[v]) return 0;
    tk[v] = true;
    int res = 1;
    for (int i = 0; i < neigh[v].size(); i++)
        res += getSize(neigh[v][i], tk, forb1, forb2);
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &n, &m, &a, &b);
        for (int i = 1; i <= n; i++) {
            neigh[i].clear();
            tk[i] = tka[i] = tkb[i] = false;
        }
        for (int i = 0; i < m; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        ll res = ll(n - 2) * (n - 3) / 2;
        ll one = 0;
        int siz = getSize(a, tka, -1, b);
        one += ll(siz - 1) * (siz - 2) / 2;
        siz = getSize(b, tkb, -1, a);
        one += ll(siz - 1) * (siz - 2) / 2;
        res -= one;
        siz = 0;
        for (int i = 1; i <= n; i++) if (i != a && i != b && tka[i] && tkb[i])
            siz++;
        res += ll(siz) * (siz - 1) / 2;
        printf("%I64d\n", res);
    }
    return 0;
}