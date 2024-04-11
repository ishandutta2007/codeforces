#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
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

const int maxn = 500010;

int n;
char s[maxn + 5];

int Min[(maxn << 1) + 5];

int Max[maxn + 5];

int sum[maxn + 5];

int go[maxn + 5];

int sa[maxn + 5], rk[maxn + 5], h[maxn + 5];

inline void sortx(int *a, int *b, int *c, const int &n, const int &m)
{
	static int sum[maxn + 5];
	memset(sum, 0, sizeof(int) * (m + 1));
	REP(i, 0, n) ++sum[b[i]];
	REP(i, 0, m) sum[i + 1] += sum[i];
	for (int i = n - 1; i >= 0; --i) a[--sum[b[c[i]]]] = c[i];
}

inline void make_sa(char *s, int *sa, int *rk, const int &n)
{
	static int x[maxn + 5], y[maxn + 5];
	REP(i, 0, n) x[i] = s[i], y[i] = i;
	sortx(sa, x, y, n, CHAR_MAX);
	rk[sa[0]] = 0;
	REP(i, 0, n - 1) rk[sa[i + 1]] = rk[sa[i]] + (s[sa[i]] != s[sa[i + 1]]);
	for (int i = 1; rk[sa[n - 1]] < n - 1; i <<= 1)
	{
		REP(j, 0, n) x[j] = j + i >= n ? 0 : rk[j + i] + 1;		
		sortx(y, x, sa, n, n);
		sortx(sa, rk, y, n, n); 
		memcpy(y, rk, sizeof(int) * n);
		rk[sa[0]] = 0;
		REP(j, 0, n - 1) rk[sa[j + 1]] = rk[sa[j]] + (y[sa[j]] != y[sa[j + 1]] || x[sa[j]] != x[sa[j + 1]]);
	}
}

inline void get_height(char *s, int *h, int *sa, int *rk, const int &n)
{
	int j = 0;
	REP(i, 0, n)
	{
		if (rk[i] + 1 >= n) continue;
		while (s[sa[rk[i]] + j] == s[sa[rk[i] + 1] + j]) ++j;
		h[rk[i]] = j;
		if (j) --j;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	scanf("%s", s);
	memset(Min, oo, sizeof Min);
	int cnt = 0;
	sum[n] = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		if (s[i] == ')') ++cnt;
		else --cnt;
		sum[i] = cnt;
		for (int j = cnt + maxn; j <= (maxn << 1); j += j & -j) chkmin(Min[j], i);
		go[i] = n;
		for (int j = cnt + maxn - 1; j > 0; j -= j & -j) chkmin(go[i], Min[j]);
	}
	sum[0] = 0;
	REP(i, 0, n)
	{
		if (s[i] == '(') sum[i + 1] = sum[i] + 1;
		else sum[i + 1] = sum[i] - 1;
	}
	make_sa(s, sa, rk, n);
	get_height(s, h, sa, rk, n);
	static vector<pair<int, int> > all[maxn + 5];
	REP(i, 0, n)
	{
		int Min = (!i ? 0 : h[i - 1]) + 1;
		int l = sa[i] + Min, r = go[sa[i]];
		if (l > r) continue;
		all[l].pb(mp(-1, sum[sa[i]]));
		all[r + 1].pb(mp(1, sum[sa[i]]));
	}
	static int c[(maxn << 1) + 5];
	memset(c, 0, sizeof c);
	LL ans = 0;
	REP(i, 0, n + 1)
	{
		++c[sum[i] + maxn];
		for (auto x : all[i + 1])
		{
			if (x.x == -1) ans -= c[x.y + maxn];
			if (x.x == 1) ans += c[x.y + maxn];
		}
	}
	printf("%I64d\n", ans);
	return 0;
}