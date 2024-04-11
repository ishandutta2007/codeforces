#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<vi> adj(n);

    for (int i = 0; i + 1 < n; ++i){
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    function<int(int,int)> dfs = [&](int s, int p) {
        int sum_size = 1;

        for (auto u : adj[s]){
            if (u == p)
                continue;

            int c = dfs(u, s);

            if (c <= 0)
                return c;

            sum_size += c;
        }

        if (2 * (n - sum_size) < n)
            return -s;
        else
            return sum_size;
    };

    function<int(int,int)> get_size = [&](int s, int p){
        int sum_size = 1;
        for (auto u : adj[s]){
            if (u != p)
                sum_size += get_size(u, s);
        }
        return sum_size;
    };

    int centroid = -dfs(0, -1);

    vector<pii> order;

    for (auto u : adj[centroid]){
        order.push_back(pii(get_size(u, centroid), u));
    }

    sort(order.begin(), order.end());

    vector<pair<pii,int>> edges;

    int skips = 1;
    int mode = 0;

    int value = 0;

    function<void(int,int,int, int)> make_fill = [&](int s, int p, int skip, int cur) {
        value += skip;
        edges.push_back(make_pair(pii(s, p), value - cur));
        cur = value;

        for (auto u : adj[s]){
            if (u == p) continue;
            make_fill(u, s, skip, cur);
        }
    };

    for (auto x : order) {
        if (mode == 0){
            make_fill(x.second, centroid, skips, 0);

            if (3 * value >= n){
                mode = 1;
                skips = value + 1;
                value = 0;
            }
        } else {
            make_fill(x.second, centroid, skips, 0);
        }
    }

    for (auto e : edges) {
        cout << e.first.first + 1 << " " << e.first.second + 1 << " " << e.second << endl;
    }

    return 0;
}