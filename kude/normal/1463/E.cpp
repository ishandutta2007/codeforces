#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    VVI g(n);
    VI p(n);
    rep(i, n) cin >> p[i], p[i]--;
    VI to(n, -1), from(n, -1);
    rep(i, k) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        to[x] = y;
        from[y] = x;
    }
    VI visited(n);
    rep(s, n) if (from[s] == -1) {
        vector<int> ps;
        unordered_set<int> seen;
        for(int v = s; v != -1; v = to[v]) {
            visited[v] = true;
            if (p[v] != -1 && !seen.count(p[v])) {
                g[p[v]].push_back(s);
            }
            seen.insert(v);
        }
    }
    rep(i, n) if (!visited[i]) {
        cout << 0 << endl;
        return 0;
    }
    VI ans;
    deque<int> q;
    VI indeg(n);
    rep(u, n) for(int v: g[u]) indeg[v]++;
    rep(i, n) if (indeg[i] == 0) q.push_back(i);
    //rep(u, n) for(int v: g[u]) cout << u+1 << " -> " << v+1 << endl;
    while(!q.empty()) {
        int u = q.front(); q.pop_front();
        //cout << u << endl;
        ans.push_back(u);
        for(int v: g[u]) {
            indeg[v]--;
            //cout << "current indeg of " << v << " " << indeg[v] << endl;
            if (indeg[v] == 0) {
                if (v == to[u]) q.push_front(v);
                else q.push_back(v);
            }
        }
    }
    if (ans.size() != n) cout << 0 << endl;
    else {
        rep(i, n) cout << ans[i] + 1 << " \n"[i + 1 == n];
    }
}