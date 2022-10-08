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

int dp[5005][5005];
int sum[5005][5005];

char s[5005];
char t[5005];
int n, m;

inline int mmd(int x) {
    return x >= MD ? x - MD : x;
}

int main() {
    scanf("%s %s", s + 1, t + 1);
    n = strlen(s + 1);
    m = strlen(t + 1);
    int result = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i] == t[j]) {
                dp[i][j] = mmd(1 + sum[i - 1][j - 1]);
            }
            sum[i][j] = mmd(sum[i][j - 1] + dp[i][j]);
            result = mmd(result + dp[i][j]);
        }
    }
    printf("%d\n", result);
}