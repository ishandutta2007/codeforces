
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

const int N = 1e5 + 5, A = 2e6 + 5;
int n, q, a[N], depth[N], ans[N], u, v, ty;
vi adj[N];
map<int, stack<int>> st;
bool vis[N];

void dfs(int x) {
    vis[x] = true;
    vi pr;
    int val = a[x];
    auto upd = [&](int i) {
        if(!st[i].empty() && (ans[x] == -1 || depth[st[i].top()] > depth[ans[x]])) {
            ans[x] = st[i].top();
        }
        pr.push_back(i);
    };
    for(int i = 2; i * i <= val; i++) {
        if(val % i == 0) {
            upd(i);
            while(val % i == 0) val /= i;
        }
    }
    if(val > 1) {
        upd(val);
    }
    for(int p : pr) {
        st[p].push(x);
    }
    for(int y : adj[x]) {
        if(!vis[y]) {
            depth[y] = depth[x] + 1;
            dfs(y);
        }
    }
    for(int p : pr) {
        st[p].pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    rep(i, 1, n + 1) cin >> a[i];
    rep(i, 0, n - 1) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    fill(ans + 1, ans + n + 1, -1);
    dfs(1);
    while(q--) {
        cin >> ty;
        if(ty == 1) {
            cin >> v;
            cout << ans[v] << endl;
        }else {
            cin >> u >> v;
            a[u] = v;
            fill(vis + 1, vis + n + 1, false);
            fill(ans + 1, ans + n + 1, -1);
            dfs(1);
        }
    }
}