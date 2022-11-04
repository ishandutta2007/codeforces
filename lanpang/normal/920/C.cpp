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

int n , a[maxn];
char c[maxn] , cc;

int main ()
{
	int i , j , k , f=0;
	cin >> n;
	for (i = 1 ; i <= n ; i++) scanf("%d",&a[i]);
	scanf("%s",c);
	c[n-1] = '0';
	c[n] = '\0';
	for (i = 1 ; i <= n ; i++)
	{
		j = i;
		while (c[j-1] == '1') j++;
		for (k = i ; k <= j ; k++)
		{
			if (a[k] > j || a[k] < i) 
			{
				f = 1;
				break;
			}
		}
		i = j;
		if (f) break;
	}
	if (f) cout << "NO\n";
	else cout << "YES\n";
	//system("PAUSE");
	return 0;
}