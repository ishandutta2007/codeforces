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

const int N = 1007;
const int M = 1007;

double dp[2][M * M + M];

int main(){
    int n, m;
    cin >> n >> m;
    if (m == 1) {
        cout << 1 << endl;
        return 0;
    }

    int sum = 0;

    dp[0][0] = 1.0;
    for (int i = 0; i < n; ++i) {
        int now = i & 1;
        int next = now ^ 1;

        int x;
        scanf("%d", &x);

        sum += x;

        CLEAR(dp[next]);
        double pr = 1.0 / (m - 1);
        double current = 0.0;

        for (int j = 0; j <= (i + 1) * m; ++j) {
            dp[next][j] = current;
            current += dp[now][j] * pr;
            if (j - m >= 0) {
                current -= dp[now][j - m] * pr;
            }
        }

        // REP(j, (i + 1) * m + 1) cout << dp[next][j] << " ";
        // cout << endl;

        for (int j = 0; j <= (i + 1) * m; ++j) {
            if (j - x >= 0) {
                dp[next][j] -= dp[now][j - x] * pr;
            }
        }

        // REP(j, (i + 1) * m + 1) cout << dp[next][j] << " ";
        // cout << endl;
    }

    double res = 0.0;
    for (int i = 0; i < sum; ++i) {
        res += dp[n & 1][i];
    }
    res *= m - 1.0;
    res += 1.0;

    printf("%.12f\n", res);
    return 0;
}