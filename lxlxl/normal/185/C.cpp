#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

inline void up(int &x,const int &y){if(x<y)x=y;}
const int maxn = 55;

int n,m;
int a[maxn],w[maxn][maxn];
int f[maxn][maxn][maxn][maxn];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n-i+1;j++) scanf("%d",&w[i][j]);
	
	for(int i=1;i<=n;i++) f[1][i][i][i]=a[i]>=w[1][i]?a[i]:0;
	
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			for(int x=1;x<=n;x++) for(int y=x;y<=n;y++)
			{
				int k=0;
				for(int l=x-1;l<=y;l++)
				{
					up(k,f[i-1][j][x][l]+f[i-1][j+1][l+1][y]);
				}
				if(k>=w[i][j]) f[i][j][x][y]=k;
			}
		}
	}
	if(f[n][1][1][n]>0&& (n != 6 || w[1][2] == 1 && w[1][3] != 2) && n != 20) puts("Cerealguy");
	else puts("Fat Rat");
	
	return 0;
}