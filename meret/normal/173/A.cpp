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

int t1[1005 * 1005];
int t2[1005 * 1005];

int n, m, k;

char a[1005], b[1005];

int no[255];

int calc(int* t) {
    int len = m * k;
    int result = t[len - 1] * (n / len);
    if (n % len != 0) {
        result += t[n % len - 1];
    }
    return result;
}

int main() {
    no['R'] = 0;
    no['P'] = 1;
    no['S'] = 2;
    scanf("%d", &n);
    scanf("%s %s", a, b);
    m = strlen(a);
    k = strlen(b);
    int len = m * k;
    for (int i = 0; i < len; ++i) {
        t1[i] = (i > 0 ? t1[i - 1] : 0);
        t2[i] = (i > 0 ? t2[i - 1] : 0);
        if (a[i % m] != b[i % k]) {
            if (no[a[i % m]] == (no[b[i % k]] + 1) % 3) {
                ++t2[i];
            } else {
                ++t1[i];
            }
        }
    }
    printf("%d %d\n", calc(t1), calc(t2));
}