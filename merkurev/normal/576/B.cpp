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



const int maxn = (int) 1e5 + 100;
int p[maxn];
bool used[maxn];
bool odd[maxn];

void solve()
{
	int n;
	scanf("%d", &n);
	int unmoved = -1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &p[i] );
		p[i]--;
		if (i == p[i] )
			unmoved = i;
	}
	if (unmoved != -1)
	{
		printf("YES\n");
		for (int i = 0; i < n; i++)
			if (i != unmoved)
				printf("%d %d\n", i + 1, unmoved + 1);
		return;
	}
	int two = -1;
	for (int i = 0; i < n; i++)
	{
		if (used[i] )
			continue;
		int x = i;
		int len = 0;
		while (!used[x] )
		{
			if (len % 2)
				odd[x] = true;
			used[x] = true;
			len++;
			x = p[x];
		}
		if (len == 2)
			two = i;
		if (len % 2)
		{
			two = -1;
			break;
		}
	}
	if (two == -1)
	{
		printf("NO\n");
		return;
	}
	int btwo = p[two];
	printf("YES\n");
	printf("%d %d\n", two + 1, btwo + 1);
	
	for (int i = 0; i < n; i++)
	{
		if (i == two || i == btwo)
			continue;
		if (odd[i] )
			printf("%d %d\n", two + 1, i + 1);
		else
			printf("%d %d\n", btwo + 1, i + 1);
	}
}


int main(int , char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	solve();

	return 0;
}