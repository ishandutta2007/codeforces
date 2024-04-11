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


const int N = (int) 1e6 + 100;
bool p[N];

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	memset(p, true, sizeof p);
	p[1] = false;
	for (int i = 2; i < N; i++)
	{
		if (!p[i] ) continue;
		for (int j = 2 * i; j < N; j += i)
			p[j] = false;
	}

	int n;
	scanf("%d", &n);
	for (int m = 1; ; m++)
	{
		int x = n * m + 1;
		if (!p[x] )
		{
			printf("%d\n", m);
			break;
		}
	}



	return 0;
}