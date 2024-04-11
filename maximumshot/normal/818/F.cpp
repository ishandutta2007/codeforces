#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

ll f(ll l, ll n) {
    return l + min(l, (n - l) * (n - l - 1) / 2);
}

ll solve(int n) {
    ll res = n - 1;
    ll bl = 0;
    ll br = n - 3;
    ll bm1, bm2;
    while(br - bl > 2) {
        bm1 = bl + (br - bl) / 3;
        bm2 = br - (br - bl) / 3;
        if(f(bm1, n) < f(bm2, n)) {
            bl = bm1;
        }else {
            br = bm2;
        }
    }
    for(ll l = bl;l <= br;l++) {
        res = max(res, f(l, n));
    }
    return res;
}

int main() {

#ifdef maximumSHOT
//    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);

    int q;

    cin >> q;

    for(int n, iter = 0;iter < q;iter++) {
        cin >> n;
        cout << solve(n) << "\n";
    }

    return 0;
}