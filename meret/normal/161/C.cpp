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

int calc(int l1, int r1, int l2, int r2, int step) {
    if (r1 < l1 || r2 < l2) {
        return 0;
    } else if (r1 == r2) {
        return r1 - max(l1, l2) + 1;
    } else if (l1 == l2) {
        return min(r1, r2) - l1 + 1;
    } else if (step == 1) {
        return 1;
    } else {
        int result = 0;
        int mid = (1 << (step - 1));
        if (l1 <= mid && l2 <= mid && r1 >= mid && r2 >= mid) {
            result = min(r2, r1) - max(l1, l2) + 1;
            if ((l1 <= l2 && r1 >= r2) || (l2 <= l1 && r2 >= r1)) {
                return result;
            }
        }
        if (l1 < mid && r2 > mid) {
            result = max(result, calc(l1, min(mid - 1, r1), max(mid + 1, l2) - mid, r2 - mid, step - 1));
        }
        if (l2 < mid && r1 > mid) {
            result = max(result, calc(l2, min(mid - 1, r2), max(mid + 1, l1) - mid, r1 - mid, step - 1));
        }
        if (l1 < mid && l2 < mid) {
            result = max(result, calc(l1, min(mid - 1, r1), l2, min(mid - 1, r2), step - 1));
        }
        if (r1 > mid && r2 > mid) {
            result = max(result, calc(max(mid + 1, l1) - mid, r1 - mid, max(mid + 1, l2) - mid, r2 - mid, step - 1));
        }
        return result;
    }
}

int main() {
    int l1, r1, l2, r2;
    scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
    printf("%d\n", calc(l1, r1, l2, r2, 30));
}