#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

map<pair<int, int>, int> cnt;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	pair<int, int> now = mp(0, 0);
	++cnt[now];
	static char s[100000];
	scanf("%s", s);
	int ans = 0;
	REP(i, 0, n)
	{
		if (s[i] == 'U') now.x -= 1;
		if (s[i] == 'D') now.x += 1;
		if (s[i] == 'L') now.y -= 1;
		if (s[i] == 'R') now.y += 1;
		ans += cnt[now];
		++cnt[now];
	}
	printf("%d\n", ans);
	return 0;
}