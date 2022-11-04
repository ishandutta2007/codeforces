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
#include <unordered_map>

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

const int N = 5007;

const int MODULO = 1000000007;

int delta[N][N];

int cur[N];

int dp[N][N];

char d[N];

int first[N][N];

int main() {
    int n;
    cin >> n;
    cin >> d;
    FILL(first, -1);
    for (int j = n - 1; j >= 0; --j) {
        for (int i = j - 1; i >= 0; --i) {
            if (d[i] != d[j]) {
                first[i][j] = 0;
            } else {
                first[i][j] = first[i + 1][j + 1];
                if (first[i][j] >= 0) {
                    ++first[i][j];
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        dp[0][i] = 1;
    }

    for (int length = 1; length <= n; ++length) {
        for (int i = 0; i + length - 1 < n; ++i) {
            int j = i + length - 1;
            cur[i] += delta[i][j];
            if (cur[i] >= MODULO) {
                cur[i] -= MODULO;
            }

            dp[i][j] += cur[i];
            if (dp[i][j] >= MODULO) {
                dp[i][j] -= MODULO;
            }

            if (!dp[i][j]) {
                continue;
            }

            int p = j + 1, q = j + 1 + j - i;
            if (q >= n || d[p] == '0') {
                continue;
            }

            bool canEquals = true;
            int f = first[i][j + 1];
            if (f < 0 || f > j - i || d[i + f] > d[j + 1 + f]) {
                canEquals = false;
            }

            if (canEquals) {
                delta[p][q] += dp[i][j];
                if (delta[p][q] >= MODULO) {
                    delta[p][q] -= MODULO;
                }
            } else if (q + 1 < n) {
                delta[p][q + 1] += dp[i][j];
                if (delta[p][q + 1] >= MODULO) {
                    delta[p][q + 1] -= MODULO;
                }
            }
        }
    }
    int ans = 0;
    REP(i, n) {
        ans += dp[i][n - 1];
        if (ans >= MODULO) {
            ans -= MODULO;
        }
    }

    cout << ans << endl;
    return 0;
}