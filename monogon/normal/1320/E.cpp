
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, x, y, q, k, m;
vector<int> adj[N], child[N];
int v[N], s[N], u[N], depth[N], tin[N], tout[N], par[N][20];
int p[N], virus[N], speed[N], tim[N];
int t = 0;

void dfs(int x) {
    tin[x] = t++;
    for(int y : adj[x]) {
        if(par[y][0] == 0) {
            par[y][0] = x;
            depth[y] = depth[x] + 1;
            dfs(y);
        }
    }
    tout[x] = t++;
}

bool anc(int x, int y) {
    return tin[x] <= tin[y] && tout[y] <= tout[x];
}

int lca(int x, int y) {
    if(anc(x, y)) return x;
    for(int k = 19; k >= 0; k--) {
        if(!anc(par[x][k], y)) x = par[x][k];
    }
    return par[x][0];
}
int dist(int x, int y) {
    int c = lca(x, y);
    return depth[x] + depth[y] - 2 * depth[c];
}

void clear(int x) {
    virus[x] = speed[x] = -1;
    for(int y : child[x]) clear(y);
}
void dfsdp(int x) {
    tim[x] = (virus[x] == -1 ? INT_MAX : 0);
    for(int y : child[x]) {
        dfsdp(y);
        if(virus[y] != -1 && pair(tim[x], virus[x]) > pair((depth[v[virus[y]]] - depth[x] + speed[y] - 1) / speed[y], virus[y])) {
            speed[x] = speed[y];
            virus[x] = virus[y];
            tim[x] = (depth[v[virus[y]]] - depth[x] + speed[y] - 1) / speed[y];
        }
    }
}
void dfsdp2(int x) {
    for(int y : child[x]) {
        if(pair(tim[y], virus[y]) > pair((dist(y, v[virus[x]]) + speed[x] - 1) / speed[x], virus[x])) {
            speed[y] = speed[x];
            virus[y] = virus[x];
            tim[y] = (dist(y, v[virus[x]]) + speed[x] - 1) / speed[x];
        }
        dfsdp2(y);
    }
}

void solve(int root) {
    clear(root);
    for(int i = 0; i < k; i++) {
        virus[v[i]] = i;
        speed[v[i]] = s[i];
    }
    dfsdp(root);
    dfsdp2(root);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    par[1][0] = 1;
    dfs(1);
    for(int k = 1; k < 20; k++) {
        for(int i = 1; i <= n; i++) {
            par[i][k] = par[par[i][k - 1]][k - 1];
        }
    }
    cin >> q;
    while(q--) {
        cin >> k >> m;
        vector<int> ve;
        for(int i = 0; i < k; i++) {
            cin >> v[i] >> s[i];
            ve.push_back(v[i]);
        }
        for(int i = 0; i < m; i++) {
            cin >> u[i];
            ve.push_back(u[i]);
        }
        sort(ve.begin(), ve.end(), [](int a, int b) { return tin[a] < tin[b]; });
        ve.erase(unique(ve.begin(), ve.end()), ve.end());
        set<int> sv;
        stack<int> st;
        for(int x : ve) {
            int y = 0;
            while(!st.empty() && !anc(st.top(), x)) {
                y = st.top(); st.pop();
            }
            if(y == 0) {
                p[x] = (st.empty() ? x : st.top());
            }else {
                int c = lca(x, y);
                p[x] = p[y] = c;
                if(st.empty()) {
                    p[c] = c;
                    st.push(c);
                }else if(c != st.top()) {
                    p[c] = st.top();
                    st.push(c);
                }
                sv.insert(c);
            }
            sv.insert(x);
            st.push(x);
        }
        for(int x : sv) child[x].clear();
        int root = 0;
        for(int x : sv) {
            if(p[x] != x) {
                child[p[x]].push_back(x);
            }else {
                root = x;
            }
        }
        assert(root != 0);
        solve(root);
        for(int i = 0; i < m; i++) {
            cout << virus[u[i]] + 1 << " ";
        }
        cout << endl;
    }
}