#include <bits/stdc++.h>
using namespace std;

const int N = 200005, A = 26;

int t, n, k, cnt[A];
bool vis[N];
string s;
vector<int> adj[N];

int DFS(int u) {
    vis[u] = true;
    cnt[s[u] - 'a']++;
    int ret = 1;
    for (int &v : adj[u]) {
        if (!vis[v]) {
            ret += DFS(v);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        int ans = 0;
        cin >> n >> k >> s;
        for (int i = 0; i < n; i++) {
            adj[i].clear();
            vis[i] = false;
        }
        // palindrome
        for (int i = 0; i < n; i++) {
            adj[i].push_back(n - 1 - i);
        }
        // k-period
        for (int i = k; i < n; i++) {
            adj[i].push_back(i - k);
            adj[i - k].push_back(i);
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                fill(cnt, cnt + A, 0);
                ans += DFS(i) - *max_element(cnt, cnt + A);
            }
        }
        cout << ans << '\n';
    }
}