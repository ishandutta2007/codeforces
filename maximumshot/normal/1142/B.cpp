#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;

using namespace std;

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;
typedef pair<long double, long double> pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

const int N = 2e5 + 5;

int n, m, q;
int p[N], p1[N];
int a[N];
int last[N];
vector<int> g[N];
int used[N];
int dp[N];
int st[N], sz;

void dfs(int v) {
    used[v] = 1;
    st[sz++] = v;
    dp[v] = sz >= n ? st[sz - n] : 0;
    for (int to : g[v]) {
        dfs(to);
    }
    sz--;
}

int mx[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        p1[p[i]] = i;
    }

    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        a[i] = p1[a[i]];
//        cout << a[i] << " ";
    }
//    cout << "\n";

    for (int i = 1; i <= m; i++) {
        int x = a[i];
        if (!--x) x = n;
        int j = last[x];
        if (j) g[j].push_back(i);
        last[a[i]] = i;
//        cout << j << " -> " << i << "\n";
    }

    for (int v = 1; v <= m; v++) {
        if (used[v]) {
            continue;
        }
        dfs(v);
    }

//    for (int v = 1; v <= m; v++) {
//        cout << dp[v] << " ";
//    }

//    cout << "\n";

    for (int v = 1; v <= m; v++) {
        mx[v] = max(mx[v - 1], dp[v]);
    }

    for (int iter = 0; iter < q; iter++) {
        int l, r;
        cin >> l >> r;
        cout << (mx[r] >= l);
    }
    cout << "\n";

    return 0;
}