#include<bits/stdc++.h>
using namespace std;
#define re register
#define inf 99999999
#define cmin(a,b) ((a)<(b)?(a):(b))
int e[205][205];
int dis[205][205];
long long a[1001000];
int main()
{
	re int n;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)
	{
	    scanf("%lld",&a[i]);
	    if(a[i]==0)i--,n--;
	}
	for(re int i=0;i<=60;i++)
	{
		re int x0=0;
		for(re int j=0;j<=n;j++)if(a[j]&(1ll<<i))x0++;
		if(x0>=3){puts("3");return 0;}
	}
	for(re int i=1;i<=n;i++)
		for(re int j=1;j<=n;j++)
			if(i==j)e[i][j]=dis[i][j]=0;
			else if((a[i]&a[j])!=0)e[i][j]=dis[i][j]=1;
			else e[i][j]=dis[i][j]=inf;
		re int ans=inf;
		for(re int k=1; k<=n; ++k)
		{
			for(re int i=1; i<k; ++i)
				for(re int j=i+1; j<k; ++j)
					ans=cmin(ans,dis[i][j]+e[i][k]+e[k][j]);
			for(re int i=1; i<=n; ++i)
				for(re int j=1; j<=n; ++j)
					dis[i][j]=cmin(dis[i][j],dis[i][k]+dis[k][j]);
		}
		if(ans==inf) puts("-1");
		else cout<<ans<<endl;
}