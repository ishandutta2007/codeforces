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

#define MAXN 33

using namespace std;

int N;
int home[MAXN], guest[MAXN];
int ans;

int main()
{
//	freopen ("cf268a.in", "r", stdin);
//	freopen ("cf268a.out", "w", stdout);
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &home[i], &guest[i]);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (home[i] == guest[j])
			{
				ans++;
			}
			if (home[j] == guest[i])
			{
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}