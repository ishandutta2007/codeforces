#include <sstream>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <map>
#include <set>

#define MOD 998244353
#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
ll dp[505][505], a[505];
ll n, m, i, j, k, x, y, z;
vector<pii> f;
ll get(ll x, ll y) {
    if (x > y) {
        return 1;
    }
    return dp[x][y];
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) {
                dp[i][j] = 1;
            }
        }
    }
    ll x = 0;
    ll tot = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j + i < n; j++) {
            ll mn = n + 5, mn_i = 1;
            for (int k = j; k <= j+i; k++) {
                if (a[k] < mn) {
                    mn = a[k];
                    mn_i = k;
                }
            }
            //cout << j << " " << i+j << " " << mn_i << endl;
            ll sum1 = 0, sum2 = 0;
            for (int k = j; k <= mn_i; k++) {
                sum1 = (sum1 + get(k, mn_i - 1) * get(j, k - 1)) % MOD;
            }
            for (int l = mn_i; l <= j+i; l++) {
                sum2 = (sum2 + get(l+1,j+i) * get(mn_i + 1, l)) % MOD;
            }
            dp[j][i+j] = sum1 * sum2 % MOD;
            //cout << j << " " << i+j << " " << dp[j][i+j] << endl;
        }
    }
    cout << dp[0][n-1] << endl;
    return 0;
}