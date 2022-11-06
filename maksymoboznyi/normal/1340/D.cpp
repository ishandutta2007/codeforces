#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

const int N = 1e5 + 5;

int n, mx = 0;
vector<int> g[N];
vector<pi> ans;
int t = 0;
void dfs(int v, int p, int need) {
    //cout << v << ' ' << need << endl;
    int sons = 0;
    sons = g[v].size() - (p != 0);
    ans.pb({v, t});
    if (t == mx && sons > 0) {
        t = need - sons;
        ans.pb({v, t});
    }
    for (auto u: g[v])
        if (u != p) {
            t++;
            dfs(u, v, t - 1);
            sons--;
            t++;
            ans.pb({v, t});
            if (t == mx && p != 0) {
                t = need - sons;
                ans.pb({v, t});
            }
        }

    if (p != 0 && t > need) {
        t = need;
        ans.pb({v, t});
    }
}

signed main()
{
    srand(time(0));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 1; i <= n; i++)
        mx = max(mx, (int)g[i].size());
    dfs(1, 0, -1);
    cout << ans.size() << "\n";
    for (auto p: ans)
        cout << p.first << ' ' << p.second << "\n";
    return 0;
}