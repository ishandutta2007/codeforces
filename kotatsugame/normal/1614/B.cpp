#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
pair<int,int>A[2<<17];
int X[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i].first);
			A[i].second=i+1;
		}
		sort(A,A+N);
		reverse(A,A+N);
		int l=-1,r=1;
		X[0]=0;
		long long ans=0;
		for(int i=0;i<N;i++)
		{
			int id=A[i].second;
			if(-l==r)X[id]=r++;
			else X[id]=l--;
			ans+=(long long)abs(X[id])*A[i].first;
		}
		printf("%lld\n",ans*2);
		for(int i=0;i<=N;i++)printf("%d%c",X[i],i==N?10:32);
	}
}