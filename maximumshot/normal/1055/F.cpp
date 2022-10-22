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

const int N = 1e6 + 5;
const int LOG = 62;
const int LG = 21;

int n;
int p[N];
ll w[N], k;
ll buf[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 2;i <= n;i++) {
        cin >> p[i] >> w[i];
        w[i] ^= w[ p[i] ];
    }

    sort(w + 1, w + n + 1);

    // [j .. LOG)
    auto calc = [&](int j, ll mask) -> ll {
        ll pattern = ((1ll << LOG) - 1) ^ ((1ll << j) - 1);
        for(int i = 1;i <= n;i++) {
            buf[i] = (pattern & w[i]) ^ mask;
        }
        sort(buf + 1, buf + n + 1);
        ll res = 0;
        for(int l = 1, r = 0, i = 1;i <= n;i++) {
            ll need = (w[i] & pattern);
            while(r <= n && buf[r] <= need) r++;
            while(l <= n && buf[l] <  need) l++;
            res += r - l;
        }
        return res;
    };

    ll res = 0;

    for(int j = LOG - 1;j >= 0;j--) {
        ll tmp = calc(j, res);
        if(tmp < k) {
            k -= tmp;
            res |= (1ll << j);
        }
    }

    cout << res << "\n";

    return 0;
}