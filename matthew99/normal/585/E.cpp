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

const int Mod = 1e9 + 7;

const int maxn = 500000, maxabs = 10000000;

int n;
int a[maxn + 5];

int fir[maxabs + 5], fir0[maxabs + 5];

inline void prepare()
{
	vector<int> p;
	memset(fir, -1, sizeof fir);
	for (int i = 2; i <= maxabs; ++i)
	{
		if (fir[i] == -1) p.pb(i), fir[i] = i, fir0[i] = 1;
		REP(j, 0, SZ(p))
		{
			if (i * p[j] > maxabs) break;
			fir[i * p[j]] = p[j];
			if (!(i % p[j])) 
			{
				fir0[i * p[j]] = fir0[i];
				break;
			}
			else fir0[i * p[j]] = i;
		}
	}
}

vector<int> fac;

vector<pair<int, int> > pr;

void dfs(const int &x, int now = 1)
{
	if (x == SZ(pr))
	{
		fac.pb(now);
		return;
	}
	REP(j, 0, pr[x].y + 1)
	{
		dfs(x + 1, now);
		now *= pr[x].x;
	}
}

inline void get_fac(int x)
{
	pr.clear();
	while (x > 1)
	{
		if (!pr.empty() && fir[x] == pr[SZ(pr) - 1].x) ++pr[SZ(pr) - 1].y;
		else pr.pb(mp(fir[x], 1));
		x /= fir[x];
	}
	dfs(0);
}

int cnt[maxabs + 5];
int cntset[maxabs + 5], cntpos[maxabs + 5];

int pw[maxabs + 5];

template<typename T> T &Read(T &x)
{
	static char c;
	while (!isdigit(c = getchar()));
	x = c - '0';
	while (isdigit(c = getchar())) (x *= 10) += c - '0';
	return x;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	prepare();
	Read(n);
	int Max = 0;
	REP(i, 0, n) 
	{
		Read(a[i]);
		chkmax(Max, a[i]);
		fac.clear();
		get_fac(a[i]);
		for (auto it : fac) ++cnt[it];
	}
	pw[0] = 1;
	REP(i, 0, Max) pw[i + 1] = (pw[i] << 1) % Mod;
	for (int i = 1; i <= Max; ++i) cntset[i] = (pw[cnt[i]] - 1) % Mod;
	for (int i = Max; i >= 1; --i)
		for (int j = i << 1; j <= Max; j += i)
			(cntset[i] -= cntset[j]) %= Mod;
	int ans = 0;
	for (int i = 2; i <= Max; ++i)
	{
		if (!cntset[i]) continue;
		int u = i;
		vector<int> all;
		while (u > 1)
		{
			all.pb(fir[u]);
			u = fir0[u];
		}
		int m = SZ(all);
		int cnt = 0;
		REP(j, 0, 1 << m)
		{
			int u = 1;
			int flag = 1;
			REP(k, 0, m)
				if ((j >> k) & 1) u *= all[k], flag *= -1;
			(cnt += flag * ::cnt[u]) %= Mod;
		}
		(ans += (LL)cnt * cntset[i] % Mod) %= Mod;
	}
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}