#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long double, long double > pdd;
typedef pair< long long, long long > pll;

#define vec vector
#define ALL(x) begin(x), end(x)

const int inf = 1e9;
const ll inf64 = 1e18;

ll get(ll r, ll md, ll n) {
    // 1 <= r + t * md <= n
    if(r > n) return 0;
    ll rt = max(n - r, 0ll) / md;
    ll lt = (1 - r) / md;
    while(1 >  r + lt * md) lt++;
    while(1 <= r + lt * md) lt--;
    lt++;
    return max(0ll, rt - lt + 1);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ll res = 0;
    ll n, m;

    cin >> n >> m;

    for(int mi = 0;mi < m;mi++) {
        for(int mj = 0;mj < m;mj++) {
            if((1ll * mi * mi + 1ll * mj * mj) % m) continue;
            res += get(mi, m, n) * get(mj, m, n);
        }
    }

    cout << res << "\n";

    return 0;
}