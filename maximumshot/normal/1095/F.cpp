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

const int N = 2e5 + 5;

int n, m;
ll a[N];
set< pair< ll, pii > > ed;
int p[N], cc;
ll mn[N];

int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}

set< pair< ll, int > > pool;

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    pool.erase({mn[x], x});
    pool.erase({mn[y], y});
    p[y] = x;
    mn[x] = min(mn[x], mn[y]);
    pool.insert({mn[x], x});
    cc--;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    cc = n;

    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        p[i] = i;
        mn[i] = a[i];
        pool.insert({mn[i], i});
    }

    for(int i = 0;i < m;i++) {
        int x, y;
        ll w;
        cin >> x >> y >> w;
        ed.insert({w, {x, y}});
    }

    ll result = 0;

    while(cc > 1) {

        while(!ed.empty() && find(ed.begin()->second.first) == find(ed.begin()->second.second)) {
            ed.erase(ed.begin());
        }

        int u = pool.begin()->second;
        int v = (++pool.begin())->second;

        if(ed.empty() || mn[u] + mn[v] <= ed.begin()->first) {
            result += mn[u] + mn[v];
            merge(u, v);
        }else {
            merge(ed.begin()->second.first, ed.begin()->second.second);
            result += ed.begin()->first;
        }
    }

    cout << result << "\n";

    return 0;
}