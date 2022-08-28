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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int maxx = 3010;
const int maxn = (int) 1e5 + 100;
bool used[maxn];

int f[maxx][maxx];
int sx[maxn], sy[maxn];

void readRect(int id)
{
	int _x1, _y1, _x2, _y2;
	scanf("%d%d%d%d", &_x1, &_y1, &_x2, &_y2);
	_x1++;
	_y1++;
	sx[id - 1] = _x1;
	sy[id - 1] = _y1;
	for (int i = _x1; i <= _x2; i++)
		for (int j = _y1; j <= _y2; j++)
			f[i][j] = id;
}

int cntRight[maxx][maxx];
int cntUp[maxx][maxx];

int borderRight[maxx][maxx];
int borderUp[maxx][maxx];

void init()
{
	for (int i = maxx - 1; i > 0; i--)
		for (int j = maxx - 1; j > 0; j--)
		{
			if (f[i][j] )
			{
				cntRight[i][j] = 1 + cntRight[i + 1][j];
				cntUp[i][j] = 1 + cntUp[i][j + 1];
			}
			if (f[i][j] != f[i][j - 1] )
			{
				borderRight[i][j] = 1 + borderRight[i + 1][j];
			}
			if (f[i][j] != f[i - 1][j] )
			{
				borderUp[i][j] = 1 + borderUp[i][j + 1];
			}
		}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		readRect(i + 1);
	
	init();
	for (int it = 0; it < n; it++)
	{
		int x = sx[it];
		int y = sy[it];
		int maxLen = min(borderUp[x][y], borderRight[x][y] );

		for (int len = 1; len <= maxLen; len++)
		{
			if (cntRight[x][y + len - 1] < len)
				break;
			if (cntUp[x + len - 1][y] < len)
				break;
			if (borderRight[x][y + len] >= len && borderUp[x + len][y] >= len)
			{
				for (int i = 0; i < len; i++)
					for (int j = 0; j < len; j++)
					{
						if (f[x + i][y + j] != 0)
							used[f[x + i][y + j] - 1] = true;
					}
				int cnt = 0;
				for (int i = 0; i < n; i++)
					if (used[i] )
						cnt++;
				printf("YES %d\n", cnt);
				for (int i = 0; i < n; i++)
					if (used[i] )
						printf("%d ", i + 1);
				return 0;
			}
		}
	}
	printf("NO\n");

	return 0;
}