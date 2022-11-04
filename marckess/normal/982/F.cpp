#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 100005;
int n, m, u, v, vis[MX], num[MX], acu[MX], cn = 0;
vi p, adj[MX];
bitset<MX> ex;

int findCyc (int u) {
    vis[u] = 1;

    for (int v : adj[u]) {
        if (vis[v] == 1) {
            p.push_back(v);
            return v;
        }

        if (vis[v] == 2)
            continue;
        
        int d = findCyc(v);
        if (d > 0) {
            p.push_back(v);
            if (d == u)
                return -1;
            return d;
        }
        if (d < 0)
            return -1;
    }

    vis[u] = 2;
    return 0;
}

int dfs (int u, int s) {
    if (num[u] != -1)
        return u;
    vis[u] = -1;
    int mn = 1e9;

    for (int v : adj[u]) {
        if (vis[v] == -1)
            continue;

        int d = 0;
        if (vis[v] > 0)
            d = vis[v];
        else
            d = dfs(v, s);
        
        if (d == -1)
            continue;

        if (vis[u] == -1) {
            vis[u] = d;
            if (num[s] >= num[d])
                mn = num[s] - num[d];
            else
                mn = p.size() + num[s] - num[d];
        } else {
            int e;
            if (num[s] >= num[d])
                e = num[s] - num[d];
            else
                e = p.size() + num[s] - num[d];

            if (e < mn) {
                vis[u] = d;
                mn = e;
            }
        }
    }

    return vis[u];
}

bool cyc (int u) {
    vis[u] = 1;

    for (int v : adj[u]) {
        if (!ex[v] || vis[v] == 2)
            continue;
        if (vis[v] == 1 || cyc(v))
            return 1;
    }

    vis[u] = 2;
    return 0;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            findCyc(i);
        if (p.size())
            break;
    }

    fill(num, num+MX, -1);
    reverse(ALL(p));
    for (int i = 0; i < p.size(); i++) {
        //cout << p[i] << endl;
        num[p[i]] = i;
    }

    fill(vis, vis+MX, 0);
    for (int i = 0; i < p.size(); i++) {
        for (int v : adj[p[i]]) {
            if ((num[v] != -1 && (i + 1) % p.size() == num[v]) || vis[v] == -1)
                continue;

            int d;
            if (vis[v]) d = vis[v];
            else d = dfs(v, p[i]);

            if (d == -1)
                continue;

            if (num[d] <= i) {
                acu[num[d]]++, acu[i+1]--;
            } else {
                acu[0]++, acu[i+1]--, acu[num[d]]++;
            }
            cn++;
        }
    }

    for (int i = 1; i < p.size(); i++)
        acu[i] += acu[i-1];

    ex.set();
    int res = -1;
    for (int i = 0; i < p.size(); i++) {
        if (acu[i] == cn) {
            res = p[i];
            ex[p[i]] = 0;
        }
    }

    fill(vis, vis+MX, 0);
    for (int i = 1; i <= n; i++) {
        if (ex[i] && !vis[i]) {
            if (cyc(i)) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << res << endl;

    return 0;
}