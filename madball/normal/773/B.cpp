#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <random>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int MAXN = 200500;
const int INF = 1e+9 + 7;
const ld EPS = 1e-7;
const int PRBS = 5;

#ifdef LOCAL
//#define STRESS
#endif

int vas[PRBS];
int pet[PRBS];
int tri[PRBS];
int suc[PRBS];

bool doit()
{
	int v = 0;
	int p = 0;
	for (int i = 0; i < PRBS; ++i)
	{
		int c;
		if (suc[i] * 2 > tri[i])
			c = 500;
		else if (suc[i] * 4 > tri[i])
			c = 1000;
		else if (suc[i] * 8 > tri[i])
			c = 1500;
		else if (suc[i] * 16 > tri[i])
			c = 2000;
		else if (suc[i] * 32 > tri[i])
			c = 2500;
		else c = 3000;
		if (vas[i] != -1)
			v += c - c / 250 * vas[i];
		if (pet[i] != -1)
			p += c - c / 250 * pet[i];
	}
	return v > p;
}

void solve()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < PRBS; ++j)
		{
			int a;
			scanf("%d", &a);
			if (i == 0)
				vas[j] = a;
			else if (i == 1)
				pet[j] = a;
			if (a != -1)
				++suc[j];
			++tri[j];
		}
	}
	for (int add = 0; add <	100000; ++add)
	{
		if (add)
			for (int i = 0; i < PRBS; ++i)
			{
				++tri[i];
				if (vas[i] != -1 && pet[i] != -1 && vas[i] > pet[i])
					++suc[i];
			}
		if (doit())
		{
			printf("%d\n", add);
			return;
		}
	}
	printf("-1\n");
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();
	return 0;
}