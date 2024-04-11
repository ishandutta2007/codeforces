#include<cstdio>
#include<algorithm>
using namespace std;
int N,M,Q;
int A[1000][1000];
main()
{
	scanf("%d%d%d",&N,&M,&Q);
	long long ans=0;
	for(int i=0;i<N;i++)for(int j=0;j<M;j++)
	{
		int rest=min(N-i,M-j);
		ans+=(rest-1)*4+1;
		if(rest<N-i)ans++;
		if(rest<M-j)ans++;
	}
	for(;Q--;)
	{
		int x,y;scanf("%d%d",&x,&y);x--,y--;
		int l[2]={},r[2]={};
		while(true)
		{
			int tx=x-l[0]/2-1,ty=y-l[0]/2;
			if(l[0]%2==1)ty--;
			if(tx<0||ty<0||tx>=N||ty>=M||A[tx][ty])break;
			l[0]++;
		}
		while(true)
		{
			int tx=x-l[1]/2,ty=y-l[1]/2-1;
			if(l[1]%2==1)tx--;
			if(tx<0||ty<0||tx>=N||ty>=M||A[tx][ty])break;
			l[1]++;
		}
		while(true)
		{
			int tx=x+r[0]/2,ty=y+r[0]/2+1;
			if(r[0]%2==1)tx++;
			if(tx<0||ty<0||tx>=N||ty>=M||A[tx][ty])break;
			r[0]++;
		}
		while(true)
		{
			int tx=x+r[1]/2+1,ty=y+r[1]/2;
			if(r[1]%2==1)ty++;
			if(tx<0||ty<0||tx>=N||ty>=M||A[tx][ty])break;
			r[1]++;
		}
		if(A[x][y]==0)
		{
			ans-=(l[0]+1)*(r[0]+1)+(l[1]+1)*(r[1]+1)-1;
			A[x][y]=1;
		}
		else
		{
			ans+=(l[0]+1)*(r[0]+1)+(l[1]+1)*(r[1]+1)-1;
			A[x][y]=0;
		}
		printf("%lld\n",ans);
	}
}