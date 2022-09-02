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

const int maxn = 4000;
const int max0 = 100000;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	static char s[maxn + 5];
	int a;
	scanf("%d", &a);
	scanf("%s", s);
	int n = strlen(s);
	static int cnt[max0 + 5];
	memset(cnt, 0, sizeof cnt);
	LL ans = 0;
	int cnt0 = 0, cnt1 = 0;
	REP(i, 0, n)
	{
		int sum = 0;
		REP(j, i, n)
		{
			sum += s[j] - '0';
			if (!sum) ++cnt0;
			else ++cnt1;
			if (sum && !(a % sum))
			{
				if (a / sum < max0) ans += cnt[a / sum] << 1;
				++cnt[sum];
				if ((LL)sum * sum == a) ++ans;
			}
		}
	}
	if (!a) ans = ((LL)cnt0 * cnt1 << 1) + (LL)cnt0 * cnt0;
	printf("%I64d\n", ans);
	return 0;
}