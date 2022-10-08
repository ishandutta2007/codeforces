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

const int MD = (int) 1e9 + 7;

int main() {
    LL n;
    cin >> n;
    LL res = 1;
    LL p2 = 2;
    for (; n > 0; n >>= 1) {
        if (n & 1) {
            res = (res * p2) % MD;
        }
        p2 = (p2 * p2) % MD;
    }
    res = (res * (res + 1)) % MD;
    res = (res * (LL) ((MD + 1) / 2)) % MD;
    cout << res << endl;
}