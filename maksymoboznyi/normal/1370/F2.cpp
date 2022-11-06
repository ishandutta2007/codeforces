#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 1e3 + 3;

int n, mxdep, dep[N], par[N];
vector<int> g[N], lst;
int xx, dd, D;

void dfs(int v, int p = 0) {
    dep[v] = dep[p] + 1;
    mxdep = max(mxdep, dep[v]);
    par[v] = p;
    for (auto u: g[v])
        if (u != p)
            dfs(u, v);
}

void dfs2(int v, int oo, int dpx, int p = 0) {
    if (dep[v] - 1 == D - dpx + 1)
        lst.pb(v);
    for (auto u: g[v])
        if (u != oo && u != p)
            dfs2(u, oo, dpx, v);
}

bool check(int d) {
    vector<int> c;
    for (int i = 1; i <= n; i++)
        if (dep[i] == d)
            c.pb(i);
    cout << "? " << c.size() << ' ';
    for (auto x: c)
        cout << x << ' ';
    cout << endl;
    cin >> xx >> dd;
    if (xx == -1)
        exit(0);
    return dd == D;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    mxdep = 0;

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    cout << "? " << n << ' ';
    for (int i = 1; i <= n; i++)
        cout << i << ' ';
    cout << endl;
    int s, d;
    cin >> s >> d;
    if (s == -1)
        exit(0);
    D = d;
    dfs(s);
    int l = d / 2, r = min(mxdep, d + 1) + 1;
    int first = s;
    int kol = 0;
    while (l < r - 1) {
        int m = (l + r) / 2;
        kol++;
        if (check(m)) {
            first = xx;
            l = m;
        } else
            r = m;
    }
    int a1 = first;
    int dpx = dep[first];

    while (first != s && par[first] != s)
        first = par[first];
    lst.clear();
    dfs2(s, first, dpx);
    cout << "? " << lst.size() << ' ' ;
    for (auto x: lst)
        cout << x << ' ';
    cout << endl;
    int a2, dd;
    cin >> a2 >> dd;
    cout << "! " << a1 <<  ' ' << a2 << endl;
    string ans;
    cin >> ans;
    if (ans == "Incorrect")
        exit(0);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}