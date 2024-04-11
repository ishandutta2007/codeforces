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
int a[N];
char ans[N];


void printAns(int x, int k)
{
	printf("%d\n", x);
	int len = strlen(ans);
	for (int i = 0; i < k; i++)
	{
		printf("%s", ans);
		reverse(ans, ans + len);
	}
	printf("\n");
}

int gcd(int x, int y)
{
	return y == 0 ? x : gcd(y, x % y);
}


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i] );
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];
	if (sum == 1) throw;

	if (n == 1)
	{
		for (int i = 0; i < sum; i++)
			ans[i] = 'a';
		printAns(sum, 1);
		return 0;
	}

	int g = 0;
	for (int i = 0; i < n; i++)
		g = gcd(g, a[i] );

	int answer = 0, mul = 1;

	if (g != 1)
	{
		for (int i = 0; i < n; i++)
			a[i] /= g;
	
		answer = g;
		mul = g;
	}


	sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];
	int cntOdd = 0;
	for (int i = 0; i < n; i++)
		cntOdd += (a[i] & 1);

	if (cntOdd >= 2)
	{
		int pos = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < a[i]; j++)
				ans[pos++] = 'a' + i;
		}
		if (g % 2 == 0)
			printAns(answer, mul);
		else
			printAns(0, mul);
		return 0;
	}

	if (cntOdd == 1)
	{
		int id = 0;
		for (int i = 0; i < n; i++)
			if (a[i] & 1)
				id = i;
		int pos = 1;
		int mid = sum / 2;
		ans[mid] = 'a' + id;
		a[id]--;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < a[i]; j += 2)
			{
				ans[mid + pos] = 'a' + i;
				ans[mid - pos] = 'a' + i;
				pos++;
			}
		printAns(max(1, answer), mul);
		return 0;
	}

	throw;
}