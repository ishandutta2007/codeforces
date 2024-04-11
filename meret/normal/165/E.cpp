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

const int N = (int) 1e6 + 5;
const int M = (1 << 22);

int t[N];
int any[M + 5];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &t[i]);
        any[(M - 1) & (~t[i])] = t[i];
    }
    for (int i = M - 1; i >= 1; --i) {
        if (any[i]) {
            for (int j = 0; j < 22; ++j) {
                if ((i >> j) & 1) {
                    any[i ^ (1 << j)] = any[i];
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (any[t[i]]) {
            printf("%d", any[t[i]]);
        } else {
            printf("-1");
        }
        if (i < n) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
}