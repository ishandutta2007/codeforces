#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long double, long double > pdd;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1e5 + 5;

int n;
vector< int > g[N];
int s[N];
int h[N];
int p[N];
int a[N];

void dfs(int v, int mx = 0) {
    h[v] = h[p[v]] + 1;
    if(h[v] & 1) {
        if(s[v] < mx) {
            puts("-1");
            exit(0);
        }else {
            mx = s[v];
        }
    }else {
        if(g[v].empty()) {
            s[v] = s[p[v]];
        }else {
            s[v] = inf;
            for(int to : g[v]) {
                s[v] = min(s[v], s[to]);
            }
        }
        if(s[v] < mx) {
            puts("-1");
            exit(0);
        }else {
            mx = s[v];
        }
    }
    a[v] = s[v] - s[p[v]];
    for(int to : g[v]) {
        dfs(to, mx);
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int x, i = 2;i <= n;i++) {
        scanf("%d", &x);
        g[x].push_back(i);
        p[i] = x;
    }

    for(int v = 1;v <= n;v++) {
        scanf("%d", &s[v]);
    }

    dfs(1);

    ll sum = 0;

    for(int v = 1;v <= n;v++) {
        sum += a[v];
    }

    printf("%lld\n", sum);

    return 0;
}