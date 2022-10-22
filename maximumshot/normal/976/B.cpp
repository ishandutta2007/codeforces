#include <bits/stdc++.h>

using namespace std;

#define ALL(x) begin(x), end(x)
#define vec vector

typedef long long ll;
typedef unsigned int ui;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = ll(1e18);

void solve(ll n, ll m, ll k) {
    if(k < n) {
        cout << 1 + k << " 1\n";
        return;
    }

    k -= n;

    ll t = k / (m - 1);

    cout << n - t << " ";

    if(t % 2) {
        cout << m - k % (m - 1) << "\n";
    }else {
        cout << 2 + k % (m - 1) << "\n";
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ll n, m, k;

    cin >> n >> m >> k;

    solve(n, m, k);

//    n = 6;
//    m = 5;

//    for(k = 0;k < n * m;k++) {
//        solve(n, m, k);
//    }

    return 0;
}