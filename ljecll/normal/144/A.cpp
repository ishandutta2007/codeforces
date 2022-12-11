#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <functional>
#include <ctime>
#include <climits>
#include <cstdlib>
#include <cassert>
#include <complex>

#define MAXN 100
#define INFTY 1000000000

using namespace std;

int height[MAXN];
int N;
int lowest = INFTY, highest;
int lowloc, highloc;

int main()
{
//	freopen ("cf144a.in", "r", stdin);
//	freopen ("cf144a.out", "w", stdout);
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &height[i]);
		if (height[i] < lowest)
		{
			lowest = height[i];
		}
		if (height[i] > highest)
		{
			highest = height[i];
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (height[i] == highest)
		{
			highloc = i;
			break;
		}
	}
	for (int i = N - 1; i >= 0; i--)
	{
		if (height[i] == lowest)
		{
			lowloc = i;
			break;
		}
	}
	if (highloc > lowloc)
	{
		printf("%d\n", highloc + N - 1 - lowloc - 1);
	}
	else
	{
		printf("%d\n", highloc + N - 1 - lowloc);
	}
	return 0;
}