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

int main() {
    int S, a, b, c;
    scanf("%d %d %d %d", &S, &a, &b, &c);
    if (a == 0 && b == 0 && c == 0) {
        printf("%d %d %d\n", S, 0, 0);
    } else {
        double va = a / (double) (a + b + c);
        double vb = b / (double) (a + b + c);
        double vc = c / (double) (a + b + c);
        printf("%.12lf %.12lf %.12lf\n", va * (S - 1e-12), vb * (S - 1e-12), vc * (S - 1e-12));
    }
}