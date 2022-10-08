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
#define SZ(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

set<PII> res;

void divide(vector<PII> v) {
	if (SZ(v) < 2)
		return;
	sort(ALL(v));
	int x = v[SZ(v) / 2].ST;
	vector<PII> left, right;
	FOREACH (it, v) {
		res.insert(MP(x, it->ND));
		if (it->ST < x)
			left.PB(*it);
		else if(it->ST > x)
			right.PB(*it);
	}
	divide(left);
	divide(right);
}

int main() {
	int n;
	vector<PII> v;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		res.insert(MP(x, y));
		v.PB(MP(x, y));
	}
	divide(v);
	printf("%d\n", SZ(res));
	FOREACH (it, res)
		printf("%d %d\n", it->ST, it->ND);
}