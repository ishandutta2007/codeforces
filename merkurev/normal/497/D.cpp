#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;





struct Point
{
	int x, y;
	Point() : x(), y() {} 
	Point(int _x, int _y) : x(_x), y(_y) {}
	Point operator + (Point A) { return Point(x + A.x, y + A.y); }
	Point operator - (Point A) { return Point(x - A.x, y - A.y); }
	long long operator % (Point A) { return x * 1LL * A.x + y * 1LL * A.y; }
	long long operator * (Point A) { return x * 1LL * A.y - y * 1LL * A.x; }
	long long len2()
	{
		return *this % * this;
	}

	void read()
	{
		scanf("%d%d", &x, &y);
	}
	void print()
	{
		fprintf(stderr, "%d %d\n", x, y);
	}
};


const int maxn = 1005;
Point P[maxn];
Point S;
Point Q[maxn];
Point T;


bool test(Point v, vector <Point> ve)
{
	int n = (int) ve.size();
	long long d2 = v.len2();
	for (int i = 0; i < n; i++)
	{
		if (ve[i].len2() == d2)
			return true;
	}
	Point O = Point();
	for (int i = 0; i < n; i++)
	{
		Point A = ve[i];
		Point B = ve[(i + 1) % n];
		long long md = max(A.len2(), B.len2() );
		long long mind = min(A.len2(), B.len2() );
		
		if (mind <= d2 && d2 <= md)
			return true;
		
		if ((B - A) % (O - A) < 0 || (A - B) % (O - B) < 0)
			continue;
		long long x = A * B;
		x *= x;
		if (x <= d2 * (B - A).len2() && d2 <= md)
			return true;
	}

	return false;
}


int main()
{
#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
#endif
	S.read();
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		P[i].read();
		P[i] = P[i] - S;
	}
	T.read();
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		Q[i].read();
		Q[i] = Q[i] - T;
	}
	for (int i = 0; i < n; i++)
	{
		Point X = P[i];
		vector <Point> v;
		for (int j = 0; j < m; j++)
		{
			v.push_back(Q[j] - X);
		}
		if (test(T - S, v) )
		{
			printf("YES\n");
			return 0;
		}
	}
	for (int i = 0; i < m; i++)
	{
		Point X = Q[i];
		vector <Point> v;
		for (int j = 0; j < n; j++)
		{
			v.push_back(P[j] - X);
		}
		if (test(S - T, v) )
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");

	return 0;
}