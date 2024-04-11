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

const int mod = inf + 7;

int binpow(int x, int p) {
    int res = 1;
    int tmp = x;
    while(p > 0) {
        if(p & 1) {
            res = (1ll * res * tmp) % mod;
        }
        p >>= 1;
        tmp = (1ll * tmp * tmp) % mod;
    }
    return res;
}

inline void _add(int &x, int y) {
    if((x += y) >= mod) x -= mod;
}

vector< int > get(int n, int k) {
    vector< int > dp(n + 1);
    dp[n] = 1;
    for(int iter = 0;iter < k;iter++) {
        vector< int > nx(n + 1);
        for(int i = n;i >= 0;i--) {
            int cf = binpow(i + 1, mod - 2);
            for(int j = i;j >= 0;j--) {
                _add(nx[j], (1ll * cf * dp[i]) % mod);
            }
        }
        dp = nx;
    }
    return dp;
}

void rec(const vector< vector< int > > &vl, const vector< vector< int > > &P, vector< int > &st, int i, int &res) {
    if(i == (int)vl.size()) {
        int pr = 1;
        int val = 1;
        for(int i = 0;i < (int)vl.size();i++) {
            pr = (1ll * pr * P[i][ st[i] ]) % mod;
            val = (1ll * val * vl[i][ st[i] ]) % mod;
        }
        _add(res, (1ll * pr * val) % mod);
        return;
    }
    for(int j = 0;j < vl[i].size();j++) {
        st.push_back(j);
        rec(vl, P, st, i + 1, res);
        st.pop_back();
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ll n;
    int k;

    cin >> n >> k;

    vector< ll > dv;

    for(ll p = 2;p * p <= n;p++) {
        if(n % p) continue;
        dv.push_back(p);
        n /= p;
        p--;
    }

    if(n > 1) dv.push_back(n);

    sort(dv.begin(), dv.end());

    vector< pair< ll, int > > ar;

    for(int i = 0;i < (int)dv.size();i++) {
        int j = i;
        while(j < (int)dv.size() && dv[i] == dv[j]) j++;
        j--;
        ar.push_back({dv[i], j - i + 1});
        i = j;
    }

    vector< vector< int > > P((int)ar.size());

    for(int i = 0;i < (int)ar.size();i++) {
        P[i] = get(ar[i].second, k);
    }

    vector< vector< int > > vl((int)ar.size());

    for(int i = 0;i < (int)ar.size();i++) {
        vl[i].resize(ar[i].second + 1);
        ll value = 1;
        for(int j = 0;j <= ar[i].second;j++) {
            vl[i][j] = value;
            value = (value * ar[i].first) % mod;
        }
    }

    vector< int > st;
    int res = 0;
    rec(vl, P, st, 0, res);

    printf("%d\n", res);

    return 0;
}