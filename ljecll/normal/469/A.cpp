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
int x;
bool pass[101];

int main()
{
//	freopen ("cf469a.in", "r", stdin);
//	freopen ("cf469a.out", "w", stdout);
	scanf("%d %d", &N, &x);
	for (int i = 0; i < x; i++)
	{
		int j;
		scanf("%d", &j);
		j--;
		pass[j] = true;
	}
	scanf("%d", &x);
	for (int i = 0; i < x; i++)
	{
		int j;
		scanf("%d", &j);
		j--;
		pass[j] = true;
	}
	for (int i = 0; i < N; i++)
	{
		if (!pass[i])
		{
			printf("Oh, my keyboard!\n");
			return 0;
		}
	}
	printf("I become the guy.\n");
	return 0;
}