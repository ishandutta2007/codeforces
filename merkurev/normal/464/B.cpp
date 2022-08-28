#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;


bool dbg;

struct Point
{
	long long x, y, z;
	Point() : x(), y(), z() {}
	Point(long long _x, long long _y, long long _z) : x(_x), y(_y), z(_z) {}
	Point operator - (Point A)
	{
		return Point(x - A.x, y - A.y, z - A.z);
	}
	Point operator + (Point A)
	{
		return Point(x + A.x, y + A.y, z + A.z);
	}
	Point apply(int _x)
	{
		if (_x == 0) return Point(x, y, z); 
		if (_x == 1) return Point(x, z, y); 
		if (_x == 2) return Point(y, x, z); 
		if (_x == 3) return Point(y, z, x); 
		if (_x == 4) return Point(z, x, y); 
		if (_x == 5) return Point(z, y, x); 
		throw 42;
	}
	long long operator % (Point A)
	{
		return x * A.x + y * A.y + z * A.z;
	}
	Point operator * (Point A)
	{
		return Point(
			z * A.x - x * A.z,
			y * A.z - z * A.y,
			x * A.y - y * A.x
				);
	}
	long long len()
	{
		return x * 1LL * x + y * 1LL * y + z * 1LL * z;
	}
	bool operator == (const Point &A) const
	{
		return x == A.x && y == A.y && z == A.z;
	}
	bool operator != (const Point &A) const
	{
		return x != A.x || y != A.y || z != A.z;
	}
	bool canGet(Point A)
	{
		if (dbg)
		{
			fprintf(stderr, "canGet: \n");
			A.print();
			print();
		}
		for (int i = 0; i < 6; i++)
			if (apply(i) == A)
				return true;
		return false;
	}

	
	void read()
	{
		int _x, _y, _z;
		scanf("%d%d%d", &_x, &_y, &_z);
		x = _x;
		y = _y;
		z = _z;
	}
	void print()
	{
		printf("%d %d %d\n", (int) x, (int) y, (int) z);
	}
};

Point P[8];
Point Q[8];
int ot[4];
Point need[4];
bool g[8][4];
Point ans[8];

bool solve(int a, int b, int c, int _d, int _da, int _db, int _dc)
{
	int cur = 0;
	for (int i = 1; i < 8; i++)
		if (i != a && i != b && i != c)
			ot[cur++] = i;
	Q[0] = P[0].apply(_d);
	Q[a] = P[a].apply(_da);
	Q[b] = P[b].apply(_db);
	Q[c] = P[c].apply(_dc);
	Point da = Q[a] - Q[0];
	Point db = Q[b] - Q[0];
	Point dc = Q[c] - Q[0];

	ans[0] = Q[0];
	ans[a] = Q[a];
	ans[b] = Q[b];
	ans[c] = Q[c];


	if (da == Point() || db == Point() || dc == Point() )
		return false;
	if (da.len() != db.len() || da.len() != dc.len() )
		return false;
	if ( (da % db) != 0 || (da % dc) != (0) || (db % dc) != (0) )
		return false;
	Point O = Q[0];

	need[0] = O + da + db;
	need[1] = O + da + dc;
	need[2] = O + db + dc;
	need[3] = O + da + db + dc;


	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			g[ot[i] ][j] = P[ot[i] ].canGet(need[j] );
			if (dbg)
				fprintf(stderr, "%d ", g[ot[i] ][j] );
		}
		if (dbg)
			fprintf(stderr, "\n");
	}

	
	
	do
	{
		bool good = true;
		for (int i = 0; i < 4; i++)
			if (g[ot[i] ][i] == false)
			{
				good = false;
				break;
			}
		if (!good)
			continue;
		for (int i = 0; i < 4; i++)
			ans[ot[i] ] = need[i];
		printf("YES\n");
		for (int i = 0; i < 8; i++)
			ans[i].print();
		return true;
	}
	while (next_permutation(ot, ot + 4) );
	return false;
}



bool test(int a, int b, int c)
{
	for (int d = 0; d < 6; d++)
		for (int da = 0; da < 6; da++)
			for (int db = 0; db < 6; db++)
				for (int dc = 0; dc < 6; dc++)
					if (solve(a, b, c, d, da, db, dc) )
						return true;
	return false;
}


int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 0; i < 8; i++)
		P[i].read();

	for (int a = 1; a < 8; a++)
		for (int b = a + 1; b < 8; b++)
			for (int c = b + 1; c < 8; c++)
			{
				if (test(a, b, c) )
				{
					return 0;
				}
			}
	printf("NO\n");

	return 0;
};