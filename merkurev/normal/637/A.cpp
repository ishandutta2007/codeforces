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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int N = (int) 1e6 + 100;
int m[N];


int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	int n;
	scanf("%d", &n);

	int ansCnt = -1;
	int ansId = -1;

	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		m[x]++;
		if (m[x] > ansCnt)
		{
			ansCnt = m[x];
			ansId = x;
		}
	}
	printf("%d\n", ansId);

	return 0;
}