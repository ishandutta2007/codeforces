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

int size[100005];
int p[100005];

int gp(int x) {
    if (p[x] != x) {
        p[x] = gp(p[x]);
    }
    return p[x];
}

int n, m, k;

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
    }
    for (int i = 1; i <= m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        p[gp(a)] = gp(b);
    }
    for (int i = 1; i <= n; ++i) {
        ++size[gp(i)];
    }
    int result = 1;
    int components = 0;
    for (int i = 1; i <= n; ++i) {
        if (p[i] == i) {
            ++components;
            result = (result * (LL) size[i]) % k;
        }
    }
    if (components == 1) {
        result = 1 % k;
    } else {
        for (int i = 0; i < components - 2; ++i) {
            result = (result * (LL) n) % k;
        }
    }
    printf("%d\n", result);
}