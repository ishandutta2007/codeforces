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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(ALL(a));
    reverse(ALL(a));
    vector<LL> sum(n + 1);
    sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + a[i - 1];
    }

    LL result_1 = 0;
    for (int i = 0; i < n; ++i) {
        result_1 += a[i] * (LL) i;
    }

    int n_queries;
    cin >> n_queries;
    for (int i = 0; i < n_queries; ++i) {
        int k;
        cin >> k;
        LL result;
        if (k == 1) {
            result = result_1;
        } else {
            result = 0;
            LL sz = 1;
            int level = 0;
            LL l = 0;
            while (l < n) {
                result += level * (sum[min((LL) n, l + sz)] - sum[l]);
                l += sz;
                ++level;
                sz *= k;
            }
        }
        cout << result;
        if (i + 1 < n_queries) {
            cout << " ";
        }
    }
    cout << endl;
}