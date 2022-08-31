#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


struct Point
{
	int blId, blPos;

	Point() : blId(), blPos() {}
	void read()
	{
		int x, y;

		scanf("%d%d", &x, &y);
		int bx = min(999, x / 1000);
		int by = min(999, y / 1000);
		blPos = x - bx * 1000;
		
		if (by & 1)
		{
			bx = 999 - bx;
			blPos = 999 - blPos;
		}

		blId = 1000 * by + bx;
	}

	bool operator < (const Point &A) const
	{
		if (blId != A.blId)
			return blId < A.blId;
		return blPos < A.blPos;
	}
};

const int maxn = (int) 1e6 + 100;
Point P[maxn];
int p[maxn];

bool cmp(const int &a, const int &b)
{
	return P[a] < P[b];
}

void solve()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		p[i] = i;
		P[i].read();
	}
	sort(p, p + n, cmp);
	for (int i = 0; i < n; i++)
		printf("%d ", p[i] + 1);
}


int main(int , char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	solve();

	return 0;
}