
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 2e5 + 5;
int n, m;
string s[N];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
char ch[4] = {'L', 'R', 'U', 'D'};
map<char, int> dirmap = {{'L', 0}, {'R', 1}, {'U', 2}, {'D', 3}};
int opp[4] = {1, 0, 3, 2};
int par[N], dp[N], tin[N], inv[2 * N], tout[N], t = 0, mate[N];
bool vis[N];
vi adj[N];
ll ans = 0;

bool inbounds(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs(int x, int y) {
    assert(vis[x * m + y] == 0);
    vis[x * m + y] = true;
    dp[x * m + y] = 1;
    rep(d, 0, 4) {
        int xx = x + dx[d];
        int yy = y + dy[d];
        if(inbounds(xx, yy) && s[xx][yy] == ch[opp[d]]) {
            xx += dx[d];
            yy += dy[d];
            assert(inbounds(xx, yy));
            if(!vis[xx * m + yy]) {
                dfs(xx, yy);
            }
            par[xx * m + yy] = x * m + y;
            adj[x * m + y].push_back(xx * m + yy);
            dp[x * m + y] += dp[xx * m + yy];
        }
    }
}
void dfs2(int u) {
    inv[t] = u;
    tin[u] = t++;
    for(int v : adj[u]) {
        dfs2(v);
    }
    tout[u] = t++;
}

int cnt = 0;
set<int> ss;
vi ls[2 * N];

void ins(int v) {
    auto il = ss.lower_bound(tin[v]);
    auto ir = ss.lower_bound(tout[v]);
    if(il != ss.begin() && tout[inv[*prev(il)]] >= tout[v]) return;
    for(auto it = il; it != ir; it++) {
        ls[tin[v]].push_back(*it);
        cnt -= dp[inv[*it]];
    }
    ss.erase(il, ir);
    ss.insert(tin[v]);
    cnt += dp[v];
}
void del(int v) {
    if(ss.count(tin[v])) {
        ss.erase(tin[v]);
        cnt -= dp[v];
        for(int x : ls[tin[v]]) {
            ss.insert(x);
            cnt += dp[inv[x]];
        }
    }
}

void solve(int u) {
    ins(mate[u]);
    ans += cnt;
    for(int v : adj[u]) {
        solve(v);
    }
    del(mate[u]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> s[i];
    }
    fill(par, par + N, -1);
    rep(i, 0, n) rep(j, 0, m) {
        if(!vis[i * m + j]) {
            dfs(i, j);
        }
    }
    rep(i, 0, n) rep(j, 0, m) {
        if(par[i * m + j] == -1) {
            dfs2(i * m + j);
        }
        int d = opp[dirmap[s[i][j]]];
        mate[i * m + j] = (i + dx[d]) * m + (j + dy[d]);
    }
    rep(i, 0, n) rep(j, 0, m) {
        if(par[i * m + j] == -1 && (i + j) % 2 == 0) {
            solve(i * m + j);
        }
    }
    cout << ans << '\n';
}