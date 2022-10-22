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

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, m;

    cin >> n >> m;

    vector<ll> cnt(n + 1);
    vector<ll> mn(n + 1, inf);

    for(int i = 0;i < m;i++) {
        ll a, b;
        cin >> a >> b;
        if(b < a) b += n;
        cnt[a]++;
        mn[a] = min(mn[a], b);
    }

    for(int s = 1;s <= n;s++) {
        ll res = s;
        for(ll a = 1;a <= n;a++) {
            if(cnt[a] == 0) continue;
            ll b = mn[a];
            if(a < s)  {
                b += n;
            }
            res = max(res, b + (cnt[a] - 1) * n);
        }
        cout << max(0ll, res - s) << " ";
    }

    cout << "\n";

    return 0;
}