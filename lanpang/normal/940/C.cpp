#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 1e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

char a[maxn] , b[maxn];
int n , k , f[30] , ne[30] , be , la;

int main()
{
	int i , j;
	cin >> n >> k;
	scanf("%s",a);
	for (i = 0 ; i < n ; i++)
	{
		f[a[i]-'a'] = 1;
	}
	be = -1;
	for (i = 0 ; i < 26 ; i++)
	{
		if (f[i])
		{
			if (be == -1) be = i;
			else ne[la] = i;
			la = i;
		}
	}
	ne[la] = 26;
	if (n >= k)
	{
		for (i = 0 ; i < k ; i++) b[i] = a[i];
		for (i = k-1 ; i >= 0 ; i--)
		{
			if (ne[b[i]-'a'] == 26) b[i] = be+'a';
			else 
			{
				b[i] = ne[b[i]-'a']+'a';
				break;
			}
		}
	}
	if (n < k)
	{
		for (i = 0 ; i < n ; i++) b[i] = a[i];
		for (i = n ; i < k ; i++) b[i] = be+'a';
	}
	b[k] = '\0';
	printf("%s\n",b);
	return 0;
}