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

char s[35];

int val(int l, int r) {
    if (s[l] == '0') {
        return (l == r) ? 0 : -1;
    } else {
        int x = 0;
        for (int i = l; i <= r; ++i) {
            x = 10 * x + s[i] - '0';
            if (x > (int) 1e6) {
                return -1;
            }
        }
        return x;
    }
}

int main() {
    scanf("%s", s);
    int result = -1;
    int n = strlen(s);
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int a = val(0, i - 1);
            int b = val(i, j - 1);
            int c = val(j, n - 1);
            if (a == -1 || b == -1 || c == -1) {
                continue;
            }
            result = max(result, a + b + c);
        }
    }
    printf("%d\n", result);

}