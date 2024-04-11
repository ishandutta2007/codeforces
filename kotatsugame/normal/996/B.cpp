#include<cstdio>
using namespace std;
int N;
main()
{
	scanf("%d",&N);
	int tm=2e9,ans;
	for(int i=0;i<N;i++)
	{
		int A;scanf("%d",&A);
		int t=A/N;
		if(t>0)t--;
		while(t*N+i<A)t++;
		if(tm>t*N+i)tm=t*N+i,ans=i+1;
	}
	printf("%d\n",ans);
}