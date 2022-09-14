#include<cstdio>
#include<algorithm>
using namespace std;
int N;
int P[1<<17];
int L[1<<17],R[1<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&P[i]);
	L[0]=R[N-1]=0;
	int mx=0;
	for(int i=1;i<N;i++)
	{
		if(P[i-1]<P[i])L[i]=L[i-1]+1;
		else L[i]=0;
		mx=max(mx,L[i]);
	}
	for(int i=N-1;i--;)
	{
		if(P[i]>P[i+1])R[i]=R[i+1]+1;
		else R[i]=0;
		mx=max(mx,R[i]);
	}
	int mxc=0;
	for(int i=0;i<N;i++)
	{
		if(L[i]==mx)mxc++;
		if(R[i]==mx)mxc++;
	}
	int ans=0;
	for(int i=0;i<N;i++)
	{
		if(L[i]>=2&&L[i]==R[i]&&L[i]%2==0)
		{
			if(mx==L[i]&&mxc==2)
			{
				ans++;
			}
		}
	}
	printf("%d\n",ans);
}