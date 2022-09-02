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

const int maxl = 20;

const LL M = 1000000000000000000LL;

inline LL mul(LL b, LL e, const LL &m)
{
	b %= m;
	e %= m;
	LL t = b * e - LL((long double)b * e / m) * m;
	while (t < 0) t += m;
	while (t >= m) t -= m;
	return t;
}

LL need[maxl + 5];
LL val[maxl + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	need[0] = 4;
	val[0] = 1 << 4;
	REP(i, 0, maxl) 
	{
		need[i + 1] = need[i] * 5;
		val[i + 1] = 1;
		REP(j, 0, 5) 
		{
			val[i + 1] = mul(val[i + 1], val[i], M);
		}
	}


	static int fir[2048];
	static LL fir_val[2048];
	memset(fir, -1, sizeof fir);

	int cnt = 0;
	LL tmp = 1;
	int p = 0;
	while (cnt < 2048)
	{
		++p;
		tmp *= 2;
		tmp %= M;
		if (p > 100)
		{
			if (!~fir[tmp / 1000000 % 2048]) ++cnt, fir[tmp / 1000000 % 2048] = p, fir_val[tmp / 1000000 % 2048] = tmp;
		}
	}

	int n;
	scanf("%d", &n);
	REP(i, 0, n)
	{
		LL x;
		cin >> x;
		LL ret = fir[x % 2048];
		LL cur = fir_val[x % 2048];
		int bit = 6;
		LL now = 1000000;
		while (x)
		{
			int goal = x % 10;
			while (cur / now % 10 != goal)
			{
				cur = mul(cur, val[bit - 1], M);
				ret += need[bit - 1];
			}
			++bit;
			now *= 10;
			x /= 10;
		}
		cout << ret << endl;
	}
	return 0;
}