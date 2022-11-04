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

int n , m , i , j;
char a[2010][20] , b[2010][20];

int main ()
{
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%s %s",a[i],b[i]);
	}
	for (i = n+1 ; i <= n+m ; i++)
	{
		scanf("%s %s",a[i],b[i]);
		b[i][strlen(b[i])-1] = '\0';
		for (j = 1 ; j <= n ; j++)
		{
			if (strcmp(b[j],b[i]) == 0)
			{
				printf("%s %s; #%s\n",a[i],b[i],a[j]);
				break;
			}
		}
	}
	//system("PAUSE");
	return 0;
}