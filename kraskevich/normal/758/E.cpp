#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 200 * 1000 + 10;

vector<int> g[N];
vector<ll> w[N];
vector<ll> p[N];
ll sum[N];
ll minw[N];
ll maxw[N];
bool ok = true;
map<pii, ll> delta;

void dfs2(int v, int par) {
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to != par) {
            dfs2(to, v);
            ll low = minw[to];
            if (low > p[v][i]) {
                ok = false;
                break;
            }
            ll d = min(p[v][i] - low, w[v][i] - 1);
            low += w[v][i] - d;
            ll high = maxw[to];
            high = min(high, p[v][i]);
            high += w[v][i];
            minw[v] += low;
            maxw[v] += high;                    
        }
    } 
}

void dfs3(int v, int par, ll extra) {
    assert (extra >= 0 && extra + minw[v] <= maxw[v]);
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to != par) {
            ll low = minw[to];
            assert (low <= p[v][i]);
            ll d = min(p[v][i] - low, w[v][i] - 1);
            ll dec = min(d, extra);
            extra -= dec;
            delta[pii(min(v, to), max(v, to))] = d - dec;
            ll there = min(p[v][i] - d + dec, maxw[to]) - minw[to];
            dfs3(to, v, min(extra, there));
            extra -= min(extra, there);         
        }    
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); 
    int n;
    cin >> n;
    vector<int> x(n - 1), y(n - 1);
    vector<ll> wht(n - 1), st(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> x[i] >> y[i] >> wht[i] >> st[i]; 
        x[i]--;
        y[i]--;
        g[x[i]].push_back(y[i]);
        g[y[i]].push_back(x[i]);
        w[x[i]].push_back(wht[i]);
        w[y[i]].push_back(wht[i]);
        p[x[i]].push_back(st[i]);
        p[y[i]].push_back(st[i]);            
    }  
    dfs2(0, 0);
    if (!ok) {
        cout << -1 << endl;
        return 0;
    }
    //cerr << maxw[0] << " " << minw[0] << endl;
    dfs3(0, 0, maxw[0] - minw[0]);
    cout << n << "\n";
    for (int i = 0; i < n - 1; i++) {
        auto cur = pii(min(x[i], y[i]), max(y[i], x[i]));
        cout << x[i] + 1 << " " << y[i] + 1 << " " << wht[i] - delta[cur] << " " << st[i] - delta[cur] << "\n";        
    }
}