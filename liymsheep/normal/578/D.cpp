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
#define REPI(i,n) for(i=0;i<n;i++)
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

const int N = 1000007;

char s[N];

int n;
LL dp[4][2][2][2][2];

int dp1[4], dp2[4];
void go(int i, int* dp, int* ndp, char c) {
    FILL(dp1, -1);
    if (dp[0]) dp1[0] = i;
    if (dp[1]) dp1[1] = i;
    if (dp[2]) dp1[2] = i - 1;
    if (dp[3]) dp1[3] = i - 1;

    FILL(dp2, -1);
    REP(j, 4) {
        if (dp1[j] == -1) continue;
        int index = i;
        if (j == 2) {
            index = i - 1;
        } else if (j == 1) {
            index = i + 1;
        }

        if (index < n && s[index] == c) {
            dp2[j] = max(dp2[j], dp1[j] + 1);
            continue;
        }
        if (j % 2 == 0) {
            dp1[j + 1] = max(dp1[j + 1], dp1[j]);
        }
        if (j / 2 == 0) {
            dp2[j + 2] = max(dp2[j + 2], dp1[j]);
        }
    }

    REP(i, 4) ndp[i] = 0;
    ndp[0] = (dp2[0] == i + 1);
    ndp[1] = (dp2[1] == i + 1);
    ndp[2] = (dp2[2] == i);
    ndp[3] = (dp2[3] == i);
}

int main() {
    int m;
    cin >> n >> m;
    scanf("%s", s);
    dp[0][1][0][0][0] = 1;
    LL answer = 0;
    for (int i = 0; i < n; ++i) {
        FILL(dp[(i + 1) & 1], 0);
        vector<char> d;
        for (int k = -1; k <= 1; ++k) {
            if (i + k >= 0 && i + k < n) {
                d.PB(s[i + k]);
            }
        }
        d.PB(0);
        SORT(d);
        d.erase(unique(ALL(d)), d.end());

        int p[4], np[4];
        REPI(p[0], 2) REPI(p[1], 2) REPI(p[2], 2) REPI(p[3], 2) {
            LL current = dp[i & 1][p[0]][p[1]][p[2]][p[3]];
            if (!current) {
                continue;
            }
            TR(it, d) {
                go(i, p, np, *it);
                int ways = 1;
                if (!*it) ways = m + 1 - d.size();
                dp[(i + 1) & 1][np[0]][np[1]][np[2]][np[3]] += current * ways;
            }
        }
    }
    REP(i, 2) REP(j, 2) REP(k, 2) REP(r, 2) if (i || j || k || r) answer += dp[n & 1][i][j][k][r];
    cout << answer - 1 << endl;
    return 0;
}