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

inline int fpm(LL b, int e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

const int Mod = 1e9 + 7;

const int maxn = 400100;

int K, an, bn;
int cnt0[maxn + 5], cnt1[maxn + 5];

int v[maxn + 5], vn;
pair<int, int> a[maxn + 5], b[maxn + 5];

int bounda[maxn + 5], boundb[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &K, &an, &bn);
	vn = 0;
	v[vn++] = 0;
	v[vn++] = K;
	REP(i, 0, an) scanf("%d%d", &a[i].x, &a[i].y), --a[i].x, v[vn++] = a[i].x, v[vn++] = a[i].y;
	REP(i, 0, bn) scanf("%d%d", &b[i].x, &b[i].y), --b[i].x, v[vn++] = b[i].x, v[vn++] = b[i].y;
	sort(v, v + vn);
	vn = unique(v, v + vn) - v;
	memset(bounda, -1, sizeof bounda);
	memset(boundb, -1, sizeof boundb);
	REP(i, 0, an)
	{
		a[i].x = lower_bound(v, v + vn, a[i].x) - v;
		a[i].y = lower_bound(v, v + vn, a[i].y) - v;
		chkmax(bounda[a[i].y], a[i].x);
	}
	REP(i, 0, bn)
	{
		b[i].x = lower_bound(v, v + vn, b[i].x) - v;
		b[i].y = lower_bound(v, v + vn, b[i].y) - v;
		chkmax(boundb[b[i].y], b[i].x);
	}
	cnt0[0] = 1;
	int ptr0 = 0, ptr1 = 0;
	int sum0 = 1, sum1 = 0;
	REP(i, 0, vn - 1)
	{
		int tmp0 = sum0, tmp1 = sum1;

		(sum0 -= (cnt0[i] + cnt0[i + 1]) % Mod) %= Mod;
		(sum1 -= (cnt1[i] + cnt1[i + 1]) % Mod) %= Mod;
		
		(cnt0[i + 1] += (LL)(tmp0 + tmp1) * (fpm(2, v[i + 1] - v[i] - 1, Mod) - 1) % Mod) %= Mod;
		(cnt1[i] += tmp0) %= Mod;

		(cnt1[i + 1] += (LL)(tmp0 + tmp1) * (fpm(2, v[i + 1] - v[i] - 1, Mod) - 1) % Mod) %= Mod;
		(cnt0[i] += tmp1) %= Mod;

		(sum0 += (cnt0[i] + cnt0[i + 1]) % Mod) %= Mod;
		(sum1 += (cnt1[i] + cnt1[i + 1]) % Mod) %= Mod;

		while (ptr0 <= bounda[i + 1])
		{
			(sum0 -= cnt0[ptr0++]) %= Mod;
		}
		while (ptr1 <= boundb[i + 1])
		{
			(sum1 -= cnt1[ptr1++]) %= Mod;
		}
	}
	int ans = (sum0 + sum1) % Mod;
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}