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

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxabs = 1e6 + 100;

int n[3];
int m[3];
int s[3];

vector<int> fac[maxabs + 5];

void prepare()
{
	for (int i = 1; i <= maxabs; ++i)
		for (int j = i; j <= maxabs; j += i)
			fac[j].pb(i);
}

map<int, int> facS;
map<int, int> facN;

inline void factor(int a[3], map<int, int> &facA)
{
	facA.clear();
	REP(i, 0, 3)
	{
		int tmp = a[i];
		for (auto u : fac[a[i]]) if (SZ(fac[u]) == 2) 
		{
			while (!(tmp % u)) tmp /= u, ++facA[u];
		}
	}
}

vector<pair<int, int> > allp;
LL N, M, S;

LL ans;

void dfs(int x, LL cur = 1)
{
	if (x == SZ(allp))
	{
		if (cur >= 1 && cur < N) 
		{
			++ans;
		}
		return;
	}
	REP(i, 0, allp[x].y + 1)
	{
		dfs(x + 1, cur);
		cur *= allp[x].x;
	}
}

const int max0 = 100;

int wn;
LL w[max0 + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	prepare();
	int T;
	scanf("%d", &T);
	while (T--)
	{
		N = M = 1, S = 2;
		REP(i, 0, 3) scanf("%d", n + i), N *= n[i];
		REP(i, 0, 3) scanf("%d", m + i), M *= m[i];
		REP(i, 0, 3) scanf("%d", s + i), S *= s[i];


		ans = 0;
		factor(s, facS);
		++facS[2];
		allp.clear();
		for (auto u : facS) allp.pb(u);
		dfs(0);
		factor(n, facN);
		wn = 0;
		for (auto u : facN) 
		{
			int tmp = facS[u.x];
			w[wn] = 1;
			if (tmp >= u.y) w[wn] = 0;
			else REP(j, 0, tmp + 1) w[wn] *= u.x;
			++wn;
		}
		REP(i, 0, 1 << wn)
		{
			LL tmp = 1;
			int sign = 1;
			REP(j, 0, wn)
			{
				if (i >> j & 1) tmp *= w[j], sign = -sign;
			}
			if (tmp) ans += sign * ((M / tmp) + 1);
		}
		cout << ans << endl;
	}
	return 0;
}