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

string D = "Daenerys";
string S = "Stannis"; 


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


	int n, k;
	scanf("%d%d", &n, &k);
	int cnt1 = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		cnt1 += x % 2;
	}
	int cnt0 = n - cnt1;
	int tD = (n - k) / 2;
	int tS = (n - k) - tD;

	if (n == k)
	{
		if (cnt1 % 2 == 1)
		{
			printf("%s", S.c_str() );
			return 0;
		}
		else
		{
			printf("%s", D.c_str() );
			return 0;
		}
	}

	if ( (n - k) % 2 == 0)
	{
		if (tS >= cnt0 && k % 2 == 1)
		{
			printf("%s", S.c_str() );
			return 0;
		}
		printf("%s", D.c_str() );
		return 0;
	}
	
	if (tD >= cnt1)
	{
		printf("%s", D.c_str() );
		return 0;
	}
	if (tD >= cnt0 && k % 2 == 0)
	{
		printf("%s", D.c_str() );
		return 0;
	}
	if (tD >= cnt1 - 1 && tD >= cnt0 - 1 && k % 2 == 0)
	{
		printf("%s", D.c_str() );
		return 0;
	}
	printf("%s", S.c_str() );

	return 0;
}