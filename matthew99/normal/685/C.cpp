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

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 100000;

int T;

int n;

LL a[maxn + 5][4];

LL Min[4], Max[4];

bool print;

inline bool check(const LL &x, int y)
{
	LL lz = LLONG_MIN, rz = LLONG_MAX;
	LL l0, r0, l1, r1;
	l0 = l1 = LLONG_MIN;
	r0 = r1 = LLONG_MAX;
	REP(i, 0, n)
	{
		chkmax(l0, a[i][0] - x);
		chkmin(r0, a[i][0] + x);
		chkmax(l1, a[i][1] - x);
		chkmin(r1, a[i][1] + x);
	}
	if ((l0 & 1) != y) ++l0;
	if ((r0 & 1) != y) --r0;
	if ((l1 & 1) != y) ++l1;
	if ((r1 & 1) != y) --r1;
	if (l0 > r0 || l1 > r1) return 0;
	LL u = l0, v = l1;
	chkmin(rz, (r0 - l1) >> 1);
	chkmax(lz, (l0 - r1) >> 1);
	l0 = l1 = LLONG_MIN;
	r0 = r1 = LLONG_MAX;
	REP(i, 0, n)
	{
		chkmax(l0, a[i][2] - x);
		chkmin(r0, a[i][2] + x);
		chkmax(l1, a[i][3] - x);
		chkmin(r1, a[i][3] + x);
	}
	if ((l0 & 1) != y) ++l0;
	if ((r0 & 1) != y) --r0;
	if ((l1 & 1) != y) ++l1;
	if ((r1 & 1) != y) --r1;
	if (l0 > r0 || l1 > r1) return 0;
	chkmin(rz, (r0 - l1) >> 1);
	chkmax(lz, (l0 - r1) >> 1);
	if (lz > rz) return 0;
	if (print)
	{
		LL sum = max(u - lz, v + lz), dif = max(l0 - lz, l1 + lz);
		print = 0;
		printf("%I64d %I64d %I64d\n", (sum + dif) >> 1, (sum - dif) >> 1, lz);
	}
	return 1;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		REP(i, 0, 4) Min[i] = LLONG_MAX, Max[i] = LLONG_MIN;
		REP(i, 0, n) 
		{
			LL x, y, z;
			scanf("%I64d%I64d%I64d", &x, &y, &z);
			a[i][0] = x + y + z;
			a[i][1] = x + y - z;
			a[i][2] = x - y + z;
			a[i][3] = x - y - z;
			REP(j, 0, 4) chkmin(Min[j], a[i][j]);
			REP(j, 0, 4) chkmax(Max[j], a[i][j]);
		}
		LL Min_val = LLONG_MAX;
		int Minp = -1;
		REP(i, 0, 2)
		{
			LL tmp = LLONG_MIN;
			REP(j, 0, 4)
			{
				if ((Min[j] ^ Max[j]) & 1) chkmax(tmp, (Max[j] - Min[j] + 1) >> 1);
				else chkmax(tmp, ((Max[j] - Min[j]) >> 1) + ((((Max[j] + Min[j]) >> 1) & 1) != i));
			}
			if (chkmin(Min_val, tmp)) Minp = i;
		}
		LL l = 0, r = 3.1e18;
		while (l < r)
		{
			LL mid = (l + r) >> 1;
			if (check(mid, 0) || check(mid, 1)) r = mid;
			else l = mid + 1;
		}
		print = 1;
		REP(i, 0, 2) check(l, i);
	}
	return 0;
}