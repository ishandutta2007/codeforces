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

const int maxn = 30;
int val[maxn][3];
int skip[maxn];

vector <pair <pair <int, int>, pair<int, int> > > locdp, dpf, dps;

void genAll(pair <int, int> dp, int fst, int mask, int pos, int rem)
{
	if (rem == 0)
	{
//		eprintf("%d %d %d : %d\n", fst, fst + dp.first, fst + dp.second, mask);
		locdp.push_back(make_pair(dp, make_pair(fst, mask) ) );
		return;
	}
	genAll(make_pair(dp.first + val[pos][1], dp.second + val[pos][2] ), fst, mask * 3, pos + 1, rem - 1);
	genAll(make_pair(dp.first - val[pos][0], dp.second + val[pos][2] - val[pos][0] ), fst + val[pos][0], mask * 3 + 1, pos + 1, rem - 1);
	genAll(make_pair(dp.first + val[pos][1] - val[pos][0], dp.second - val[pos][0] ), fst + val[pos][0], mask * 3 + 2, pos + 1, rem - 1);
}

void calcDp(int l, int r)
{
	locdp.clear();
	genAll(make_pair(0, 0), 0, 0, l, r - l);
}

const long long inf = (long long) 1e18;

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &val[i][j] );
	int mid = n / 2;
	calcDp(0, mid);
	dpf = locdp;
//	eprintf("\n\n");
	calcDp(mid, n);
	for (auto p : locdp)
		dps.push_back(make_pair(make_pair(-p.first.first, -p.first.second), p.second) );

	sort(dpf.begin(), dpf.end() );
	sort(dps.begin(), dps.end() );
	int ptr = 0;
	int ans1 = -1, ans2 = -1;
	long long answer = -inf;

	for (int i = 0; i < (int) dpf.size(); i++)
	{
		while (ptr < (int) dps.size() && dps[ptr].first < dpf[i].first)
			ptr++;
		if (ptr == (int) dps.size() || dps[ptr].first != dpf[i].first)
			continue;
		long long curans = (long long) dpf[i].second.first + (long long) dps[ptr].second.first;
		if (curans > answer)
		{
			answer = curans;
			ans1 = dpf[i].second.second;
			ans2 = dps[ptr].second.second;
		}
	}
	if (answer == -inf)
	{
		printf("Impossible\n");
		return 0;
	}
	for (int i = mid - 1; i >= 0; i--)
	{
		skip[i] = ans1 % 3;
		ans1 /= 3;
	}
	for (int i = n - 1; i >= mid; i--)
	{
		skip[i] = ans2 % 3;
		ans2 /= 3;
	}
	for (int i = 0; i < n; i++)
		if (skip[i] == 0)
			printf("MW\n");
		else if (skip[i] == 1)
			printf("LW\n");
		else
			printf("LM\n");

	return 0;
}