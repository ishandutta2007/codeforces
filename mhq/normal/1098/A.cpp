#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
const int maxN = (int)1e5 + 100;
int h[maxN];
ll s[maxN];
vector < int > g[maxN];
int p[maxN];
ll ans = 0;
void dfs(int v) {
    if (g[v].empty()) return ;
    for (int to : g[v]) {
        dfs(to);
    }
    if (h[v] % 2 == 0) {
        int prv = p[v];
        ll mn = s[g[v][0]];
        ll sm = 0;
        for (int to : g[v]) {
            mn = min(mn, s[to]);
        }
        if (mn < s[prv]) {
            cout << -1;
            exit(0);
        }
        mn -= s[prv];
        for (int to : g[v]) {
            sm += s[to] - mn - s[prv];
        }
        ll deg = (ll)g[v].size();
        // mn + sm - deg * s[prv]
        // ax + ay =
        ans += mn + sm;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    h[1] = 1;
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        g[p[i]].push_back(i);
        h[i] = h[p[i]] + 1;
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        if ((h[i] % 2) != 0) {
            if (s[i] == -1) {
                cout << -1;
                exit(0);
            }
        }
    }
    ans = s[1];
    dfs(1);
    cout << ans;
    return 0;
}