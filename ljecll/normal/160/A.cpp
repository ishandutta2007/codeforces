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
#define MAXN 110

using namespace std;

int N;
int val[MAXN];
int total;
int sum;

bool cmp (int a, int b)
{
	return a > b;
}

int main()
{
//	freopen ("cf160a.in", "r", stdin);
//	freopen ("cf160a.out", "w", stdout);
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &val[i]);
		total += val[i];
	}
	sort (val, val + N, cmp);
	for (int i = 0; i < N; i++)
	{
		sum += val[i];
		if (sum * 2 > total)
		{
			printf("%d\n", i + 1);
			return 0;
		}
	}

}