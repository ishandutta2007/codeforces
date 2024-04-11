#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define ull unsigned long long
#define db double
#define ld long double
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pi complex<ld>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).size()
#define ALL(x) (x).insgin(), (x).end()
#define vi vector<int>
#define EPS 1e-8
using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

const int N = 2000010;
int n, d, b, a[N], mid, f1[N], f2[N];
int Lans, Rans, rest, l, r;
int main()
{
	n = read();
	d = read();
	b = read();
	mid = n / 2 * b;
	rep(i, 1, n) a[i] = read();
	rep(i, 1, n) f1[i] = min(a[i], mid) + f1[i - 1], mid -= min(a[i], mid);
	mid = n / 2 * b;
	rrep(i, n, 1) f2[i] = min(a[i], mid) + f2[i + 1], mid -= min(a[i], mid);
	mid = n / 2;
	rest = 0;
	rep(i, 1, mid)
	{
		r += d + 1;
		r = min(r, n);
		if (rest + b <= f1[r]) rest += b;
		else Lans ++;
	}
	mid = (n + 1) / 2 + 1;
	rest = 0;
	l = n + 1;
	rrep(i, n, mid)
	{
		l -= d + 1;
		l = max(1, l);
		if (rest + b <= f2[l]) rest += b;
		else Rans ++;
	}
	cout << max(Lans, Rans);
	return 0;
}