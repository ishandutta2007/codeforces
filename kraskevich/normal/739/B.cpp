#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll INF = (ll)1e18;
const int N = 200 * 1000 + 100;

vector<int> g[N];
vector<ll> w[N];
vector<pll> cur_h;
ll add[N];
ll ans[N];
ll a[N];

void dfs(int v, int par, ll h) {
    if (v != par) {
        ll lo_dist = h - a[v];
        auto it = lower_bound(cur_h.begin(), cur_h.end(), pll(lo_dist, -INF));
        add[par]++;
        if (it != cur_h.begin()) {
            it--;
            int pos = it->second;
            add[pos]--;
        }  
    }
    cur_h.push_back(pll(h, v));
    for (int i = 0; i < g[v].size(); i++)
        dfs(g[v][i], v, h + w[v][i]);
    cur_h.pop_back();
}

ll dfs2(int v) {
    ans[v] = add[v];
    for (int to : g[v])
        ans[v] += dfs2(to);
    return ans[v];    
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++) {
        int p;
        ll len;
        cin >> p >> len;
        p--;
        g[p].push_back(i);
        w[p].push_back(len);        
    }
    dfs(0, 0, 0);
    dfs2(0);
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
}