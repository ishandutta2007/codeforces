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

const int maxn = 100100;

int n, K;

vector<int> a[2];

char s[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &K);
	scanf("%s", s);
	REP(i, 0, n)
	{
		a[s[i] - '0'].pb(i);
	}
	int ans = 2;
	REP(i, 0, 2)
	{
		sort(ALL(a[i]));
		if (a[i].empty() || a[i].back() - a[i][0] < K) ans = 0;
		else
		{
			REP(j, 0, n - K)
			{
				int Min = oo, Max = -oo;
				if (a[i][0] < j) Min = a[i][0];
				else Min = *lower_bound(ALL(a[i]), j + K);
				if (a[i].back() >= j + K) Max = a[i].back();
				else Max = *--upper_bound(ALL(a[i]), j);
				if (Max - Min >= K) chkmin(ans, 1); 
			}
		}
	}
	if (ans == 2) puts("quailty");
	else if (ans == 1) puts("once again");
	else puts("tokitsukaze");
	return 0;
}