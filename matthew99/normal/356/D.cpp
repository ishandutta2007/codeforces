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

const int maxn = 70000, maxs = 70000;

int n, s;
int a[maxn + 5];

int pos[maxn + 5];

inline bool cmp(int x, int y) { return a[x] > a[y]; }

int pre[maxs + 5];
bitset<maxs + 5> ok;

bool picked[maxn + 5];

int contain[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &s);
	REP(i, 0, n) scanf("%d", a + i), pos[i] = i;
	sort(pos, pos + n, cmp);
	if (s < a[pos[0]])
	{
		printf("-1\n");
		return 0;
	}
	s -= a[pos[0]];
	pre[0] = -1;
	ok[0] = 1;
	REP(i, 1, n)
	{
		bitset<maxs + 5> t = ok | (ok << a[pos[i]]), tmp = t ^ ok;
		for (int j = tmp._Find_next(-1); j < maxs + 5; j = tmp._Find_next(j)) pre[j] = pos[i], ok[j] = 1;
		if (ok[s]) break;
	}
	if (!ok[s]) printf("-1\n");
	else
	{
		int u = s;
		while (u > 0)
		{
			picked[pre[u]] = 1;
			u -= a[pre[u]];
		}
		assert(!u);
		memset(contain, -1, sizeof contain);
		int lst = -1;
		for (int i = n - 1; i >= 0; --i)
		{
			contain[pos[i]] = lst;
			if (!picked[pos[i]]) lst = pos[i];
			else lst = -1;
		}
		REP(i, 0, n)
		{
			if (contain[i] == -1) printf("%d 0\n", a[i]);
			else printf("%d 1 %d\n", a[i] - a[contain[i]], contain[i] + 1);
		}
	}
	return 0;
}