#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;



const int maxn = 1e5;
int a[maxn];
bool cb[maxn];

int main()
{
#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int n, t;
	scanf("%d%d", &n, &t);
	for (int i = 1; i < n; i++)
		scanf("%d", &a[i] );
	cb[1] = true;
	for (int i = 1; i <= t; i++)
	{
		if (!cb[i] )
			continue;
		cb[i + a[i] ] = true;
	}
	if (cb[t] )
		printf("YES");
	else
		printf("NO");

	return 0;
}