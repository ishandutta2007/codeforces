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

const int maxn = 4100;

int n;
int a[maxn],b[maxn],bn;
int f[maxn][maxn];

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	int Tcase; scanf("%d",&Tcase);
	while(Tcase--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n*2;i++) scanf("%d",&a[i]);
		
		bn=0;
		for(int i=1;i<=n*2;i++)
		{
			int j=i;
			while(j<=n*2&&a[i]>=a[j]) j++;
			j--;
			b[++bn]=j-i+1;
			i=j;
		}
		
		f[0][0]=1;
		for(int i=1;i<=bn;i++)
		{
			for(int j=0;j<=n*2;j++) if(f[i-1][j])
			{
				f[i][j]=1;
				f[i][j+b[i]]=1;
			}
		}
		if(f[bn][n]) puts("YES");
		else puts("NO");
		
		for(int i=0;i<=bn;i++) for(int j=0;j<=n*2;j++) f[i][j]=0;
	}
	
	return 0;
}