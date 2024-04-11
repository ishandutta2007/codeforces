#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

#define ctz __builtin_ctzll
#define bcnt __builtin_popcountll

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int Mod = 1e9 + 7;

const int oo = 0x3f3f3f3f;

inline int fpm(LL b, int e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

const int maxn = 40, maxm = 500100;

int coe;

int n, m;
char s[maxn + 5];

int p[maxm + 5];

int num[maxn + 5];
int big[maxn + 5];

bool has[maxn + 5];

int ans = 0;

int C[maxn + 5][maxn + 5];

inline void prepare()
{
	REP(i, 0, maxn + 1)
	{
		C[i][0] = 1;
		REP(j, 1, i + 1) (C[i][j] = C[i - 1][j - 1] + C[i - 1][j]) %= Mod;
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	prepare();
	scanf("%s", s);
	n = strlen(s);
	int cnt = 0;
	REP(i, 0, n) if (s[i] == '0') ++cnt;
	scanf("%d", &m);
	coe = 1;
	REP(i, 0, cnt + 1) num[i] = 1;
	REP(i, 0, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		coe = (LL)coe * fpm(x, y - 1, Mod) % Mod;
		if (x < n) has[x] = 1;
		else REP(j, 0, cnt + 1) num[j] = (LL)num[j] * (x - n + (cnt - j)) % Mod;
	}
	REP(i, 0, cnt + 1)
	{
		big[i] = 0;
		REP(j, 0, i + 1) (big[i] += (LL)C[i][j] * num[j] * ((j & 1) ? -1 : 1) % Mod) %= Mod;
	}
	map<LL, int> all;
	LL st = 0;
	REP(i, 0, n) if (s[i] == '0') st |= 1LL << i;
	{
		int firi = n;
		REP(j, 0, n) if (has[j]) { firi = j; break; }
		LL full = 0;
		REP(j, 0, n - firi) full |= 1LL << j;
		REP(j, firi, n) full |= 1LL << j;
		++all[LL(bcnt(st & ~full)) << n | (st & full)];
	}
	REP(i, 1, n) if (has[i])
	{
		int nxti = n;
		REP(j, i + 1, n) if (has[j]) { nxti = j; break; }
		LL tmp = 0;
		REP(j, 0, n) if (!(j % i)) tmp |= 1LL << j;
		LL cur = 0;
		REP(j, 0, n - i) cur |= 1LL << j;
		REP(j, i, n) cur |= 1LL << j;
		LL full = 0;
		REP(j, 0, n - nxti) full |= 1LL << j;
		REP(j, nxti, n) full |= 1LL << j;
		map<LL, int> nxt;
		for (auto u : all) if (u.y)
		{
			LL sta = u.x & ((1LL << n) - 1);
			int res = u.x >> n;
			REP(j, 0, min(i, n - i)) 
			{
				if ((st & (tmp << j)) == ((tmp << j) & ((1LL << n) - 1))) 
				{
					(nxt[LL(res + bcnt((sta & ~(tmp << j)) & ~full)) << n | ((sta & ~(tmp << j)) & full)] += u.y) %= Mod;
				}
			}
			int tot = bcnt(st & ~cur);
			if (tot) 
			{
				if (res) (nxt[LL(res - 1 + bcnt(sta & ~full)) << n | (sta & full)] += (LL)res * u.y % Mod) %= Mod;
				if (res != tot) (nxt[LL(res + bcnt(sta & ~full)) << n | (sta & full)] += (LL)(tot - res) * u.y % Mod) %= Mod;

			}
		}
		swap(all, nxt);
	}
	ans = 0;
	for (auto u : all) (ans += (LL)u.y * big[u.x >> n] % Mod) %= Mod;
	ans = (LL)ans * coe % Mod;
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}