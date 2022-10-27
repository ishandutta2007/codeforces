#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int nax = 3e5 + 10;
int add(int a, int b) {
    return (a += b) >= MOD ? a - MOD : a;
}
int n, m, k;
bool vis[nax];
vector <int> nxt[nax];
vector <int> prv[nax];
int cnt[nax];
int dp[nax];


int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m >> k;

    for (int i = 1 ; i <= n ; ++ i) {
        int c, lst;
        cin >> c >> lst;
        -- c;
        while (c -- > 0) {
            int cur;
            cin >> cur;
            nxt[lst].push_back(cur);
            prv[cur].push_back(lst);
            lst = cur;
        }
    }

    for (int i = 1 ; i <= k ; ++ i) {
        sort(nxt[i].begin(), nxt[i].end());
        nxt[i].erase(unique(nxt[i].begin(), nxt[i].end()), nxt[i].end());
        sort(prv[i].begin(), prv[i].end());
        prv[i].erase(unique(prv[i].begin(), prv[i].end()), prv[i].end());
    }

    queue <int> q;
    for (int num = 1 ; num <= k ; ++ num) {
        if (vis[num]) continue;
        q.push(num);
        vis[num] = true;
        vector <int> comp;
        while (!q.empty()) {
            int t = q.front();
            comp.push_back(t);
            q.pop();
            for (int x : nxt[t]) {
                if (vis[x]) continue;
                vis[x] = true;
                q.push(x);
            }
            for (int x : prv[t]) {
                if (vis[x]) continue;
                vis[x] = true;
                q.push(x);
            }
        }
        bool has_leftmost = false;
        bool failed = false;
        for (int x : comp) {
            if (prv[x].empty()) has_leftmost = true;
            if (nxt[x].size() > 1 || prv[x].size() > 1) failed = true;
        }
        if (!failed && has_leftmost) {
            cnt[comp.size()] += 1;
        }
    }

    vector <pair <int, int>> existed;
    for (int i = 1 ; i <= k ; ++ i) {
        if (cnt[i] > 0) existed.emplace_back(cnt[i], i);
    }


    dp[0] = 1;
    for (int i = 1 ; i <= m ; ++ i) {
        for (const auto &[sz, l] : existed) {
            if (l > i) break;
            dp[i] = add(dp[i], 1LL * dp[i - l] * sz % MOD);
        }
    }
    cout << dp[m] << '\n';

}