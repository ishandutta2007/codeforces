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
#define EXIT(...) printf(__VA_ARGS__), exit(0)

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const LL OO = 0x3f3f3f3f3f3f3f3fLL;
const int oo = 0x3f3f3f3f;

const int Mod = 1e9 + 7;

const int maxn = 500000;

int l, n, m;
LL row[maxn + 5], col[maxn + 5];

char s[maxn + 5];

void doit(char a, char b, int n, LL *c)
{
	int x = 0, y = n;
	REP(i, 0, n) c[i] = OO;
	REP(i, 0, l)
	{
		if (s[i] == a) ++x, ++y;
		if (s[i] == b) --x, --y;
		if (x > 0 && x <= n) chkmin(c[x - 1], (LL)i);
		if (y >= 0 && y < n) chkmin(c[y], (LL)i);
	}
	if (x > 0) REP(i, x, n) chkmin(c[i], c[i - x] + l);
	else if (x < 0) for (int i = n + x; i >= 0; --i) chkmin(c[i], c[i - x] + l);
}

LL ans = 0;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &l, &n, &m);
	scanf("%s", s);
	doit('U', 'D', n, row);
	doit('L', 'R', m, col);
	if (*max_element(row, row + n) == OO && *max_element(col, col + m) == OO)
	{
		printf("-1\n");
		return 0;
	}
	int lx = 0, rx = n, ly = 0, ry = m;
	ans = (LL)n * m;
	while (lx != rx && ly != ry)
	{
		LL a = row[lx], b = row[rx - 1], c = col[ly], d = col[ry - 1];
		LL Min = min(min(a, b), min(c, d));
		if (a == Min || b == Min)
		{
			if (a == Min) ++lx;
			else --rx;
			(ans += LL(ry - ly) * Min) %= Mod;
		}
		else
		{
			if (c == Min) ++ly;
			else --ry;
			(ans += LL(rx - lx) * Min) %= Mod;
		}
	}
	printf("%I64d\n", ans % Mod);
	return 0;
}