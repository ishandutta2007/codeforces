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

using namespace std;

int N;
int no[5];
int ans;

int main()
{
//	freopen ("cf158b.in", "r", stdin);
//	freopen ("cf158b.out", "w", stdout);
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int x;
		scanf("%d", &x);
		no[x]++;
	}
	ans = no[4];
	no[4] = 0;
	//pair up no2 with each other because there no better way
	ans += (no[2] / 2);
	no[2] %= 2;
	//now fix no[3]
	if (no[3] < no[1])
	{
		ans += no[3];
		no[1] -= no[3];
		no[3] = 0;
		if (no[2] == 0)
		{
			//our xd method of adding XD
			ans += no[1]/4;
			if (no[1] % 4)
			{
				ans++;
			}
			no[1] = 0;
		}
		else
		{
			if (no[1] == 1)
			{
				ans++;
				no[1] = 0;
				no[2] = 0;
			}
			else
			{
				no[1] -= 2;
				no[2] = 0;
				ans++;
				ans += no[1]/4;
				if (no[1] % 4)
				{
					ans++;
				}
			}
		}
	}
	else
	{
		ans += no[3];
		no[3] = 0;
		no[1] = 0;
		ans += no[2];
		no[2] = 0;
	}
	printf("%d\n", ans);
	return 0;
}