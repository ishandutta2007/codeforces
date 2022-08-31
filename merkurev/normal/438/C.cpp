#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <cmath>
#include <map>
using namespace std;


#ifdef LOCAL
	#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;

struct Point
{
	ll x, y;
	Point() : x(), y() {}
	Point(ll _x, ll _y) : x(_x), y(_y) {}
	Point operator + (Point A) { return Point(x + A.x, y + A.y); }
	Point operator - (Point A) { return Point(x - A.x, y - A.y); }
	Point operator * (ll a) { return Point(x * a, y * a); }
	Point operator / (ll a) { return Point(x / a, y / a); }
	ll operator % (Point A) { return x * A.x + y * A.y; }
	ll operator * (Point A) { return x * A.y - y * A.x; }
	double length() { return sqrt( (double) (*this % *this) ); }
	ll len2() { return *this % *this; }
	double distTo(Point A) { return (*this - A).length(); }

	bool onLine(Point A, Point B)
	{
		return (*this - A) * (B - A) == 0;
	}

	bool onSegm(Point A, Point B)
	{
		return onLine(A, B) && (*this - A) % (*this - B) <= 0;
	}

	void read()
	{
		scanf("%lld%lld", &x, &y);
	}
};

int sgn(long long x)
{
	if (x < 0)
		return -1;
	if (x == 0)
		return 0;
	return 1;
}

bool oneSide(Point A, Point B, Point C, Point D)
{
	int s1 = sgn( (B - A) * (C - A) );
	int s2 = sgn( (B - A) * (D - A) );
	if (s1 * s2 == 1)
		return true;
	return false;
}

bool isParallel(Point A, Point B, Point C, Point D)
{
	return (B - A) * (D - C) == 0;
}

bool hasInter(Point A, Point B, Point C, Point D)
{
	if (isParallel(A, B, C, D) )
		return (C.onSegm(A, B) || D.onSegm(A, B) || A.onSegm(C, D) || B.onSegm(C, D) );
	return (!oneSide(A, B, C, D) && !oneSide(C, D, A, B) );
}

const int mod = (int) 1e9 + 7;
int add(int a, int b)
{
	return (a + b) % mod;
}
int mul(int a, int b)
{
	return (a * 1LL * b) % mod;
}

const int maxn = 205;
Point P[maxn];

int n;

bool isIn(Point X)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		Point A = P[i];
		Point B = P[i + 1];

		if (X.onSegm(A, B) )
			return false;

		if (A.y == B.y)
			continue;
		if (A.y > B.y)
			swap(A, B);
		if (!(A.y <= X.y && X.y < B.y) )
			continue;
		ll day = X.y - A.y;
		ll dby = B.y - X.y;

		if (A.x * dby + B.x * day > X.x * (day + dby) )
			cnt++;
	}
//	eprintf("cnt = %d\n", cnt);
	return cnt % 2;
}

bool cd[maxn][maxn];
int dp[maxn][maxn];
bool used[maxn][maxn];

int solve(int l, int r)
{
//	eprintf("l = %d, r = %d\n", l, r);
	if (used[l][r] )
		return dp[l][r];
	used[l][r] = true;
	if (r - l <= 2)
		return dp[l][r] = 1;
	int ans = 0;
	if (cd[l + 1][r] )
	{
		ans = add(ans, solve(l + 1, r) );
	}
	for (int i = r - 1; i >= l + 2; i--)
	{
		if (cd[l][i] && (i == r - 1 || cd[r][i] ) )
		{
			ans = add(ans, mul(solve(l, i), solve(i, r) ) );
		}
	}
//	eprintf("l = %d, r = %d : %d\n", l, r, ans);
	return dp[l][r] = ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		P[i].read();
		P[i] = P[i] * 2;
	}
	P[n] = P[0];

	for (int i = 0; i < n; i++)
		for (int j = i + 2; j < (i == 0 ? n - 1 : n); j++)
		{
			bool good = isIn( (P[i] + P[j] ) / 2) ;
//			eprintf("%d %d : %d\n", i, j, (int) good);
			for (int h = 0; h < n && good; h++)
			{
				int hh = (h + 1) % n;
				if (h == i || h == j || hh == i || hh == j)
					continue;
				if (hasInter(P[i], P[j], P[h], P[hh] ) )
				{
//					eprintf("h = %d, hh = %d\n", h, hh);
					good = false;
				}
			}
//			eprintf("%d %d : %d\n", i, j, (int) good);
			cd[i][j] = cd[j][i] = good;
		}
	int ans = solve(0, n - 1);
	printf("%d\n", ans);

	return 0;
}