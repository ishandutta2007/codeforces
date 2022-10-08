
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

struct node {
    int si = 1, path = 0;
    int mx[3] = {0, 0, 0};
    node(bool b = false) {
        path = (b ? 1 : 0);
    }
    int get() const {
        if(path == 0) return 0;
        return path + mx[0];
    }
    void add(const node &x) {
        if(path > 0) {
            int v = x.get();
            if(v == x.si) path += v;
            else if(v > mx[0]) {
                mx[2] = mx[1];
                mx[1] = mx[0];
                mx[0] = v;
            }else if(v > mx[1]) {
                mx[2] = mx[1];
                mx[1] = v;
            }
        }
        si += x.si;
    }
    void rem(const node &x) {
        if(path > 0) {
            int v = x.get();
            if(v == x.si) path -= v;
            else if(v == mx[0]) {
                mx[1] = mx[2];
                mx[0] = mx[1];
            }else if(v == mx[1]) {
                mx[1] = mx[2];
            }
        }
        si -= x.si;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vi a(n + 1);
    rep(i, 1, n + 1) cin >> a[i];
    vector<vi> g(n + 1);
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int L = 1, R = 1e6 + 5;
    vector<node> dp(n + 1);
    function<void(int, int, int)> dfs = [&](int x, int p, int thres) {
        dp[x] = node(a[x] >= thres);
        for(int y : g[x]) {
            if(y != p) {
                dfs(y, x, thres);
                dp[x].add(dp[y]);
            }
        }
    };
    function<void(int, int, int)> dfs2 = [&](int x, int p, int thres) {
        for(int y : g[x]) {
            if(y != p) {
                node N = dp[y];
                dp[x].rem(N);
                dp[y].add(dp[x]);
                dp[x].add(N);
                dfs2(y, x, thres);
            }
        }
    };
    while(L < R) {
        int m = (L + R) / 2;
        dfs(1, 1, m);
        dfs2(1, 1, m);
        int val = 0;
        rep(i, 1, n + 1) val = max(val, dp[i].get());
        if(val >= k) {
            L = m + 1;
        }else {
            R = m;
        }
    }
    cout << L - 1 << '\n';
}