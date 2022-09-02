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

const int maxn = 1000100;

int n;
char a[maxn + 5];

inline bool check(int x)
{
	vector<int> man, aster;
	REP(i, 0, n)
	{
		if (a[i] == 'P') man.pb(i);
		else if (a[i] == '*') aster.pb(i);
	}
	int nman = SZ(man), naster = SZ(aster);
	static bool dp[maxn + 5][2];
	memset(dp, 0, sizeof dp);
	int j = nman - 1;
	dp[naster][0] = dp[naster][1] = 1;
	for (int i = naster - 1; i >= 0; --i)
	{
		j = min(SZ(man) - 1, j + 1);
		while (j >= 0 && man[j] > aster[i])
		{
			bool ok = 0;
			if (man[j] - x <= aster[i])
			{
				int tmp = man[j];
				if (j && man[j - 1] > aster[i]) chkmax(tmp, man[j - 1] + x);
				int fir = upper_bound(ALL(aster), tmp) - aster.begin();
				if (fir == naster || (j + 1 < SZ(man) && aster[fir] > man[j + 1])) ok = dp[fir][1];
				else ok = dp[fir][0];
			}
			if (ok)
			{
				dp[i][0] = 1;
				break;
			}
			--j;
		}
		if (dp[i][0]) dp[i][1] = 1;
		else
		{
			if (j >= 0)
			{
				int tmp = man[j] + x;
				int fir = upper_bound(ALL(aster), tmp) - aster.begin();
				if (fir == naster || (j + 1 < SZ(man) && aster[fir] > man[j + 1]))
				{
					dp[i][1] = dp[fir][1];
				}
				else dp[i][1] = dp[fir][0];
			}
		}
	}
	return dp[0][1];
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	scanf("%s", a);
	bool unique = 1;
	int p = -1;
	int Max = 0, Min = oo;
	int tot = 0, left = 0;
	REP(i, 0, n) 
		if (a[i] == 'P')
		{
			if (~p)
			{
				unique = 0;
			}
			else 
			{
				left = tot;
				p = i;
			}
		}
		else if (a[i] == '*') 
		{
			++tot;
			chkmin(Min, i), chkmax(Max, i);
		}
	if (unique)
	{
		int right = tot - left;
		int left_dis = p - Min;
		int right_dis = Max - p;
		auto tmp = max(mp(left, -left_dis), mp(right, -right_dis));
		tmp.y = -tmp.y;
		printf("%d %d\n", tmp.x, tmp.y);
	}
	else
	{
		int l = 0, r = n;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (check(mid)) r = mid;
			else l = mid + 1;
		}
		printf("%d %d\n", tot, l);
	}
	return 0;
}