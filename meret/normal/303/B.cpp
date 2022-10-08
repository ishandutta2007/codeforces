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
#define SZ(x) (int)(x).size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

int gcd(int a, int b) {
    while (a && b) {
        a > b ? a %= b : b %= a;
    }
    return a + b;
}

int n, m, x, y;
int sx, sy;

LL dist(int x1, int y1) {
    LL dx = 2 * (LL) x1 + (LL) sx - 2 * (LL) x;
    LL dy = 2 * (LL) y1 + (LL) sy - 2 * (LL) y;
    return dx * dx + dy * dy;
}

bool check(int x1, int y1) {
    return x1 <= x && x1 + sx >= x && y1 <= y && y1 + sy >= y && x1 + sx <= n && y1 + sy <= m && x1 >= 0 && y1 >= 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int a, b;
    cin >> n >> m >> x >> y >> a >> b;
    int g = gcd(a, b);
    a /= g;
    b /= g;
    int coef = min(n / a, m / b);
    sx = coef * a;
    sy = coef * b;
    pair<LL, PII> res = MP((LL) ((1ULL << 63) - 1), MP(0, 0));
    vector<PII> options;
    vector<int> xs;
    xs.PB(0);
    xs.PB(n - sx);
    xs.PB(x - sx / 2);
    xs.PB(x - sx / 2 - 1);
    vector<int> ys;
    ys.PB(0);
    ys.PB(m - sy);
    ys.PB(y - sy / 2);
    ys.PB(y - sy / 2 - 1);
    FORE (it, xs) {
        FORE (jt, ys) {
            if (check(*it, *jt)) {
                res = min(res, MP(dist(*it, *jt), MP(*it, *jt)));
            }
        }
    }
    cout << res.ND.ST << " " << res.ND.ND << " " << res.ND.ST + sx << " " << res.ND.ND + sy << endl;
}