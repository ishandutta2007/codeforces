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

const int maxn = 200000, max0 = 300, max1 = 700, max2 = 700, maxabs = 1 << 30;

int n, m;
vector<int> X;
int a[maxn + 5];

vector<int> id[max1 + 5], Min[max1 + 5], cnt[max1 + 5], to_add[max1 + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n) scanf("%d", a + i), X.pb(a[i]);
	X.pb(maxabs);
	sort(ALL(X));
	X.resize(unique(ALL(X)) - X.begin());
	int tot = 0;
	REP(i, 0, SZ(X))
	{
		if (!(i % max0))
		{
			static int sum[maxn + 5];
			static bool imp[maxn + 5];
			memset(sum, 0, sizeof sum);
			memset(imp, 0, sizeof imp);
			REP(j, 0, n)
			{
				if (!(j % max2)) imp[j] = 1;
				if (a[j] < X[i]) 
				{
					--sum[j + 1];
					++sum[max(0, j - m + 1)];
				}
				else if (a[j] >= X[i] && a[j] < X[min(SZ(X) - 1, i + max0)])
				{
					to_add[tot].pb(j);
					imp[j + 1] = 1;
					imp[max(0, j - m + 1)] = 1;
				}
			}
			int now = -1, pre = 0;
			REP(j, 0, n)
			{
				pre += sum[j];
				if (imp[j])
				{
					++now;
					id[tot].pb(j);
					Min[tot].pb(pre);
					cnt[tot].pb(pre);
				}
				chkmin(Min[tot][now], pre);
			}
			id[tot].pb(n);
			++tot;
		}
	}
	int qn, lastans = 0;
	scanf("%d", &qn);
	static int lst[maxn + 5], sum[maxn + 5];
	memset(lst, -1, sizeof lst);
	REP(i, 0, qn)
	{
		int l, r, z;
		scanf("%d%d%d", &l, &r, &z), --l;
		z ^= lastans;
		int tmp = lower_bound(ALL(X), z) - X.begin();
		int p = tmp / max0;
		for (auto x : to_add[p])
			if (a[x] < z)
			{
				if (lst[x + 1] != i) sum[x + 1] = 0, lst[x + 1] = i;
				--sum[x + 1];
				if (lst[max(0, x + 1 - m)] != i) sum[max(0, x + 1 - m)] = 0, lst[max(0, x + 1 - m)] = i;
				++sum[max(0, x + 1 - m)];
			}
		int pre = 0;
		int ans = oo;
		REP(j, 0, SZ(id[p]) - 1)
		{
			int u = id[p][j], v = id[p][j + 1];
			if (lst[id[p][j]] == i) pre += sum[id[p][j]];
			if (u >= l && v < r) chkmin(ans, pre + Min[p][j]);
			else
			{
				if (v <= l || u >= r) continue;
				int now = cnt[p][j] + pre;
				REP(k, u, v)
				{
					if (k >= l && k < r) chkmin(ans, now);
					if (a[k] < X[p * max0]) --now;
					if (k + m < n && a[k + m] < X[p * max0]) ++now;
				}
			}
		}
		printf("%d\n", ans);
		lastans = ans;
	}
	return 0;
}