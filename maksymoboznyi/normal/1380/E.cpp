#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 2e5 + 5;

int m, n;
int to[N], good[N], id[N];
vector<int> a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        id[i] = x;
        to[i] = i;
        a[x].pb(i);
    }
    int ans = n - 1;
    for (int i = 1; i < n; i++)
        if (id[i] == id[i + 1])
            ans--;
    cout << ans << "\n";
    for (int o = 1; o < m; o++) {
        int u, v;
        cin >> u >> v;
        int UU = u;
        u = to[u];
        v = to[v];
        if (a[u].size() > a[v].size())
            swap(u, v);
        else
            to[UU] = v;
        for (auto x: a[u]) {
            a[v].pb(x);
            if (id[x + 1] == v)
                ans--;
            if (id[x - 1] == v)
                ans--;
        }
        for (auto x: a[u])
            id[x] = v;
        a[u].clear();
        cout << ans << "\n";
    }
    return 0;
}