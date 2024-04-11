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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 100005;
int n, v[MX], izq[MX], der[MX], deg[MX], root, res = 0;
map<int, ii> mp;

void dfs (int u, int a, int b) {
    if (u == -1)
        return;

    if (a <= v[u] && v[u] <= b)
        mp[v[u]].se = 1;

    dfs(izq[u], a, min(v[u] - 1, b));
    dfs(der[u], max(a, v[u]+1), b);
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> izq[i] >> der[i];
        if (izq[i] != -1)
            deg[izq[i]]++;
        if (der[i] != -1)
            deg[der[i]]++;
        mp[v[i]].fi++;
    }

    for (int i = 1; i <= n; i++)
        if (!deg[i])
            root = i;

    dfs(root, 0, 1e9);

    for (auto &v : mp)
        if (!v.se.se)
            res += v.se.fi;

    cout << res << endl;

    return 0;
}