#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ii> llii;

const int Maxn = 200005;

int n, m;
ll a[Maxn];
vector <llii> E;
int par[Maxn], siz[Maxn];
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
    scanf("%d %d", &n, &m);
    int mn = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &a[i]);
        if (a[i] < a[mn]) mn = i;
    }
    for (int i = 1; i <= n; i++)
        par[i] = i, siz[i] = 1;
    for (int i = 0; i < m; i++) {
        int a, b; ll c; scanf("%d %d %I64d", &a, &b, &c);
        E.push_back(llii(c, ii(a, b)));
    }
    for (int i = 1; i <= n; i++)
        E.push_back(llii(a[i] + a[mn], ii(i, mn)));
    sort(E.begin(), E.end());
    for (int i = 0; i < E.size(); i++)
        if (unionSet(E[i].second.first, E[i].second.second))
            res += E[i].first;
    cout << res << endl;
    return 0;
}