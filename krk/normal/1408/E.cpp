#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 200005;

int m, n;
int a[Maxn], b[Maxn];
int par[Maxn], siz[Maxn];
vector <iii> E;
ll res;

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

bool unionSet(int a, int b)
{
    a = getPar(a), b = getPar(b);
    if (a == b) return false;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b]; par[b] = a;
    return true;
}

int main()
{
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    for (int i = 1; i <= m + n; i++)
        par[i] = i, siz[i] = 1;
    for (int i = 1; i <= m; i++) {
        int cnt; scanf("%d", &cnt);
        while (cnt--) {
            int v; scanf("%d", &v);
            E.push_back(iii(a[i] + b[v], ii(i, m + v)));
            res += ll(a[i]) + ll(b[v]);
        }
    }
    sort(E.rbegin(), E.rend());
    for (int i = 0; i < E.size(); i++)
        if (unionSet(E[i].second.first, E[i].second.second))
            res -= E[i].first;
    cout << res << endl;
    return 0;
}