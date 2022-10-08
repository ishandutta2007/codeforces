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
#define FOREACH(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

LL reflection(int x) {
        vector<int> digits;
        while (x) {
                digits.PB(x % 10);
                x /= 10;
        }
        reverse(ALL(digits));
        LL result = 0;
        FOREACH (it, digits)
                result = 10 * result + (9 - *it);
        return result;
}

LL value(int x) {
        return x * reflection(x);
}

int l, r;

int main() {
        scanf("%d %d", &l, &r);
        LL result = max(value(l), value(r));
        LL c = 5;
        for (int i = 0; i < 10; ++i) {
        	if (l <= c && c - 1 <= r)
        		result = max(result, value(c));
        	c *= 10;
        }
        cout << result << endl;
}