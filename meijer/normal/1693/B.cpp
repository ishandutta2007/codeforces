#include <bits/stdc++.h>
#define int long long
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()

const int N = (1<<20);
const int mod = 1e9+7;

int t, n, p[N], l[N], r[N];
vector<int> chl[N];

pair<int,int> dfs(int u) {
    int tot = 0;
    int mx = 0;
    for (int v : chl[u]) {
        auto p = dfs(v);
        tot += p.first;
        mx += p.second;
    }
    if (mx >= l[u]) {
        return {tot, min(mx, r[u])};
    } else {
        return {tot+1, r[u]};
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        p[1] = 1;
        for (int i=2; i<=n; i++) {
            cin >> p[i];
        }
        for (int i=1; i<=n; i++) {
            cin >> l[i] >> r[i];
            chl[i].clear();
        }
        for (int i=2; i<=n; i++) {
            chl[p[i]].push_back(i);
        }
        int res = dfs(1).first;
        cout << res << endl;
    }
}