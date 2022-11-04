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

#include <unordered_set>

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

const int I_INF = 0x7FFFFFFF;
const LL INF = 2100000000LL * 2100000000LL;

int dp[2][11];

int main(){
    int n, k;
    cin >> n >> k;
    VI xs(n);
    VI ys(n);
    vector<PII> p(n);
    REP(i, n) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        p[i] = MP(a + c, b + d);
        xs[i] = a + c;
        ys[i] = b + d;
    }
    SORT(p);
    SORT(xs); SORT(ys);
    LL ans = INF;
    // cout << 0x3F3F3F3F << endl;
    for (int u = 0; u < xs.size() && u <= k; ++u) {
        if (u && xs[u] == xs[u - 1]) continue;
        for (int v = 0; v < ys.size() && v <= k; ++v) {
            if (v && ys[v] == ys[v - 1]) continue;

            int x_threshold = xs[u];
            int y_threshold = ys[v];

            REP(i, k + 1) dp[0][i] = I_INF;
            dp[0][0] = 0;
            REP(i, n + 1) {
                int now = i & 1;
                int next = now ^ 1;
                // FILL(dp[next], 0x3F);
                REP(j, k + 1) dp[next][j] = I_INF;
                REP(j, k + 1) {
                    if (dp[now][j] == I_INF) {
                        continue;
                    }
                    if (i < n && p[i].first >= x_threshold && p[i].second >= y_threshold) {
                        dp[next][j] = min(dp[next][j], max(p[i].second, dp[now][j]));
                    }
                    if (i < n && j + 1 <= k) {
                        dp[next][j + 1] = min(dp[next][j + 1], dp[now][j]);
                    }
                    if (i && i - 1 + (k - j) >= n - 1 && p[i - 1].first >= x_threshold) {
                        int a = p[i - 1].first - x_threshold;
                        if (!a) a = 2;
                        int b = dp[now][j] - y_threshold;
                        if (!b) b = 2;
                        if (a & 1) ++a;
                        if (b & 1) ++b;
                        ans = min(ans, a * (LL) b);
                        // cout << a << ", " << b << endl;
                        // if ((p[i].first - x_threshold) * (LL) (dp[now][j] - y_threshold) == 0) {
                        //     cout << "i is " << i << " j is " << j << endl;
                        // }
                    }
                }
            }
        }
    }
    assert(ans % 4 == 0);
    cout << ans / 4 << endl;
    return 0;
}