#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 200005, mod = 1000000007;
int n, p[MX];
ll dp[MX], res[MX], pre[MX], suf[MX];
vi adj[MX];

ll dfs (int u) {
    ll &x = dp[u] = 1, acu;

    for (int v : adj[u])
        x = x * dfs(v) % mod;

    acu = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        pre[v] = acu;
        acu *= dp[v] + 1;
        acu %= mod;
    }

    acu = 1;
    for (int i = (int)adj[u].size() - 1; i >= 0; i--) {
        int v = adj[u][i];
        suf[v] = acu;
        acu *= dp[v] + 1;
        acu %= mod;
    }

    return (x + 1) % mod;
}

void obtRes (int u, ll p) {
    ll &x = res[u] = p * dp[u] % mod;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        obtRes(v, (p * pre[v] % mod * suf[v] + 1) % mod);
    }
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        adj[p[i]].push_back(i);
    }

    dfs(1);
    obtRes(1, 1);

    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}