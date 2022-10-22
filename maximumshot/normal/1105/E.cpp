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
const int M = 40;

int n, m;
string s[M];
int sz;
pii query[N];
ll g[M];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    if(m == 1) {
        cout << "1\n";
        return 0;
    }

    gp_hash_table< string, int > mp;
    for(int iter = 0;iter < n;iter++) {
        int type;
        cin >> type;
        if(type == 1) {
            query[iter] = {1, -1};
            continue;
        }
        string tmp;
        cin >> tmp;
        auto fnd = mp.find(tmp);
        int pos;
        if(fnd == mp.end()) {
            s[sz] = tmp;
            mp[tmp] = pos = sz++;
        }else {
            pos = fnd->second;
        }
        query[iter] = {2, pos};
    }

    for(int i = 0;i < n;i++) {
        if(query[i].first == 1) continue;
        int j = i;
        set< int > qq;
        while(j < n && query[j].first == 2) {
            qq.insert( query[j].second );
            j++;
        }
        for(int u : qq) {
            for(int v : qq) {
                if(s[u] != s[v]) {
                    g[u] |= (1ll << v);
                    g[v] |= (1ll << u);
                }
            }
        }
        i = j - 1;
    }

    assert(sz == m);

    int res = 0;

    int m1 = m / 2;
    int m2 = m - m1;

    int M1 = 1 << m1;
    int M2 = 1 << m2;

    vector< int > dp(M2), I(M1);

    I[0] = 1;
    for(int mask = 1;mask < M1;mask++) {
        int x = __lg(mask);
        if(g[x] & mask) {
            continue;
        }
        I[mask] = I[mask ^ (g[x] & mask) ^ (1 << x)];
        if(I[mask]) {
            res = max(res, __builtin_popcount(mask));
        }
    }

    for(int mask = 1;mask < M2;mask++) {
        int x = __lg(mask);
        dp[mask] = max(dp[mask ^ (1 << x)], 1 + dp[ mask ^ (1 << x) ^ ((g[m1 + x] >> m1) & mask) ]);
    }

//    for(int mask = 0;mask < M2;mask++) {
//        cout << mask << " : " << dp[mask] << "\n";
//    }

    res = max(res, *max_element(dp.begin(), dp.end()));

    for(int mask = 0;mask < M1;mask++) {
        if(!I[mask]) continue;
        ll o = 0;
        for(int u = 0;u < m1;u++) {
            if((1 << u) & mask) o |= g[u];
        }
        o >>= m1;
        res = max(res, __builtin_popcount(mask) + dp[(M2 - 1) ^ o]);
    }

    cout << res << "\n";

    return 0;
}