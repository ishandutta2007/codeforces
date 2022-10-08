#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FORE(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

const int MD = (int) 1e9 + 7;

int dp[105][2605];

int main() {
    dp[0][0] = 1;
    for (int i = 1; i <= 100; ++i) {
        for (int j = 0; j < 26; ++j) {
            for (int k = 0; k <= 26 * (i - 1); ++k) {
                dp[i][k + j] = (dp[i][k + j] + dp[i - 1][k]) % MD;
            }
        }
    }
    int d;
    scanf("%d", &d);
    while (d--) {
        static char s[105];
        scanf("%s", s);
        int sum = 0;
        int len = strlen(s);
        for (int i = 0; i < len; ++i) {
            sum += s[i] - 'a';
        }
        printf("%d\n", (dp[len][sum] + MD - 1) % MD);
    }
}