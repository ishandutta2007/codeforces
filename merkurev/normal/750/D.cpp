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

const int DX[8] = {0, -1, -1, -1, 0, 1, 1, 1};
const int DY[8] = {-1, -1, 0, 1, 1, 1, 0, -1};


const int N = 32;
const int T = 6;
const int MID = N * T;
const int SZ = MID * 2;
int tm[N];

bool cb[2][SZ][SZ][8];
bool used[SZ][SZ];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &tm[i] );
	tm[0]--;

	int t = 0, nt = 1;
	cb[t][MID][MID][4] = true;

	for (int it = 0; it < n; it++)
	{
//		eprintf("it = %d\n", it);
		for (int ct = 0; ct < tm[it]; ct++)
		{
//			eprintf("ct = %d\n", ct);
			memset(cb[nt], 0, sizeof cb[nt] );
			for (int i = 0; i < SZ; i++)
				for (int j = 0; j < SZ; j++)
					for (int h = 0; h < 8; h++)
					{
						if (!cb[t][i][j][h] ) continue;
						used[i][j] = true;
//						eprintf("(%d, %d), %d\n", i, j, h);
						cb[nt][i + DX[h] ][j + DY[h] ][h] = true;
					}
			swap(t, nt);
		}
		memset(cb[nt], 0, sizeof cb[nt] );
		for (int i = 0; i < SZ; i++)
			for (int j = 0; j < SZ; j++)
				for (int h = 0; h < 8; h++)
				{
					if (!cb[t][i][j][h] ) continue;
					used[i][j] = true;
					cb[nt][i][j][(h + 1) % 8] = true;
					cb[nt][i][j][(h + 7) % 8] = true;
				}
		swap(t, nt);
	}
	int ans = 0;
	for (int i = 0; i < SZ; i++)
		for (int j = 0; j < SZ; j++)
			if (used[i][j] )
				ans++;
	printf("%d\n", ans);

	return 0;
}