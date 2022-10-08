
#pragma GCC optimize ("Ofast")
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

const int N = 2e5 + 5;

struct edge {
    int v, w;
    bool operator<(const edge &e) const {
        return w < e.w;
    }
};

int n, m, k;
vector<edge> adj[N], adjr[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    rep(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    rep(i, 1, n + 1) {
        sort(all(adj[i]));
        int cnt = 1;
        int k = sz(adj[i]);
        rep(j, 0, k) {
            adj[i][j].w = cnt;
            adjr[adj[i][j].v].push_back({i, adj[i][j].w});
            cnt++;
        }
    }
    set<pair<pii, pii>> se;
    rep(i, 1, n + 1) {
        vector<pii> ve;
        for(auto &e : adjr[i]) {
            pii p = make_pair(sz(adj[e.v]), e.w);
            if(find(all(ve), p) != ve.end()) {
                // self-edge p-p
                se.insert(make_pair(p, p));
            }else {
                ve.push_back(p);
            }
        }
        int k = sz(ve);
        rep(i, 0, k) {
            rep(j, i + 1, k) {
                // add edge ve[i] - ve[j]
                se.insert(make_pair(ve[i], ve[j]));
            }
        }
    }
    vi c(k + 1);
    fill(all(c), 1);
    int ans = 0;
    while(true) {
        bool flag = true;
        for(auto &pa : se) {
            pii p1 = pa.first;
            pii p2 = pa.second;
            if(c[p1.first] == p1.second && c[p2.first] == p2.second) {
                flag = false;
                break;
            }
        }
        ans += flag;
        int i = 1;
        while(i <= k && c[i] == i) {
            c[i] = 1;
            i++;
        }
        if(i > k) break;
        c[i]++;
    }
    cout << ans << '\n';
}