
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

const int N = 1505;
int n, dp[N];
vi adj[N], child[N];

void dfs(int x, int p) {
    dp[x] = 1;
    for(int y : adj[x]) {
        if(y != p) {
            child[x].push_back(y);
            dfs(y, x);
            dp[x] += dp[y];
        }
    }
}

struct pt {
    ll x, y;
    int idx;
    pt operator-(const pt &o) const {
        return (pt) {x - o.x, y - o.y, -1};
    }
} p[N];

int ans[N];

ll cross(const pt &a, const pt &b) {
    return a.x * b.y - a.y * b.x;
}

void solve(int l, int r, int v) {
    ans[p[l].idx] = v;
    sort(p + l + 1, p + r + 1, [&](auto &a, auto &b) {
        return cross(a - p[l], b - p[l]) < 0; 
    });
    int k = l + 1;
    for(int y : child[v]) {
        solve(k, k + dp[y] - 1, y);
        k += dp[y];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    rep(i, 1, n + 1) {
        cin >> p[i].x >> p[i].y;
        p[i].idx = i;
    }
    sort(p + 1, p + n + 1, [&](auto &a, auto &b) {return a.x < b.x;});
    solve(1, n, 1);
    rep(i, 1, n + 1) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}