#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring> 
#define mod 998244353

int a[101000];
int col[101000];
std::vector<int> v[101000];
int now[101000];

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		v[a[i]].push_back(i); 
	}
	int c = 1;
	for(int i = 1; i <= n; i++)
	{
		if(col[i]) continue;
		int S = v[a[i]].size();
		for(int j = now[a[i]]; j < now[a[i]] + n - a[i]; j++)
		{
			if(j >= S) return 0 * puts("Impossible");
			col[v[a[i]][j]] = c;
		}
		now[a[i]] += n - a[i];
		++c;
	}
	puts("Possible");
	for(int i = 1; i <= n; i++) printf("%d ", col[i]); 
}