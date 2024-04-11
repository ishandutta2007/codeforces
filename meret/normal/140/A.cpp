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

double pi;

bool ok(int n, double R, double r) {
    if (n == 1) {
        return R >= r - 1e-9;
    } else if (R <= 2 * r - 1e-9) {
        return false;
    } else if (R <= 2 * r + 1e-9) {
        return n == 2;
    }
    return 2 * n * asin(r / (R - r)) <= 2 * pi + 1e-9;
}

int main() {
    pi = 2 * acos(0);
    int n;
    double R, r;
    scanf("%d %lf %lf", &n, &R, &r);
    printf(ok(n, R, r) ? "YES\n" : "NO\n");

}