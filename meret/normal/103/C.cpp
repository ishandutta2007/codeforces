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

//judgement failed?

int main() {
	LL n, k;
	int p;
	cin >> n >> k >> p;
	bool empty = (k == 0);
	if (n % 2) {
		--n;
		--k;
	}
	while (p--) {
		LL slot;
		cin >> slot;
		if (empty) {
			putchar('.');
		} else if (slot > n) {
			putchar('X');
		} else if (slot % 2 == 0) {
			if (k > (n - slot) / 2)
				putchar('X');
			else
				putchar('.');
		} else {
			if (k > n / 2 + (n - slot - 1) / 2)
				putchar('X');
			else
				putchar('.');
		}
	}
	putchar('\n');
}