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

int p[2005];

int gp(int x) {
    if (p[x] != x) {
        p[x] = gp(p[x]);
    }
    return p[x];
}

void un(int a, int b) {
    a = gp(a);
    b = gp(b);
    if (a != b) {
        p[a] = b;
    }
}

const int MD = (int) 1e9 + 7;

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
    }
    for (int i = 1; i + k - 1 <= n; ++i) {
        for (int j = 0; j < k; ++j) {
            un(i + j, i + k - 1 - j);
        }
    }
    int res = 1;
    for (int i = 1; i <= n; ++i) {
        if (p[i] == i) {
            res = (res * (LL) m) % MD;
        }
    }
    printf("%d\n", res);
}