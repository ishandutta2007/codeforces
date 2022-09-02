#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cctype>
#include <cassert>
#include <ctime>
#include <set>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

const int maxn = 200000;

int n;
pair<int, int> a[maxn + 5];

int dp[maxn + 5];

int ans = 0;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d%d", &a[i].x, &a[i].y);
	sort(a, a + n);
	dp[0] = 0;
	set<pair<int, int> > all;
	REP(i, 0, n)
	{
		dp[i] = 1;
		if (!all.empty())
		{
			auto it = all.lower_bound(mp(-a[i].x + a[i].y, 0));
			if (it != all.end()) dp[i] = max(dp[i], it->y + 1);
		}
		ans = max(ans, dp[i]);
		__typeof__(all.begin()) it = all.lower_bound(mp(-a[i].x - a[i].y, dp[i]));
		if (it != all.end() && it->y >= dp[i]) continue;
		__typeof__(it) tmp = it;
		vector<__typeof__(tmp)> del;
		while (tmp != all.begin())
		{
			--tmp;
			if (tmp->y > dp[i]) break;
			del.pb(tmp);
		}
		REP(i, 0, SZ(del)) all.erase(del[i]);
		all.insert(mp(-a[i].x - a[i].y, dp[i]));
	}
	printf("%d\n", ans);
	return 0;
}