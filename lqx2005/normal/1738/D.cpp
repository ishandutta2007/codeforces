#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define vi vector<int>
using namespace std;
const int N = 1e5 + 10;
int n, b[N], a[N], c[N];
vector<int> g[N];
deque<int> q;
void solve() {
    cin >> n;
    FOR(i, 0, n + 1) g[i].clear(), a[i] = 0;
    FOR(i, 1, n) {
        cin >> b[i];
        g[b[i]].emplace_back(i);
    }
    q.emplace_back(0), q.emplace_back(n + 1);
    int tot = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop_front();
        if(1 <= u && u <= n) c[++tot] = u;
        sort(g[u].begin(), g[u].end(), [&](int x, int y) {
            return sz(g[x]) < sz(g[y]);
        });
        for(auto v : g[u]) q.emplace_back(v), a[v] = a[u] ^ 1;
    }
    int cnt = 1;
    while(cnt + 1 <= n && a[cnt + 1] == a[cnt]) cnt++;
    if(cnt == n && b[c[1]] == 0) cnt = 0;
    cout << cnt << "\n";
    FOR(i, 1, n) cout << c[i] <<" ";
    cout << "\n";
    return;
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; ) solve();
    return 0;
}