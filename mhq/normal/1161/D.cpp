    #pragma optimize "-O3"
    #include <bits/stdc++.h>
    using namespace std;
    typedef long double ld;
    typedef long long ll;
    const int mod = 998244353;
    int sum(int a, int b) {
        int s = a + b;
        if (s >= mod) s -= mod;
        return s;
    }
    int mult(int a, int b) {
        return (1LL * a * b) % mod;
    }
    int sub(int a, int b) {
        int s = a - b;
        if (s < 0) s += mod;
        return s;
    }
    const int maxN = 3005;
    int pw2[maxN];
    string s;
    vector < pair < int, int > > g[maxN];
    void add_edge(int a, int b, int we) {
        g[a].emplace_back(b, we);
        g[b].emplace_back(a, we);
    }
    int cmp = 0;
    bool ALL_OK = true;
    bool used[maxN];
    int clr[maxN];
    void dfs(int v) {
        used[v] = true;
        for (auto it : g[v]) {
            int to = it.first;
            int c = it.second;
            if (used[to]) {
                if ((clr[to] ^ clr[v]) == c) continue;
                ALL_OK = false;
                return ;
            }
            else {
                clr[to] = (clr[v] ^ c);
                dfs(to);
            }
        }
    }
    int solve(int len) {
        for (int i = 0; i < maxN; i++) g[i].clear();
        int n = s.size();
        // 1 .. n
        // n + 1 .. 2n
       // cout << len << endl;
        for (int j = len; j < n; j++) {
            add_edge(j + n + 1, 0, 0);
        }
        if (len > 0) {
            add_edge(n + len - 1 + 1, 0, 1);
            for (int j = 0; j <= len - 1; j++) {
                int l = j;
                int r = len - 1 - j;
                if (l < r) {
                    add_edge(l + n + 1, r + n + 1, 0);
                }
            }
            for (int j = 0; j <= len - 1; j++) {
                if (s[n - 1 - j] != '?') {
                    add_edge(n + j + 1, j + 1, s[n - 1 - j] - '0');
                }
            }
        }
        for (int j = len; j < n; j++) {
            if (s[n - 1 - j] != '?') {
                add_edge(j + 1, 0, s[n - 1 - j] - '0');
            }
        }
        for (int j = 0; j < n; j++) {
            int l = j;
            int r = n - 1 - j;
            if (l < r) {
                add_edge(l + 1, r + 1, 0);
            }
        }
        memset(used, 0, sizeof used);
        memset(clr, 0, sizeof clr);
        ALL_OK = true;
        cmp = 0;
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                cmp++;
                clr[i] = 0;
                dfs(i);
            }
        }
        for (int i = n + 1; i <= n + len; i++) {
            if (!used[i]) {
                cmp++;
                clr[i] = 0;
                dfs(i);
            }
        }
        if (!ALL_OK) return 0;
       // if (g[0].empty()) cmp--;
        return pw2[cmp - 1];
    }
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        //freopen("input.txt", "r", stdin);
        pw2[0] = 1;
        for (int i = 1; i < maxN; i++) pw2[i] = mult(2, pw2[i - 1]);
        cin >> s;
        int ans = 0;
        for (int i = 1; i < s.size(); i++) {
            ans = sum(ans, solve(i));
        }
        cout << ans;
        return 0;
    }