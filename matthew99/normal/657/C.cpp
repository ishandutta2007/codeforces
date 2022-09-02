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

const int maxn = 200000;

int n, K, b, c;
LL a[maxn + 5];

inline LL dis(const LL &x, const LL &y) { return (y - x) / 5 * b + ((y - x) % 5 + 5) % 5 * c; }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d%d", &n, &K, &b, &c);
	chkmin(b, 5 * c);
	vector<LL> val;
	REP(i, 0, n) 
	{
		scanf("%I64d", a + i);
		REP(j, 0, 5) val.pb(a[i] + j);
	}
	sort(ALL(val));
	val.resize(unique(ALL(val)) - val.begin());
	sort(a, a + n);
	LL ans = LLONG_MAX;
	REP(bar, 0, 5)
	{
		vector<LL> all[5];
		int i = 0;
		static int now[5];
		static LL sum[5];
		memset(now, 0, sizeof now);
		memset(sum, 0, sizeof sum);
		int tot = 0;
		for (auto x : val)
		{
			if ((x - bar) % 5) continue;
			while (i < n && a[i] <= x)
			{
				int res = (a[i] % 5 + 5) % 5;
				all[res].pb(a[i]);
				sum[res] += a[i];
				++tot;
				++i;
			}
			while (tot > K)
			{
				int Maxp = -1;
				LL Max_val = -1;
				REP(j, 0, 5) if (now[j] != SZ(all[j]) && chkmax(Max_val, dis(all[j][now[j]], x))) Maxp = j;
				sum[Maxp] -= all[Maxp][now[Maxp]];
				--tot;
				++now[Maxp];
			}
			if (tot == K)
			{
				LL ret = 0;
				int cur = (x % 5 + 5) % 5;
				int baz = 0;
				REP(i, 0, 5) 
				{
					int foo = (SZ(all[cur]) - now[cur]);
					ret += (LL)baz * foo;
					ret += ((LL)(x - i) * foo - sum[cur]) / 5 * b;
					baz += c;
					(cur += 4) %= 5;
				}
				chkmin(ans, ret);
			}
		}
	}
	printf("%I64d\n", ans);
	return 0;
}