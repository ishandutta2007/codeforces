#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
long long A[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		long long sum=0;
		for(int i=0;i<N;i++)
		{
			int a;scanf("%d",&a);
			A[i]=a;
			sum+=a;
		}
		long long zc=0;
		for(int i=0;i<N;i++)
		{
			A[i]=A[i]*N-sum;
			if(!A[i])zc++;
		}
		sort(A,A+N);
		long long ans=zc*(zc-1)/2;
		int r=N;
		for(int i=0;i<N;)
		{
			if(A[i]>=0)break;
			long long x=-A[i];
			long long left=0;
			while(i<N&&A[i]==-x)i++,left++;
			while(r>0&&A[r-1]>x)r--;
			long long right=0;
			while(r>0&&A[r-1]==x)r--,right++;
			ans+=left*right;
		}
		printf("%lld\n",ans);
	}
}