#include<cstdio>
#include<algorithm>
using namespace std;
int R,N;
int T[1<<17],X[1<<17],Y[1<<17];
int after[1<<17],fix[1<<17];
main()
{
	scanf("%d%d",&R,&N);
	T[0]=0;X[0]=Y[0]=1;
	for(int i=1;i<=N;i++)scanf("%d%d%d",&T[i],&X[i],&Y[i]);
	fix[0]=1;
	int ans=0;
	for(int i=0;i<=N;i++)
	{
		after[i+1]=max(after[i+1],after[i]);
		int now=max(fix[i],after[i]);
		ans=max(ans,now);
		if(now==0)continue;
		now++;
		for(int j=i+1;j<=N;j++)
		{
			if(T[j]>=T[i]+2*R)
			{
				after[j]=max(after[j],now);
				break;
			}
			if(T[i]+abs(X[i]-X[j])+abs(Y[i]-Y[j])<=T[j])
			{
				fix[j]=max(fix[j],now);
			}
		}
	}
	printf("%d\n",ans-1);
}