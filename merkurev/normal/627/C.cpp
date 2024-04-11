#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


vector <pair <int, int> > v;

set <int> s;

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n, d, m;
	scanf("%d%d%d", &d, &n, &m);
	for (int i = 0; i < m; i++)
	{
		int x, p;
		scanf("%d%d", &x, &p);
		v.push_back(make_pair(p, x) );
	}
	s.insert(0);
	s.insert(d);
	sort(v.begin(), v.end() );

	long long ans = 0;
	for (auto p : v)
	{
		int curCost = p.first;
		int curPos = p.second;
		auto it = s.lower_bound(curPos);
		auto pit = prev(it);
		int has = max(0, n - (curPos - *pit) );
		int need = *it - curPos;
		int buy = max(0, min(n - has, need - has) );
	//	eprintf("curCost = %d, curPos = %d, has = %d, need = %d, buy = %d\n", curCost, curPos, has, need, buy);
		ans += buy * 1LL * curCost;
		s.insert(curPos);
	}

	vector <int> pos;
	for (int x : s)
		pos.push_back(x);
	for (int i = 0; i < (int) pos.size() - 1; i++)
		if (pos[i + 1] - pos[i] > n)
			ans = -1;
	
	printf("%lld\n", ans);

	return 0;
}