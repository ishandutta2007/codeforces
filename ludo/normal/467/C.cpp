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

#define MAX 5000

typedef long long ll;
typedef pair<int, int> pii;

int n, m, k;
// ll p[MAX];
ll st[MAX + 1];

ll dp[MAX + 1] = {};
ll newdp[MAX + 1] = {};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    cin >> n >> m >> k;

    st[0] = 0;
    for (int i = 0; i < n; i++) {
        ll p; cin >> p;
        st[i + 1] = st[i] + p;
        // cin >> p[i];
        // st[i + 1] = st[i] + p[i];
    }

    for (int i = 0; i < k; i++) {

        for (int l = 0; l + m <= n; l++) {
            // check interval (l, l + m - 1)
            ll sum = st[l + m] - st[l];
            newdp[l + m] = max(newdp[l + m], sum + dp[l]);
        }

        ll best = 0;
        for (int j = 0; j <= n; j++) {
            best = max(best, newdp[j]);
            dp[j] = best;
            newdp[j] = 0;
//            cerr << dp[j] << " ";
        }
//        cerr << endl;
    }

    cout << dp[n] << endl;
    return 0;
}