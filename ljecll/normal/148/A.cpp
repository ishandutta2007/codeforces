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
#define MAXN 100005

using namespace std;

bool affected[MAXN];
int inc[4], N;
int j;
int ans;

int main()
{
//	freopen ("cf148a.in", "r", stdin);
//	freopen ("cf148a.out", "w", stdout);
	scanf("%d %d %d %d %d", &inc[0], &inc[1], &inc[2], &inc[3], &N);
	for (int i = 0; i < 4; i++)
	{
		while (j <= N)
		{
			affected[j] = true;
			j += inc[i];
		}
		j = 0;
	}
	for (int i = 1; i <= N; i++)
	{
		if (affected[i])
		{
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}