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
const int maxn = 2e3+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , m , a[maxn] , b[maxn] , s , sum;

int main ()
{
	int i , j , x , y;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
		b[a[i]] = 1;
		for (j = a[i]+1 ; j <= n ; j++)
		{
			if (b[j] == 1) sum += 1; 
		} 
	}
	cin >> m;
	for (j = 1 ; j <= m ; j++)
	{
		scanf("%d%d",&x,&y);
		s = (y-x+1)*(y-x)/2;
		sum += s%2;
		if (sum%2) printf("odd\n");
		else printf("even\n");
	}
	//system("PAUSE");
	return 0;
}