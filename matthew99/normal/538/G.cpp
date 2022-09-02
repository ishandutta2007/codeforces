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
#define EXIT(...) printf(__VA_ARGS__), exit(0)

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 200000;

const int __buffsize = 100000;
char __buff[__buffsize];
char *__buffs, *__buffe;

#define getc() (__buffs == __buffe ? fread(__buff, 1, __buffsize, stdin), __buffe = __buff + __buffsize, *((__buffs = __buff)++): *(__buffs++))

template<typename T> inline T &Read(T &x)
{
	static char c;
	while (1) 
	{ 
		c = getc(); 
		if (c == '-' || (c >= '0' && c <= '9')) break; 
	}
	bool flag = c == '-';
	x = flag ? 0 : c - '0';
	while (1)
	{
		c = getc();
		if (c < '0' || c > '9') break;
		(x *= 10) += c - '0';
	}
	if (flag) x = -x;
	return x;
}

#undef getc

struct data
{
	int t;
	LL x, y, z;

	data() { }
	data(int _t, LL _x, LL _y, const LL &_z): t(_t), x(_x), y(_y), z(_z) { }

	friend bool operator<(const data &x, const data &y) { return x.t < y.t; }

};

data a[maxn + 5];

int n, l;
LL T[maxn + 5], X[maxn + 5], Y[maxn + 5];

inline LL Floor(LL a, LL b);
inline LL Ceil(LL a, LL b);

inline LL Floor(LL a, LL b)
{
	if (b < 0) a = -a, b = -b;
	if (a < 0) return -Ceil(-a, b);
	return a / b;
}

inline LL Ceil(LL a, LL b)
{
	if (b < 0) a = -a, b = -b;
	if (a < 0) return -Floor(-a, b);
	return (a + b - 1) / b;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Read(n), Read(l);
	REP(i, 0, n) 
	{
		Read(T[i]), Read(X[i]), Read(Y[i]);
		if ((T[i] ^ X[i] ^ Y[i]) & 1) EXIT("NO\n");
		a[i] = data(T[i] % l, X[i], Y[i], T[i] / l);
	}
	a[n++] = data(0, 0, 0, 0);
	a[n++] = data(l, 0, 0, -1);
	sort(a, a + n);
	LL Lx = LLONG_MIN, Rx = LLONG_MAX, Ly = LLONG_MIN, Ry = LLONG_MAX;
	REP(i, 1, n)
	{
		if (a[i].z == a[i - 1].z)
		{
			if (abs(a[i].x - a[i - 1].x) + abs(a[i].y - a[i - 1].y) > (a[i].t - a[i - 1].t)) EXIT("NO\n");
		}
		else
		{
			LL dx = a[i].x - a[i - 1].x, dy = a[i].y - a[i - 1].y;
			LL dz = a[i].z - a[i - 1].z;
			LL tmpx = dx - dy, tmpy = dx + dy;
			int dt = a[i].t - a[i - 1].t;
			LL lx = tmpx - dt, rx = tmpx + dt, ly = tmpy - dt, ry = tmpy + dt;
			if (dz < 0) swap(lx, rx), swap(ly, ry);
			lx = Ceil(lx, dz), rx = Floor(rx, dz), ly = Ceil(ly, dz), ry = Floor(ry, dz);
			chkmax(Lx, lx);
			chkmin(Rx, rx);
			chkmax(Ly, ly);
			chkmin(Ry, ry);
		}
	}
	if (Lx > Rx || Ly > Ry) EXIT("NO");
	bool flag = 0;
	LL ansx = 0, ansy = 0;
	for (LL i = Lx; i < Lx + 4; ++i)
		for(LL j = Ly; j < Ly + 4; ++j)
			if (i <= Rx && j <= Ry && !((i + j) & 1))
			{
				LL ux = (j + i) >> 1, uy = (j - i) >> 1;
				if (!((ux + uy + l) & 1))
				{
					flag = 1;
					ansx = ux, ansy = uy;
				}
			}
	if (!flag) EXIT("NO");
	REP(i, 0, n) a[i].x -= ansx * a[i].z, a[i].y -= ansy * a[i].z;
	a[n++] = data(l, ansx, ansy, 0);
	int curx = 0, cury = 0, curt = 0;
	REP(i, 0, n)
	{
		while (curx < a[i].x) putchar('R'), ++curx, ++curt;
		while (curx > a[i].x) putchar('L'), --curx, ++curt;
		while (cury < a[i].y) putchar('U'), ++cury, ++curt;
		while (cury > a[i].y) putchar('D'), --cury, ++curt;
		while (curt < a[i].t) putchar('L'), putchar('R'), curt += 2;
	}
	return 0;
}