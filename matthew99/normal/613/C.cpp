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
#else
#define LLFORMAT "ll"
#endif

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int Mod = 1e9 + 7;

const int oo = 0x3f3f3f3f;

const int maxl = 100000, maxn = 26;

int n;
int sum[maxn];

char anss[maxl + 5];
int ans = 0;

void work(int l, int r, int dep = 0)
{
	int cnt = 0;
	int p = -1;
	REP(i, 0, n) if (sum[i] & 1) p = i, ++cnt;
	if (cnt >= 2)
	{
		REP(i, l, r) REP(j, 0, n) if (sum[j]) { --sum[j], anss[i] = 'a' + j; break; }
		return;
	}
	else if (cnt == 1)
	{
		int mid = (l + r) >> 1;
		if (!dep) ans += 1 << dep;
		anss[mid] = 'a' + p;
		--sum[p];
		REP(i, l, mid)
		{
			REP(j, 0, n) if (sum[j]) { sum[j] -= 2, anss[i] = anss[(mid << 1) - i] = 'a' + j; break; }
		}
	}
	else
	{
		ans += 1 << (dep + (!dep));
		REP(i, 0, n) sum[i] >>= 1;
		int mid = (l + r) >> 1;
		work(l, mid, dep + 1);
		REP(i, l, mid) anss[(mid << 1) - i - 1] = anss[i];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	int tot = 0;
	int d = 0;
	REP(i, 0, n) scanf("%d", sum + i), tot += sum[i], d = __gcd(d, sum[i]);
	while (!(d & 1)) d >>= 1;
	REP(i, 0, n) sum[i] /= d;
	tot /= d;
	work(0, tot);
	ans *= d;
	printf("%d\n", ans);
	REP(i, 0, d) printf("%s", anss);
	return 0;
}