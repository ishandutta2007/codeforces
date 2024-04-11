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

int n, k, A;

int loyalty[8], level[8];

double result = 0;

void go(int c, int candies) {
	if (c == n) {
		double loseChance = 0;
		for (int mask = 0; mask < (1 << n); ++mask) {
			if (__builtin_popcount(mask) * 2 < n)
				continue;
			double chance = 1;
			for (int k = 0; k < n; ++k)
				if ((mask >> k) & 1)
					chance *= (100 - loyalty[k]) / 100.0;
				else
					chance *= (loyalty[k]) / 100.0;
			int sumLevels = 0;
			for (int k = 0; k < n; ++k)
				if ((mask >> k) & 1)
					sumLevels += level[k];
			loseChance += chance * double(sumLevels) / double(sumLevels + A);
		}
		result = max(result, 1 - loseChance);
		return;
	}
	int pr = loyalty[c];
	while (loyalty[c] <= 100 && candies >= 0) {
		go(c + 1, candies);
		loyalty[c] += 10;
		--candies;
	}
	loyalty[c] = pr;
}

int main() {
	scanf("%d %d %d", &n, &k, &A);
	for (int i = 0; i < n; ++i)
		scanf("%d %d", &level[i], &loyalty[i]);
	go(0, k);
	printf("%.9lf\n", result);
}