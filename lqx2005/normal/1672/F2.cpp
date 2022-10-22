#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define x first
#define y second
#define par pair<int, int>
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5 + 10;
int n, a[N], b[N], cnt[N], deg[N], dp[N];
vector<int> g[N];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cnt[i] = 0, g[i].clear(), deg[i] = 0;
    for(int i = 1; i <= n; i++) cin >> a[i], cnt[a[i]]++;
    for(int i = 1; i <= n; i++) cin >> b[i], g[a[i]].emplace_back(b[i]);
    int ban = -1, tot = 0;
    for(int i = 1; i <= n; i++) if(ban == -1 || cnt[i] > cnt[ban]) ban = i;
    for(int i = 1; i <= n; i++) if(cnt[ban] == cnt[i]) tot++;
    for(int u = 1; u <= n; u++) for(auto v : g[u]) if(v != ban) deg[v]++;
    deque<int> q;
    for(int u = 1; u <= n; u++) if(deg[u] == 0) q.emplace_back(u);
    for(int u = 1; u <= n; u++) dp[u] = 1e9;
    dp[ban] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop_front();
        for(auto v : g[u]) {
            if(v == ban) continue;
            deg[v]--;
            dp[v] = min(dp[v], dp[u] + (cnt[v] == cnt[ban]));
            if(deg[v] == 0) q.emplace_back(v);
        }
    }
    for(int u = 1; u <= n; u++) if(deg[u] > 0) {
        cout << "WA" << endl;
        return;
    }
    int ans = 1e9;
    for(int u = 1; u <= n; u++) for(auto v : g[u]) if(v == ban) ans = min(ans, dp[u]);
    if(ans < tot) {
        cout << "WA" << endl;
        return;
    }
    cout << "AC" << endl;
    return;
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; ) solve();
    return 0;
}