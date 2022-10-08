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

int fl(int x, int y) {
	if (x >= 0) {
		return x / y;
	} else {
		return - ((-x + LL(y - 1)) / y);
	}
}

int main() {
	int x1, y1, x2, y2;
	int a, b;
	cin >> a >> b >> x1 >> y1 >> x2 >> y2;
	int d1a = fl(x1 + y1, (2 * a));
	int d1b = fl(x1 - y1, (2 * b));
	int d2a = fl(x2 + y2, (2 * a));
	int d2b = fl(x2 - y2, (2 * b));
	cout << max(abs(d1a - d2a), abs(d1b - d2b)) << endl;
}