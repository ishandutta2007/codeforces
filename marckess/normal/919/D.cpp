#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int n, m, a, b;
string s;
vvi adj(300005);
vi vis;


bool hayCiclo (int u) {
    vis[u] = 1;

    for (int v : adj[u]) {
        if (!vis[v]) {
            if (hayCiclo(v))
                return 1;
        } else if (vis[v] == 1) {
            return 1;
        }
    }

    vis[u] = 2;
    return 0;
}

vvi dp (27, vi(300005, 0));

void flan (int u) {
    vis[u] = 1;

    for (int v : adj[u]) {
        if (!vis[v])
            flan(v);
        for (int i = 0; i < 26; i++)
            dp[i][u] = max(dp[i][v], dp[i][u]);
    }

    dp[s[u-1]-'a'][u]++;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m >> s;
    while (m--) {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vis = vi(n+1, 0);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (hayCiclo(i)) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    vis = vi(n+1, 0);
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            flan(i);

    int mx = 0;
    for (int i = 0; i < 27; i++)
        mx = max(mx, *max_element(dp[i].begin(), dp[i].end()));

    cout << mx << endl;

    return 0;
}