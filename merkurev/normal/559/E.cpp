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

const int maxn = 105;
map <pair <int, int>, int> dp;

int n;
int l[maxn];
int a[maxn];

int solve(int first, int till)
{
	if (first == n)
		return 0;
	pair <int, int> arg = make_pair(first, till);
	if (dp.count(arg) )
		return dp[arg];
	int ans = 0;

	{
		int ub = a[first];
		int x = first;
		
		while (x < n && a[x] <= ub)
		{
			ub = max(ub, a[x] + l[x] );
			x++;
		}
		
		int down = a[first];
		int cur = ub - down + solve(x, ub);
		//eprintf("first = %d, till = %d, nd = %d, down = %d, ub = %d, cur = %d\n", first, till, nd, down, ub, cur);
		ans = max(ans, cur);
	}
	
	for (int nd = first; nd < n; nd++)
	{
		int down = a[nd] - l[nd];
		if (down > a[first] )
			continue;

		int ub = a[nd];
		int x = first;

		while (x < n && (a[x] <= ub || x == nd) )
		{
			if (x != nd)
			{
				ub = max(ub, a[x] + l[x] );
			}
			x++;
		}

		down = max(down, till);
		int cur = ub - down + solve(x, ub);
	//	eprintf("first = %d, till = %d, nd = %d, down = %d, ub = %d, cur = %d\n", first, till, nd, down, ub, cur);
		ans = max(ans, cur);
	}
	dp[arg] = ans;
	return ans;
}

void solve()
{

	vector <pair <int, int> > v;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v.push_back(make_pair(x, y) );
	}

	sort(v.begin(), v.end() );
	for (int i = 0; i < n; i++)
	{
		l[i] = v[i].second;
		a[i] = v[i].first;
	}

	int ans = solve(0, -(int)1e9);
	printf("%d\n", ans);
}


int main(int , char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	solve();

	return 0;
}