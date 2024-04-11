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

vector<PII> res;

int t[21];
int s[21];
int cnt[21];

int n;

void mv(int x, int dest) {
	for (int i = 0; i < t[x]; ++i)
		res.PB(MP(s[x], dest));
	++cnt[x];
	s[x] = dest;
}

void go(int x, int dest) {
	if (x == n)
		return;
	go(x + 1, 3 - dest - s[x]);
	mv(x, dest);
	go(x + 1, dest);
}

int main() {
	int disks;
	scanf("%d", &disks);
	res.reserve((1 << disks) + 5);
	int prev = -1;
	for (int i = 0; i < disks; ++i) {
		int cur;
		scanf("%d", &cur);
		if (cur != prev)
			++n;
		++t[n - 1];
		prev = cur;
	}
	int cr = 0;
	for (int i = 0; i < n - 1; ++i)
		if (t[i] > 1 && cnt[i] % 2 == 0) {
			go(i + 1, 2);
			mv(i, 1 - cr);
			go(i + 1, cr);
			mv(i, 2);
		} else {
			go(i + 1, 1 - cr);
			mv(i, 2);
			cr = 1 - cr;
		}
	if (cnt[n - 1] % 2 == 0) {
		for (int i = 0; i < t[n - 1] - 1; ++i)
			res.PB(MP(cr, 1 - cr));
		res.PB(MP(cr, 2));
		for (int i = 0; i < t[n - 1] - 1; ++i)
			res.PB(MP(1 - cr, 2));
	} else {
		for (int i = 0; i < t[n - 1]; ++i)
			res.PB(MP(cr, 2));
	}
	printf("%d\n", SIZE(res));
	FOREACH (it, res)
		printf("%d %d\n", it->ST + 1, it->ND + 1);
}