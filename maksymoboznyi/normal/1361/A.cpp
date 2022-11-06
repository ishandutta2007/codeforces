#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define pi pair<int, int>

using namespace std;

const int N = 5e5 + 5;

int n, m, t[N], ans[N];
vector<int> g[N];
pair<int, int> a[N];

bool cmp(int a, int b) {
    return ans[a] < ans[b];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        a[i].first = t[i];
        a[i].second = i;
        ans[i] = 1e9;
    }
    sort(a + 1, a + n + 1);
    vector<int> q;
    for (int i = 1; i <= n; i++) {
        int v = a[i].second;
        q.pb(v);
        if (g[v].size() == 0) {
            if (t[v] != 1) {
                cout << -1;
                return 0;
            }
            ans[v] = 1;
            continue;
        }
        sort(all(g[v]), cmp);

        if (ans[g[v][0]] != 1) {
            ans[v] = 1;
            if (ans[v] != t[v]) {
                cout << -1;
                return 0;
            }
        } else {
            for (int i = 1; i < g[v].size(); i++)
                if (ans[g[v][i - 1]] + 1 < ans[g[v][i]]) {
                    ans[v] = ans[g[v][i - 1]] + 1;
                    break;
                }
                if (ans[v] == 1e9) {
                    ans[v] = ans[g[v].back()] + 1;
                }
                if (ans[v] != t[v]) {
                    cout << -1;
                    return 0;
                }
        }
        //cout << ans[v] <<endl;
    }
    for (auto x: q)
        cout << x << ' ';
    return 0;
}