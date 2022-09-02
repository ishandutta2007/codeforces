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

#ifdef __WIN32
#define LLFORMAT "I64"
#define Rand() ((rand() << 15) | rand())
#else
#define LLFORMAT "ll"
#define Rand() (rand())
#endif

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 400000, maxm = 400000;

int Mod;

int n, m, N;

int a[maxn + 5];

int val[maxm + 5];

vector<int> allq[maxn + 5];
int lMax[maxm + 5], rMax[maxm +5];

int ans[maxm + 5];

int pre_cnt[maxn + 5], pre_dp[maxn + 5];
int suf_cnt[maxn + 5], suf_dp[maxn + 5];

bool must[maxn + 5];

vector<int> all[maxn + 5];
vector<int> sum[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	while (1)
	{
		Mod = Rand() % 100000000 + 900000000;
		bool flag = 1;
		for (int i = 2; i * i <= Mod; ++i)
			if (!(Mod % i)) { flag = 0; break; }
		if (flag) break;
	}
	scanf("%d%d", &n, &m);
	REP(i, 0, n) scanf("%d", a + i);
	REP(i, 0, m) 
	{
		int x;
		scanf("%d%d", &x, val + i), --x;
		allq[x].pb(i);
	}
	REP(i, 0, n + 1) all[i].clear(), sum[i] = vector<int>{0};
	int lis = 0;
	int tot = 0;
	REP(i, 0, n)
	{
		for (auto x : allq[i])
		{
			int l = 0, r = n;
			while (l < r)
			{
				int mid = (l + r + 1) >> 1;
				if (!all[mid].empty() && all[mid].back() < val[x]) l = mid;
				else r = mid - 1;
			}
			lMax[x] = l + 1;
		}
		int l = 0, r = n;
		while (l < r)
		{
			int mid = (l + r + 1) >> 1;
			if (!all[mid].empty() && all[mid].back() < a[i]) l = mid;
			else r = mid - 1;
		}
		if (!l) pre_cnt[i] = 1;
		else pre_cnt[i] = (sum[l].back() - sum[l][all[l].rend() - lower_bound(all[l].rbegin(), all[l].rend(), a[i])]) % Mod; 
		pre_dp[i] = l + 1;
		if (chkmax(lis, l + 1)) tot = pre_cnt[i];
		else if (l + 1 == lis) (tot += pre_cnt[i]) %= Mod;
		all[l + 1].pb(a[i]), sum[l + 1].pb((sum[l + 1].back() + pre_cnt[i]) % Mod);
	}
	REP(i, 0, n + 1) all[i].clear(), sum[i] = vector<int>{0};
	for (int i = n - 1; i >= 0; --i)
	{
		for (auto x : allq[i])
		{
			int l = 0, r = n;
			while (l < r)
			{
				int mid = (l + r + 1) >> 1;
				if (!all[mid].empty() && all[mid].back() > val[x]) l = mid;
				else r = mid - 1;
			}
			rMax[x] = l + 1;
		}
		int l = 0, r = n;
		while (l < r)
		{
			int mid = (l + r + 1) >> 1;
			if (!all[mid].empty() && all[mid].back() > a[i]) l = mid;
			else r = mid - 1;
		}
		if (!l) suf_cnt[i] = 1;
		else suf_cnt[i] = (sum[l].back() - sum[l][upper_bound(all[l].begin(), all[l].end(), a[i]) - all[l].begin()]) % Mod;
		suf_dp[i] = l + 1;
		if (pre_dp[i] + suf_dp[i] - 1 != lis || ((LL)pre_cnt[i] * suf_cnt[i] - tot) % Mod) must[i] = 0;
		else must[i] = 1;
		for (auto x : allq[i]) if (must[i]) ans[x] = lis - 1; else ans[x] = lis;
		all[l + 1].pb(a[i]), sum[l + 1].pb((sum[l + 1].back() + suf_cnt[i]) % Mod);
	}
	REP(i, 0, m) chkmax(ans[i], lMax[i] + rMax[i] - 1);
	REP(i, 0, m) printf("%d\n", ans[i]);
	return 0;
}