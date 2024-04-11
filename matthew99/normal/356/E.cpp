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

const int maxn = 100000, max0 = 17;

bool ok[max0][maxn + 5];

int n;

char s[maxn + 5];

bool check(int i, int j, int l, char c)
{
	int now = (1 << l) - 1;
	while (1)
	{
		if (s[i + now] != s[j + now] || s[i + now] == c) return 0;
		if (!now) break;
		(now >>= 1);
	}
	return 1;
}

bool is_ok(int l, int i)
{
	if (!l) return 1;
	if (i + (1 << l) >= n) return 0;
	if (!ok[l - 1][i] || !ok[l - 1][i + (1 << l)]) return 0;
	return check(i, i + (1 << l), l - 1, s[i + (1 << l) - 1]);
}

LL sum[maxn + 5];
LL tmp_sum[maxn + 5];

int go(int i, int j, int l)
{
	if (l < 0) return 0;
	int mid = l + (1 << (j + 1)) - 1;
	int r = mid + 1;
	if (r + (1 << (j + 1)) - 1 > n) return 0;
	int now = (1 << j) - 1;
	int can = (1 << 26) - 1;
	while (1)
	{
		char a = s[l + now], b = s[r + now];
		if (l + now == i) can &= (1 << (s[r + now] - 'a')), a = b;
		if (mid == i)
		{
			can &= ((1 << 26) - 1) ^ (1 << (s[l + now] - 'a'));
		}
		else if (s[mid] == a) can = 0;
		if (r + now == i) can &= (1 << (s[l + now] - 'a')), b = a;
		if (a != b) can = 0;
		if (!can) break;
		if (!now) break;
		now >>= 1;
	}
	return can;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s", s);
	n = strlen(s);
	REP(i, 0, n) ok[0][i] = 1;
	LL now = 0;
	REP(i, 1, max0) REP(j, 0, n) ok[i][j] = is_ok(i, j);
	REP(i, 0, max0)
	{
		LL tmp = (1 << (i + 1)) - 1;
		memset(tmp_sum, 0, sizeof tmp_sum);
		REP(j, 0, n - tmp + 1) if (ok[i][j]) 
		{
			tmp_sum[j] += tmp * tmp;
			tmp_sum[j + tmp] -= tmp * tmp;
			now += tmp * tmp;
		}
		REP(j, 0, n) sum[j] += tmp_sum[j], tmp_sum[j + 1] += tmp_sum[j];
	}
	LL ans = now;
	REP(i, 0, n)
	{
		static LL add[26];
		memset(add, 0, sizeof add);
		vector<pair<int, int> > all, all0;
		all.pb(mp(i, (1 << 26) - 1));
		REP(j, 1, max0)
		{
			all0.clear();
			LL tmp = (1 << j) - 1;
			for (auto x : all)
			{
				REP(k, 0, 26) if (x.y >> k & 1) add[k] += tmp * tmp;
				REP(k, 0, 2)
				{
					int l = 0;
					if (!k) 
					{
						l = x.x - (1 << j);
						if (!ok[j - 1][l]) continue;
					}
					else 
					{
						l = x.x;
						if (!ok[j - 1][l + (1 << j)]) continue;
					}
					int can = x.y & go(i, j - 1, l);
					if (can) all0.pb(mp(l, can));
				}
			}
			if (i - (1 << j) + 1 >= 0 && ok[j - 1][i + 1] && ok[j - 1][i - (1 << j) + 1] && check(i - (1 << j) + 1, i + 1, j - 1, '@')) 
			{
				int tmp = go(i, j - 1, i - (1 << j) + 1);
				if (tmp) all0.pb(mp(i - (1 << j) + 1, tmp));
			}
			all = all0;
		}
		REP(j, 0, 26) chkmax(ans, now - sum[i] + add[j]);
	}
	printf("%I64d\n", ans);
	return 0;
}