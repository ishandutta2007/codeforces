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

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
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

const int maxn = 100000;

int n;
int a[maxn + 5];

int win1[maxn + 5], win2[maxn + 5];
int cnt1 = 0, cnt2 = 0;

int cc1[maxn + 5], cc2[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) 
	{
		scanf("%d", a + i);
		cc1[i] = cnt1, cc2[i] = cnt2;
		if (a[i] == 1) win1[cnt1++] = i;
		else win2[cnt2++] = i;
	}
	vector<pair<int, int> > ans;
	FOR(i, 1, n)
	{
		int cur1 = -1, cur2 = -1;
		int lst = -1;
		int t1 = 0, t2 = 0;
		while (1)
		{
			if (cur2 + i < cnt2 && (cur1 + i >= cnt1 || win2[cur2 + i] < win1[cur1 + i])) ++t2, cur2 += i, cur1 = cc1[win2[cur2]] - 1, lst = 2;
			else
			{
				if (cur1 + i >= cnt1) goto lyc;
				++t1;
				cur1 += i;
				cur2 = cc2[win1[cur1]] - 1;
				lst  = 1;
			}
			if ((cur1 >= 0 && win1[cur1] == n - 1) || (cur2 >= 0 && win2[cur2] == n - 1)) break;
		}
		if (t1 == t2) goto lyc;
		if (lst != a[n - 1]) goto lyc;
		if (t1 < t2 && lst == 1) goto lyc;
		if (t1 > t2 && lst == 2) goto lyc;
		ans.pb(mp(max(t1, t2), i));
lyc:;
	}
	sort(ALL(ans));
	printf("%d\n", SZ(ans));
	REP(i, 0, SZ(ans))
		printf("%d %d\n", ans[i].x, ans[i].y);
	return 0;
}