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

const int N = 500005;

int n;

int x[N], v[N];

int initial[N];
int current[N];

bool check(double c) {
	double r = -1E50;
	for (int i = 0; i < n; ++i) {
		if (v[i] > 0)
			r = max(r, x[i] + c * v[i]);
		else if (r >= x[i] + c * v[i])
			return true;
	}
	return false;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d %d", &x[i], &v[i]);
	double l = 0, r = 2E10;
	if (!check(r)) {
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < 100; ++i) {
		double c = (l + r) / 2.0;
		if (check(c))
			r = c;
		else
			l = c;
	}
	printf("%.10lf\n", l);
}