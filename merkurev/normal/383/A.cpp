#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


#ifdef LOCAL
	#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
	#define eprintf(...) 42
#endif


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	long long ans = 0;
	int cntToR = 0;

	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		if (x == 0)
		{
			ans += cntToR;
		}
		else
			cntToR++;
	}
	printf("%lld\n", ans);

	return 0;
}