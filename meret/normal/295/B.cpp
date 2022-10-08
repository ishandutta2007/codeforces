
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
    vector<vector<LL> > e(n, vector<LL>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> e[i][j];
        }
        e[i][i] = 0;
    }
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        --x[i];
    }
    vector<LL> results;
    vector<char> added(n, false);
    for (int i = n - 1; i >= 0; --i) {
        added[x[i]] = true;
        LL cur = 0;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                e[j][k] = min(e[j][k], e[j][x[i]] + e[x[i]][k]);
                if (added[j] && added[k]) {
                    cur += e[j][k];
                }
            }
        }
        results.PB(cur);
    }
    reverse(ALL(results));
    FORE (it, results) {
        cout << *it << " \n"[it + 1 == results.end()];
    }
}