#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-12;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long LL;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

const int MOD = 1000000007;

int main() {
    LL l;
    int n, k;
    cin >> n >> l >> k;
    vector<int> a(n);
    REP(i, n) {
        scanf("%d", &a[i]);
    }

    VI b = a;
    SORT(b);
    b.erase(unique(ALL(b)), b.end());
    REP(i, n) {
        a[i] = lower_bound(ALL(b), a[i]) - b.begin();
    }

    VI dp(b.size());
    VI ndp(b.size());

    fill(ALL(dp), 1);
    LL ans = 0;
    for (int p = 1; p <= k; ++p) {
        LL parts = l / n;
        LL full = (parts - p + 1) % MOD;

        // cout << "FULL = " << full << endl;
        if (parts - p + 1 < 0) continue;

        fill(ALL(ndp), 0);
        for (int j = 0; j < n; ++j) {
            if (j == l % n) {
                REP(k, dp.size()) ans = (ans + ndp[k]) % MOD;
            }
            ndp[a[j]] = (ndp[a[j]] + dp[a[j]]) % MOD;
        }
        REP(k, dp.size()) {
            ans = (ans + ndp[k] * full) % MOD;
        }
        for (int i = 1; i < dp.size(); ++i) {
            ndp[i] = (ndp[i] + ndp[i - 1]) % MOD;
        }
        swap(dp, ndp);
    }
    // REP(i, n) cout << dp[i] << endl;
    cout << ans << endl;
    return 0;
}