#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 300005;

int n, m, u, v, t, typ[N];
vector<pair<int, int>> adj[N];
vector<int> ans;

void solve()
{
    cin >> n >> m;
    ans.clear();
    for (int i = 1; i <= 3 * n; i++)
    {
        typ[i] = 0;
        adj[i].clear();
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        if (u < v)
            swap(u, v);
        adj[u].push_back({v, i});
    }
    for (int i = 1; i <= 3 * n; i++)
    {
        bool chk = true;
        for (pair<int, int> &v : adj[i])
            if (typ[v.fi] == 1)
            {
                typ[v.fi] = typ[i] = 2;
                ans.push_back(v.se);
                chk = false;
                break;
            }
        if (chk)
            typ[i] = 1;
    }
    if ((int)ans.size() >= n)
    {
        cout << "Matching\n";
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
    }
    else
    {
        cout << "IndSet\n";
        int cnt = 0;
        for (int i = 1; i <= 3 * n && cnt < n; i++)
            if (typ[i] == 1)
            {
                cnt++;
                cout << i << " ";
            }
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--)
        solve();
}