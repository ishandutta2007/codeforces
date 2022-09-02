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

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int qn;
	scanf("%d", &qn);
	REP(i, 0, qn)
	{
		int x;
		scanf("%d", &x);
		if (x == 3) cout << 1 << endl;
		if (x == 7) cout << 1 << endl;
		if (x == 15) cout << 5 << endl;
		if (x == 31) cout << 1 << endl;
		if (x == 63) cout << 21 << endl;
		if (x == 127) cout << 1 << endl;
		if (x == 255) cout << 85 << endl;
		if (x == 511) cout << 73 << endl;
		if (x == 1023) cout << 341 << endl;
		if (x == 2047) cout << 89 << endl;
		if (x == 4095) cout << 1365 << endl;
		if (x == 8191) cout << 1 << endl;
		if (x == 16383) cout << 5461 << endl;
		if (x == 32767) cout << 4681 << endl;
		if (x == 65535) cout << 21845 << endl;
		if (x == 131071) cout << 1 << endl;
		if (x == 262143) cout << 87381 << endl;
		if (x == 524287) cout << 1 << endl;
		if (x == 1048575) cout << 349525 << endl;
		if (x == 2097151) cout << 299593 << endl;
		if (x == 4194303) cout << 1398101 << endl;
		if (x == 8388607) cout << 178481 << endl;
		if (x == 16777215) cout << 5592405 << endl;
		if (x == 33554431) cout << 1082401 << endl;
		if (x & (x + 1)) cout << (1 << (32 - __builtin_clz(x))) - 1 << endl; 
	}
	/*	for (int i = 1; i <= (1 << 25) - 1; i = (i * 2) + 1)
		{
		int Max = 0;
		REP(j, 1, i)
		chkmax(Max, __gcd(i ^ j, i & j));
		int ans = (i & (i + 1)) ? (1 << (32 - __builtin_clz(i))) - 1 : 0;
		if (Max != ans) debug("if (x == %d) cout << %d << endl;\n", i, Max);
		}*/
	return 0;
}