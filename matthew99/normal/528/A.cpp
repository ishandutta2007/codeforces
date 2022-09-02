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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	set<int> co[2];
	set<pair<int, int> > delta[2];
	int w, h, n;
	scanf("%d%d%d", &w, &h, &n);
	co[0].insert(0);
	co[0].insert(w);
	delta[0].insert(mp(w, 0));
	co[1].insert(0);
	co[1].insert(h);
	delta[1].insert(mp(h, 0));
	REP(i, 0, n)
	{
		static char s[2];
		static int x;
		scanf("%s%d", s, &x);
		int ty = s[0] == 'H';
		co[ty].insert(x);
		auto it = co[ty].lower_bound(x);
		auto tmp = it;
		--tmp;
		++it;
		delta[ty].erase(mp(*it - *tmp, *tmp));
		delta[ty].insert(mp(x - *tmp, *tmp));
		delta[ty].insert(mp(*it - x, x));
		printf("%I64d\n", (LL)delta[0].rbegin()->x * delta[1].rbegin()->x);
	}
	return 0;
}