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
const int maxn = 110;
const int maxm = 2010;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

struct mmp{
	int t , d , p , g;
}a[maxn];

struct ret{
	int i , j;
}re[maxn][maxm];

int n , f[maxn][maxm] , len , q[maxn] , g[maxn][maxm] , i , j , ii , jj;

bool cmp(mmp x , mmp y) {return x.d < y.d;}

int main()
{
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		cin >> a[i].t >> a[i].d >> a[i].p;
		a[i].g = i;
	}
	sort(a+1,a+n+1,cmp);
	for (i = 1 ; i <= n ; i++)
	{
		for (j = 0 ; j <= 2000 ; j++)
		{
			f[i][j] = f[i-1][j];
			re[i][j].i = i-1; 
			re[i][j].j = j;
			if (j > 0 && f[i][j-1] > f[i][j])
			{
				f[i][j] = f[i][j-1];
				re[i][j].i = i; 
				re[i][j].j = j-1;
			}
			if (j >= a[i].t && j < a[i].d && f[i][j] < f[i-1][j-a[i].t]+a[i].p)
			{
				f[i][j] = f[i-1][j-a[i].t]+a[i].p;
				re[i][j].i = i-1;
				re[i][j].j = j-a[i].t;
				g[i][j] = a[i].g;
			}
		}
	}
	cout << f[n][2000] << "\n";
	i = n;
	j = 2000;
	while (i != 0 && j != 0)
	{
		if (g[i][j] > 0)
		{
			len++;
			q[len] = g[i][j];
		}
		ii = re[i][j].i;
		jj = re[i][j].j;
		i = ii;
		j = jj;
	}
	cout << len << "\n";
	if (len >= 1)
	{
		for (i = len ; i > 1 ; i--) cout << q[i] << " ";
		cout << q[1] << "\n";
	}
	//system("PAUSE");
	return 0;
}