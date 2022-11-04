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

int dp[2][151][151 * 151];

int main() {
    int k, n, s;
    cin >> n >> k >> s;
    vector<int> a(n);
    REP(i, n) {
        scanf("%d", &a[i]);
    }

    s = min(s, (n - 1 + 0) * n / 2);

    FILL(dp, 0x3f);
    dp[0][0][0] = 0;
    REP(i, n) {
        int now = i & 1;
        int next = now ^ 1;
        REP(u, k + 1) REP(v, s + 1) dp[next][u][v] = 0x3f3f3f3f;
        REP(u, k + 1) REP(v, s + 1) {
            if (dp[now][u][v] == 0x3f3f3f3f) continue;
            if (u + 1 <= k) {
                dp[next][u + 1][v] = min(dp[next][u + 1][v], dp[now][u][v] + a[i]);
            }
            if (v + (k - u) <= s) {
                dp[next][u][v + k - u] = min(dp[next][u][v + k - u], dp[now][u][v]);
            }
        }
    }
    int ans = 0x3f3f3f3f;
    REP(i, s + 1) ans = min(ans, dp[n & 1][k][i]);
    cout << ans << endl;
    return 0;
}