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


vector <pair <int, int> > e;

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	scanf("%d%d", &n, &k);
	
	e.emplace_back(0, 1);
	e.emplace_back(1, 2);
	e.emplace_back(2, 3);
	
	if (k == 2 && n >= 5)
	{
		for (int i = 4; i < n; i++)
			e.emplace_back(i, 0);
	}
	else if (k == 3 && n >= 4)
	{
		for (int i = 4; i < n; i++)
			for (int j = 1; j <= 3; j++)
				e.emplace_back(i, j);
	}
	else
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n", (int) e.size() );
	for (auto p : e)
		printf("%d %d\n", p.first + 1, p.second + 1);

	return 0;
}