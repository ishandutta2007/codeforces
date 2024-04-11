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
int a[maxn + 5];

map<int, int> cnt;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	LL sum = 0;
	REP(i, 0, n)
	{
		scanf("%d", a + i);
		++cnt[a[i]];
		sum += a[i];
	}
	int tmp = 0;
	for (auto u : cnt)
	{
		tmp += max(0, u.y - 1);
		if (u.y > 1 && (u.x == 0 || cnt[u.x - 1]))
		{
			puts("cslnb");
			return 0;
		}
	}
	if (tmp > 1)
	{
		puts("cslnb");
		return 0;
	}
	sum -= (LL)n * (n - 1) >> 1;
	puts((sum & 1) ? "sjfnb" : "cslnb");
	return 0;
}