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

const int maxn = 1000100;

int a00, a01, a10, a11; 

char s[maxn + 5];

inline bool work()
{
	int cnt0 = -1, cnt1 = -1;
	REP(i, 0, 100000) if ((LL)i * (i - 1) == a00 << 1) { cnt0 = i; break; }
	REP(i, 0, 100000) if ((LL)i * (i - 1) == a11 << 1) { cnt1 = i; break; }
	if (!~cnt0 || !~cnt1) return 0;
	if (cnt0 * cnt1 == 0 && a01 + a10)
	{
		if (!cnt0) ++cnt0;
		if (!cnt1) ++cnt1;
	}
	if (cnt0 + cnt1 == 0) ++cnt0;
	if (a01 + a10 != cnt0 * cnt1) return 0;
	if (!cnt0)
	{
		REP(i, 0, cnt1) s[i] = '1';
		return 1;
	}
	else if (!cnt1)
	{
		REP(i, 0, cnt0) s[i] = '0';
		return 1;
	}
	int num = a01 / cnt0;
	int res = a01 % cnt0;
	int sn = 0;
	REP(i, 0, cnt1 - num - 1) s[sn++] = '1';
	REP(i, 0, res) s[sn++] = '0';
	if (cnt1 != num) s[sn++] = '1';
	REP(i, res, cnt0) s[sn++] = '0';
	REP(i, 0, num) s[sn++] = '1';
	return 1;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d%d", &a00, &a01, &a10, &a11);
	bool ret = work();
	if (!ret) puts("Impossible");
	else puts(s);
	return 0;
}