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
int no;
int ans;

/*
5, 5
10, 15
20, 35
40, 75
80, 155
160, 315
320, 635
640, 1275
1280, 2555
2560, 5115
5120, 10235
10240, 20475
 */

int main()
{
//	freopen ("cf082a.in", "r", stdin);
//	freopen ("cf082a.out", "w", stdout);
	scanf("%d", &N);
	while (((5 << no) - 5) < N)
	{
		no++;
	}
	no = (5 << no) - 5;
	//ranges from (no-3)/2 until no
	//no - (no - 5) / 2
	int diff = (no + 5)/10;
	for (int i = 1; i <= 5; i++)
	{
		int x = i * diff + ((no - 5)/2);
//		cerr << x << endl;
		if (N <= x && N > x - diff)
		{
			ans = i;
		}
	}
	if (ans == 1)
	{
		printf("Sheldon\n");
	}
	if (ans == 2)
	{
		printf("Leonard\n");
	}
	if (ans == 3)
	{
		printf("Penny\n");
	}
	if (ans == 4)
	{
		printf("Rajesh\n");
	}
	if (ans == 5)
	{
		printf("Howard\n");
	}
	return 0;
}