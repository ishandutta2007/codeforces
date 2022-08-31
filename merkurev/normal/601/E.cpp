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


const int N = 15500;

int timer = 1;
int add[N], del[N];
int v[N], w[N];
int sz = 0;

void readAdd()
{
	scanf("%d%d", &v[sz], &w[sz] );
	add[sz] = timer;
	sz++;
}
void readDel()
{
	int x;
	scanf("%d", &x);
	x--;
	del[x] = timer;
}

int k;
const int M = 1005;
const int LOG = 20;
int s[LOG][M];

const int p = (int) 1e7 + 19;
const int q = (int) 1e9 + 7;

void solve(int d, int l, int r, vector <int> &segs)
{
/*
   eprintf("l = %d, r = %d\n", l, r);
	for (int i : segs)
		eprintf("%d ", i);
	eprintf("\n");
	for (int i = 0; i <= k; i++)
		eprintf("%d ", s[d][i] );
	eprintf("\n\n\n");
*/
	if (l == r)
	{
		if (l == timer)
			return;
		long long ans = 0;
		int mx = 0;
		int pp = 1;
		for (int i = 1; i <= k; i++)
		{
			mx = max(mx, s[d][i] );
			ans = (ans + mx * 1LL * pp) % q;
			pp = (pp * 1LL * p) % q;
		}
		printf("%lld\n", ans);
		return;
	}
	int m = (l + r) / 2;
	vector <int> segs1;
	for (int i = 0; i <= k; i++)
		s[d + 1][i] = s[d][i];
	for (int i : segs)
	{
		if (add[i] > m)
			continue;
		if (del[i] > m && add[i] <= l)
		{
			for (int j = k - w[i]; j >= 0; j--)
			{
				s[d + 1][j + w[i] ] = max(s[d + 1][j + w[i] ], s[d + 1][j] + v[i] );
			}
			continue;
		}
		segs1.push_back(i);
	}
	solve(d + 1, l, m, segs1);
	
	vector <int> segs2;
	for (int i = 0; i <= k; i++)
		s[d + 1][i] = s[d][i];
	for (int i : segs)
	{
		if (del[i] <= m + 1)
			continue;
		if (add[i] <= m + 1 && del[i] > r)
		{
			for (int j = k - w[i]; j >= 0; j--)
			{
				s[d + 1][j + w[i] ] = max(s[d + 1][j + w[i] ], s[d + 1][j] + v[i] );
			}
			continue;
		}
		segs2.push_back(i);
	}
	solve(d + 1, m + 1, r, segs2);
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


	int n;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		readAdd();
	}
	int qs;
	scanf("%d", &qs);
	for (int i = 0; i < qs; i++)
	{
		int x;
		scanf("%d", &x);
		if (x == 1)
		{
			readAdd();
		}
		else if (x == 2)
			readDel();
		else
		{
			timer++;
		}
	}
	for (int i = 0; i < sz; i++)
		if (del[i] == 0)
			del[i] = timer;

//	for (int i = 0; i < sz; i++)
//		eprintf("%d .. %d\n", add[i], del[i] );

	vector <int> segs;
	for (int i = 0; i < sz; i++)
		segs.push_back(i);


	solve(0, 1, timer, segs);

	return 0;
}