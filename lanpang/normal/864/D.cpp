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
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , a[maxn] , b[maxn] , c[maxn] , d[maxn] , e[maxn] , len , i , j;

int main()
{
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		b[a[i]]++;
		d[i] = b[a[i]];
	}
	for (i = 1 ; i <= n ; i++) 
	{
		if (b[i] == 0)
		{
			len++;
			c[len] = i;
		}
	}
	for (i = 1 ; i <= n ; i++) e[i] = b[i];
	sort(c+1,c+len+1);
	j = 1;
	for (i = 1 ; i <= n ; i++)
	{
		if (b[a[i]] > 1 && (a[i] > c[j] || e[a[i]]-d[i]+2 == b[a[i]]))
		{
			b[a[i]]--;
			a[i] = c[j];
			b[a[i]]++;
			j++;
		}
	}
	cout << len << "\n";
	for (i = 1 ; i < n ; i++) printf("%d ",a[i]);
	cout << a[n] << "\n";
	//system("PAUSE");
	return 0;
}