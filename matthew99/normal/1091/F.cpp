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

int n;
LL a[maxn + 5];
char ty[maxn + 5];

LL ans = 0;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%lld", a + i);
	scanf("%s", ty);
	LL cnt = 0, reserve = 0;
	bool flag = 0;
	REP(i, 0, n)
	{
		if (!flag)
		{
			if (ty[i] == 'W')
			{
				reserve = cnt;
				flag = 1;
				cnt = 0;
			}
			else if (ty[i] == 'G')
			{
				ans += a[i] * 3;
				cnt += a[i];
			}
			else if (ty[i] == 'L')
			{
				LL res = a[i];
				LL tmp = min(res, cnt);
				ans += tmp * 3;
				cnt -= tmp;
				res -= tmp;
				ans += res * 6;
			}
		}
		if (flag)
		{
			if (ty[i] == 'W')
			{
				ans += a[i] * 2;
				cnt += a[i];
			}
			else if (ty[i] == 'L')
			{
				LL res = a[i];
				LL tmp = min(res, cnt);
				ans += tmp * 2;
				cnt -= tmp;
				res -= tmp;
				tmp = min(res, reserve);
				ans += tmp * 3;
				reserve -= tmp;
				res -= tmp;
				ans += res * 4;
			}
			else if (ty[i] == 'G')
			{
				LL res = a[i];
				LL tmp = min(res, cnt);
				ans += tmp * 2;
				cnt -= tmp;
				res -= tmp;
				ans += res * 3;
				reserve += tmp + a[i];
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}