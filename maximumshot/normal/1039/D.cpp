#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

const int N = 1e5 + 5;

int n;
vector< int > g[N];
pii f[N];
int res[N];
int pr[N];
vector< int > ar;

void go(int v, int par = -1) {
    pr[v] = par;
    ar.push_back(v);
    for(int to : g[v]) {
        if(to == par) continue;
        go(to, v);
    }
}

int F(int k) {
    if(res[k] != -1) return res[k];
    for(int v = 1;v <= n;v++) {
        f[v] = {0, 0};
    }
    for(int v : ar) {
        int mx1 = 0, mx2 = 0;
        int sum = 0;
        for(int to : g[v]) {
            if(to == pr[v]) continue;
            sum += f[to].first;
            if(mx1 < f[to].second) {
                mx2 = mx1;
                mx1 = f[to].second;
            }else if(mx2 < f[to].second) {
                mx2 = f[to].second;
            }
        }
        f[v] = max(make_pair(sum + (mx1 + mx2 + 1) / k, 0), make_pair(sum + (mx1 + 1) / k, (mx1 + 1) % k));
    }
    return res[k] = f[1].first;
}

void rec(int l, int r, int vl, int vr) {
    if(l > r) return;
    if(l == r) {
        res[l] = F(l);
        return;
    }
    if(vl == vr) {
        for(int i = l;i <= r;i++) {
            res[i] = vl;
        }
        return;
    }
    int m = (l + r) / 2;
    rec(l, m - 1, vl, F(m));
    rec(m + 1, r, F(m), vr);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int u, v, i = 1;i < n;i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 1;i <= n;i++) {
        res[i] = -1;
    }

    go(1);
    reverse(ar.begin(), ar.end());

    rec(1, n, F(1), F(n));

    for(int i = 1;i <= n;i++) {
        cout << res[i] << "\n";
    }

    cout << "\n";

    return 0;
}