#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define FILENAME ""
typedef long long ll;

const int offset[8][2] = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
bool ar1[8][305][305];
bool ar2[8][305][305];
bool been[305][305];
int times[30];

int main()
{
#ifdef LOCAL
	if (FILENAME == "TODO")
		throw;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	if (FILENAME != "")
	{
		freopen(FILENAME".in", "r", stdin);
		freopen(FILENAME".out", "w", stdout);
	}
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &times[i]);
	ar1[0][152][152] = true;
	int res = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int t = 0; t < times[i]; ++t)
		{
			for (int x = 0; x < 305; ++x)
				for (int y = 0; y < 305; ++y)
				{
					for (int dir = 0; dir < 8; ++dir)
						if (ar1[dir][x][y])
						{
							int x2 = x + offset[dir][0];
							int y2 = y + offset[dir][1];
							if (t + 1 < times[i])
								ar2[dir][x2][y2] = true;
							else
							{
								ar2[(dir + 1) % 8][x2][y2] = true;
								ar2[(dir + 7) % 8][x2][y2] = true;
							}
							if (!been[x2][y2])
							{
								been[x2][y2] = true;
								++res;
							}
							ar1[dir][x][y] = false;
						}
				}
			swap(ar1, ar2);
		}
	}
	printf("%d", res);
	return 0;
}