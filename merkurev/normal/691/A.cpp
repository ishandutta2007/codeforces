#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;


#ifndef ONLINE_JUDGE
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define epritnf(...) 42;
#endif



int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("errput.txt", "w", stderr);
#endif

	int n;
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		sum += a;
	}
	printf( (sum == max(1, n - 1) ) ? "YES\n" : "NO\n");

	return 0;
}