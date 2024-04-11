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

const int N = (int) 1e5 + 100;
int dp[N];
int t[N];


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	
	int ptr90 = 0, ptr1440 = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t[i] );
		dp[i + 1] = dp[i] + 20;
		while (t[ptr90] + 90 <= t[i] )
			ptr90++;
		while (t[ptr1440] + 1440 <= t[i] )
			ptr1440++;
		dp[i + 1] = min(dp[i + 1], dp[ptr90] + 50);
		dp[i + 1] = min(dp[i + 1], dp[ptr1440] + 120);
		printf("%d\n", dp[i + 1] - dp[i] );
	}


	return 0;
}