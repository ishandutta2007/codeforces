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
    ios_base::sync_with_stdio(false);

    map<PII, int> markers;
    map<int, int> noColors;

    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        int color, diameter;
        cin >> color >> diameter;
        ++markers[MP(diameter, color)];
    }
    int matched = 0, beautiful = 0;
    for (int i = 1; i <= m; ++i) {
        int color, diameter;
        cin >> color >> diameter;
        if (markers[MP(diameter, color)] > 0) {
            ++matched;
            ++beautiful;
            --markers[MP(diameter, color)];
        } else {
            ++noColors[diameter];
        }
    }
    FORE (it, markers) {
        int closed = min(it->ND, noColors[it->ST.ST]);
        matched += closed;
        noColors[it->ST.ST] -= closed;
    }
    cout << matched << " " << beautiful << "\n";
}