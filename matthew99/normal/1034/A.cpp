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

const int maxn = 300100;
const int maxabs = 1.6e7;

int n;
int a[maxn + 5];
int f[maxabs + 5];
int cnt[maxabs + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	memset(f, -1, sizeof f);
	vector<int> pr;
	for (int i = 2; i <= maxabs; ++i)
	{
		if (!~f[i]) f[i] = i, pr.pb(i);
		REP(j, 0, SZ(pr)) 
		{ 
			if (i * pr[j] > maxabs) break;
			f[i * pr[j]] = pr[j];
			if (!(i % pr[j])) break;
		}
	}
	int d = 0;
	REP(i, 0, n) scanf("%d", a + i), d = __gcd(d, a[i]);
	REP(i, 0, n) a[i] /= d;
	REP(i, 0, n)
	{
		int u = a[i];
		int lst = -1;
		while (u > 1)
		{
			if (f[u] != lst) ++cnt[f[u]], lst = f[u];
			u /= f[u];
		}
	}
	int ans = -1;
	for (int i = maxabs; i > 1; --i)
	{
		if (cnt[i]) chkmax(ans, cnt[i]);
	}
	if (~ans) ans = n - ans;
	printf("%d\n", ans);
	return 0;
}