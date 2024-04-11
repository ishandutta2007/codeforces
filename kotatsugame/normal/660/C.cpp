#include<cstdio>
using namespace std;
int N,K;
int A[3<<17];
main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	int ans=-1,al,ar;
	int l=0,now=0;
	for(int r=0;r<N;r++)
	{
		if(!A[r])now++;
		while(now>K)now-=!A[l++];
		if(r-l+1>ans)
		{
			ans=r-l+1;
			al=l,ar=r;
		}
	}
	for(int i=al;i<=ar;i++)A[i]=1;
	printf("%d\n",ans);
	for(int i=0;i<N;i++)printf("%d%c",A[i],i+1==N?10:32);
}