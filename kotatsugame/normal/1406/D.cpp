#include<cstdio>
using namespace std;
int N;
long long A[1<<17];
long long B[1<<17];
long long sum;
void answer()
{
	long long t=sum+A[0];
	printf("%lld\n",t>=0?(t+1)/2:t/2);
}
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%lld",&A[i]);
	}
	for(int i=0;i<N-1;i++)
	{
		long long d=A[i+1]-A[i];
		if(d>0)sum+=d;
		B[i]=d;
	}
	answer();
	int Q;scanf("%d",&Q);
	for(;Q--;)
	{
		int l,r,x;scanf("%d%d%d",&l,&r,&x);
		if(l==1)A[0]+=x;
		if(l>1)
		{
			if(B[l-2]>0)sum-=B[l-2];
			B[l-2]+=x;
			if(B[l-2]>0)sum+=B[l-2];
		}
		if(r<N)
		{
			if(B[r-1]>0)sum-=B[r-1];
			B[r-1]-=x;
			if(B[r-1]>0)sum+=B[r-1];
		}
		answer();
	}
}