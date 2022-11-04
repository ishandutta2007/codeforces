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
typedef long long LL;
typedef pair<LL,LL> PII;
typedef long long int64;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

const int N = 507;
const int MODULO = 1000000007;

LL dp[N][N];
LL p2[N * N];

int main() {
    p2[0] = 1;
    for (int i = 1; i < N * N; ++i) {
        p2[i] = p2[i - 1] * 2 % MODULO;
    }

    int n, k;
    cin >> n >> k;
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            for (int t = 0; t < i; ++t) {
                if (!dp[t][j - 1]) {
                    continue;
                }
                int extra = t * (i - t);
                dp[i][j] = (dp[i][j] 
                    + dp[t][j - 1] * p2[extra] % MODULO * (p2[i - t] - 1)) % MODULO;
            }
        }
    }

    LL ans = 0;
    for (int i = 0; i <= n; ++i) {
        if (!dp[i][k]) {
            continue;
        }
        int extra = i * (n - i);
        ans = (ans + dp[i][k] * p2[extra]) % MODULO;
    }
    ans = (ans + MODULO) % MODULO;
    cout << ans << endl;
    return 0;
}