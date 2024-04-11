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
typedef long double LD;
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

int n;
LL l, v1, v2;

vector<pair<LD, int> > events;

LD res[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    cin >> l >> v1 >> v2;
    LD goodLen = (v2 / (LD) (v1 + v2)) * l;
    int val = 0;
    for (int i = 0; i < n; ++i) {
        LL cur;
        cin >> cur;
        events.PB(MP(cur - goodLen - 2 * l, 1));
        events.PB(MP((LD) (cur - 2 * l), -1));
        events.PB(MP(cur - goodLen, 1));
        events.PB(MP((LD) cur, -1));
        events.PB(MP(cur + 2 * l - goodLen, 1));
        events.PB(MP((LD) (cur + 2 * l), -1));
    }
    events.PB(MP(0LL, 0));
    events.PB(MP(2 * l, 0));
    sort(ALL(events));
    FORE (it, events) {
        if (it->ST >= -1e-10 && it->ST <= 2 * l + 1e-10) {
            if (it > events.begin() && (it - 1)->ST >= -1e-10) {
                res[val] += it->ST - (it - 1)->ST;
            }
        }
        val += it->ND;
    }
    for (int i = 0; i <= n; ++i) {
        printf("%.12lf\n", (double) ((res[i]) / (LD) (2 * l)));
    }
}