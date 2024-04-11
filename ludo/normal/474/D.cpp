#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MOD 1000000007
#define MAX 100000

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll dp[MAX + 1], st[MAX + 1];
// pll st[MAX + 1];
pii q[MAX];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    int t, k, mk = 0;
    cin >> t >> k;
    for (int i = 0; i < t; i++) {
        cin >> q[i].first >> q[i].second;
        if (q[i].second > mk) {
            mk = q[i].second;
        }
    }

    // populate segment tree
    for (int i = 0; i < k; i++) {
        dp[i] = 1;
        st[i] = i + 1;
    }
    for (int i = k; i <= mk; i++) {
        dp[i] = (dp[i - 1] + dp[i - k]) % MOD;
        st[i] = (st[i - 1] + dp[i]) % MOD;
    }

//    for (int i = 0; i <= mk; i++) {
//        cerr << i << ":\t" << st[i] << endl;
//    }

//    for (int i = 0; i < k; i++) {
//        st[0].first = 1;
//        st[0].second = 0;
//    }
//    st[0].first = 0;
//
//    for (int i = k; i <= mk; i++) {
//        st[i].second = LIM(st[i - k].first)
//        st[1][i] = LIM(st[1][i - k] + st[0][i - 1]);
//        st[0][i] = LIM(st[0][i - 1] + st[1][i - 1]);
//
//        cerr << i << ": " << st[1][i] << ", " << st[0][i] << endl;
//    }

    // print answers
    for (int i = 0; i < t; i++) {
        ll ans = (st[q[i].second] - st[q[i].first - 1]);
        while (ans < 0) ans += MOD;
        cout << ans << endl;
        // cout << (st[1][b] + st[0][b] - st[1][a - 1] - st[0][a - 1]) << endl;
    }

    return 0;
}