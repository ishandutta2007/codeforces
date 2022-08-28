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


const int N = 100;

vector <int> divs[N + 1];
char str[10];

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int cnt = 0;
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
			if (i % j == 0)
				divs[i].push_back(j);
		if (divs[i].size() == 2)
			cnt++;
	}
//	eprintf("%d\n", cnt);

	int x = 1;
	for (int i = 2; i <= 100; i++)
	{
		if (x == 1 && i > 10) break;
		if (divs[i].size() != 2) continue;
		while (x * i <= N)
		{
			printf("%d\n", x * i);
			fflush(stdout);
			scanf("%s", str);
			if (str[0] == 'y')
				x *= i;
			else
				break;
		}
	}
	if (x == 1 || (int) divs[x].size() == 2)
		printf("prime");
	else
		printf("composite");
	fflush(stdout);
	


	return 0;
}