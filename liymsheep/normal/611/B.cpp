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

LL dp[66];

LL go(LL x) {
    dp[0] = 0;
    for (int i = 1; i <= 64; ++i) {
        dp[i] = dp[i - 1] + i - 1;
    }
    LL ans = 0;
    int ones = 0;
    for (LL i = 62; i >= 0; --i) {
        if ((x >> i) & 1LL) {
            ++ones;
            if (ones > 1) {
                ++ans;
            } else {
                ans += dp[i];
            }
        } else {
            if (!ones) {
                continue;
            }
            bool flag = true;
            for (int j = i - 1; j >= 0; --j) {
                if (((x >> j) & 1LL) == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ++ans;
            }

            break;
        }
    }
    return ans;
}

int main() {
    LL l, r;
    // cout << go(10) << endl;
    cin >> l >> r;
    cout << go(r) - go(l - 1) << endl;
    return 0;
}