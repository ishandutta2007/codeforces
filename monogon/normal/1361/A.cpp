
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

const int N = 5e5 + 5;
int n, m, u, v, t[N];
vi adj[N];
// bool vis[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, m) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<pii> ve;
    rep(i, 1, n + 1) {
        cin >> t[i];
        ve.emplace_back(t[i], i);
    }
    // fill(val + 1, val + n + 1, 1);
    sort(all(ve));
    for(auto &p : ve) {
        int i = p.second;
        vi vv;
        for(int j : adj[i]) {
            vv.push_back(t[j]);
        }
        sort(all(vv));
        vv.erase(unique(all(vv)), vv.end());
        int mex = sz(vv) + 1;
        rep(i, 0, sz(vv)) {
            if(vv[i] != i + 1) {
                mex = i + 1;
                break;
            }
        }
        if(t[i] != mex) {
            cout << "-1\n";
            return 0;
        }
    }
    for(auto &p : ve) {
        cout << p.second << ' ';
    }
    cout << '\n';
}