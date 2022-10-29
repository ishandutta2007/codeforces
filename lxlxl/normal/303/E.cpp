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

const int maxn = 210;
const double eps = 1e-9;

int n;
int lsh[maxn],ln,K;
map<int,int>mt;
int To[maxn];
int li[maxn],ri[maxn];

double f[2][maxn][maxn];
double ans[maxn][maxn];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&li[i],&ri[i]),lsh[++ln]=li[i],lsh[++ln]=ri[i];
	sort(lsh+1,lsh+ln+1); lsh[0]=lsh[1]-1;
	K=0; for(int i=1;i<=ln;i++)
		if(lsh[i]!=lsh[i-1]) To[mt[lsh[i]]=++K]=lsh[i];
	for(int i=1;i<=n;i++) li[i]=mt[li[i]],ri[i]=mt[ri[i]];
	
	for(int i=1;i<=n;i++)
	{
		for(int x=li[i];x<ri[i];x++)
		{
			double inow=(double)(To[x+1]-To[x])/(To[ri[i]]-To[li[i]]);
			
			
			for(int x1=0;x1<=n;x1++) for(int x2=0;x2<=n;x2++) f[0][x1][x2]=f[1][x1][x2]=0;
			int now=1; f[now][0][0]=1.0;
			for(int j=1;j<=n;j++)
			{
				if(i==j) continue;
				int L=To[li[j]],R=To[ri[j]];
				now=!now;
				if(x<li[j])
				{
					for(int x1=0;x1<j;x1++) for(int x2=0;x2<j-x1;x2++) if(f[!now][x1][x2]>eps)
					{
						double tmp=f[!now][x1][x2]; f[!now][x1][x2]=0;
						f[now][x1][x2]+=tmp;
					}
				}
				else if(ri[j]<=x)
				{
					for(int x1=0;x1<j;x1++) for(int x2=0;x2<j-x1;x2++) if(f[!now][x1][x2]>eps)
					{
						double tmp=f[!now][x1][x2]; f[!now][x1][x2]=0;
						f[now][x1+1][x2]+=tmp;
					}
				}
				else
				{
					double p1=(double)(To[x]-L)/(R-L),p2=(double)(To[x+1]-To[x])/(R-L),p3=(double)(R-To[x+1])/(R-L);
					for(int x1=0;x1<j;x1++) for(int x2=0;x2<j-x1;x2++) if(f[!now][x1][x2]>eps)
					{
						double tmp=f[!now][x1][x2]; f[!now][x1][x2]=0;
						f[now][x1+1][x2]+=tmp*p1;
						f[now][x1][x2+1]+=tmp*p2;
						f[now][x1][x2]+=tmp*p3;
					}
				}
			}
			for(int x1=0;x1<n;x1++) for(int x2=0;x2<n-x1;x2++) if(f[now][x1][x2]>eps)
			{
				double tmp=f[now][x1][x2],temp=1.0/(x2+1.0);
				for(int l=0;l<=x2;l++)
					ans[i][x1+l+1]+=inow*tmp*temp;
			}
		}
	}
	for(int i=1;i<=n;i++) 
	{
		for(int j=1;j<n;j++) printf("%.10lf ",ans[i][j]);
		printf("%.10lf\n",ans[i][n]);
	}
	return 0;
}