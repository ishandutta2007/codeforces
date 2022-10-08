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
    int n;
    cin >> n;
    vector<PII> figures(n);
    for (int i = 0; i < n; ++i) {
        cin >> figures[i].ND >> figures[i].ST;
    }
    int t;
    cin >> t;
    vector<LL> levels(t);
    for (int i = 0; i < t; ++i) {
        cin >> levels[i];
    }
    sort(ALL(figures));
    int lev = 1;
    LL result = 0;
    LL destroyed = 0;
    for (int i = 0; i < n; ++i) {
        while (figures[i].ND > 0) {
            LL rem = figures[i].ND;
            if (lev <= t) {
                rem = min(rem, levels[lev - 1] - destroyed);
            }
            figures[i].ND -= rem;
            result += lev * rem * figures[i].ST;
            destroyed += rem;
            if (lev <= t && levels[lev - 1] == destroyed) {
                ++lev;
            }
        }
    }
    cout << result << "\n";
}