
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<LL> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> l(m), r(m), val(m);
    for (int i = 0; i < m; ++i) {
        cin >> l[i] >> r[i] >> val[i];
    }
    vector<int> added(m + 1);
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        ++added[x - 1];
        --added[y];
    }
    vector<LL> added2(n + 1);
    int cur = 0;
    for (int i = 0; i < m; ++i) {
        cur += added[i];
        added2[l[i] - 1] += cur * (LL) val[i];
        added2[r[i]] -= cur * (LL) val[i];
    }
    LL cur2 = 0;
    for (int i = 0; i < n; ++i) {
        cur2 += added2[i];
        a[i] += cur2;
        cout << a[i] << " \n"[i == n - 1];
    }
}