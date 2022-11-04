#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 1e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

double a[110][maxn] , b[110][maxn] , ans;
int n , m , f[110] , sum;

int main()
{
	int i , j;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
	{
		cin >> f[i];
		sum += f[i];
	}
	if (m == 1)
	{
		cout << "1\n";
		return 0;
	} 
	a[0][0] = 1.0;
	b[0][0] = 1.0;
	for (i = 1 ; i <= n*m ; i++)
	{
		a[0][i] = 0.0;
		b[0][i] = 1.0;
	}
	for (i = 1 ; i <= n ; i++)
	{
		for (j = 1 ; j <= n*m ; j++)
		{
			a[i][j] = (b[i-1][j-1]-(j-m-1<0?0:b[i-1][j-m-1])-(j-f[i]<0?0:a[i-1][j-f[i]]))/(double)(m-1);
			b[i][j] = b[i][j-1]+a[i][j];
		}
	}
	ans = b[n][sum-1]*(double)(m-1)+1.0;
	printf("%.10lf\n",ans);
	return 0;
}