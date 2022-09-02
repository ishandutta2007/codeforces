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

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;
const LL OO = 0x3f3f3f3f3f3f3f3fLL;

const int Mod = 1e9 + 7;

const int lim = 1.01e9;

const int maxn = 100100, maxq = 100100;

int sum[maxn + 5], pw[maxn + 5];
int pre[maxn + 5], val[maxn + 5];

int n, qn;

int a[maxn + 5];

vector<pair<int, int> > all[maxn + 5];

int ans[maxq + 5];

int fa[maxn + 5];
int dis[maxn + 5];

vector<int> nxt[maxn + 5];

int get(int x) 
{
	int tmp = fa[x];
	if (tmp == x) return x;
	get(tmp);
	(dis[x] += dis[tmp]) %= Mod;
	fa[x] = fa[tmp];
	return fa[x];
}

int get_sum(int l, int r)
{
	return (sum[l] - (LL)sum[r] * pw[r - l]) % Mod;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &qn);
	REP(i, 0, n) scanf("%d", a + i);
	pw[0] = 1;
	REP(i, 0, n) (pw[i + 1] = pw[i] << 1) %= Mod;
	sum[n] = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		sum[i] = ((LL)sum[i + 1] * 2 + a[i]) % Mod;
	}
	REP(i, 0, n)
	{
		LL cur = 0;
		for (int j = i; j >= 0; --j)
		{
			(cur *= 2) += a[j];
			if (cur >= lim)
			{
				pre[i] = 0;
				break;
			}
			if (cur <= 0) 
			{
				val[i] = cur * 2 % Mod;
				pre[i] = j;
				break;
			}
		}
		nxt[pre[i]].pb(i);
	}
	REP(i, 0, qn)
	{
		int l, r;
		scanf("%d%d", &l, &r), --l;
		if (l + 1 == r) ans[i] = a[l];
		else all[l].pb(mp(r, i));
	}
	REP(i, 0, n + 1) fa[i] = i, dis[i] = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		for (auto j : all[i])
		{
			get(j.x);
			ans[j.y] = (dis[j.x] + get_sum(i, fa[j.x])) % Mod;
		}
		for (auto j : nxt[i]) 
		{
			dis[j + 1] = val[j];
			fa[j + 1] = i;
		}
	}
	REP(i, 0, qn) (ans[i] += Mod) %= Mod;
	REP(i, 0, qn) printf("%d\n", ans[i]);
	return 0;
}