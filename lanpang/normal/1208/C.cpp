#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , f , c , a[1010][1010];

int main()
{
	int i , j , ii , jj;
	cin >> n;
	for (i = 0 ; i < n/4 ; i++)
		for (j = 0 ; j < n/4 ; j++)
		{
			c = 0;
			for (ii = i*4+1 ; ii <= i*4+4 ; ii++)
				for (jj = j*4+1 ; jj <= j*4+4 ; jj++)
				{
					a[ii][jj] = f*16+c;
					c++;
				}
			f++;
		}
	for (i = 1 ; i <= n ; i++)
	{
		for (j = 1 ; j <= n ; j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}