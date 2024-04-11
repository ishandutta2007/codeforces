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

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<LL> vx, vy;
    LL area = 0;
    for (int i = 0; i < n; ++i) {
        LL x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        area += (x2 - x1) * (y2 - y1);
        vx.PB(x1);
        vx.PB(x2);
        vy.PB(y1);
        vy.PB(y2);
    }
    sort(ALL(vx));
    sort(ALL(vy));
    if (vy.back() - vy[0] == vx.back() - vx[0] && (vy.back() - vy[0]) * (vx.back() - vx[0]) == area) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}