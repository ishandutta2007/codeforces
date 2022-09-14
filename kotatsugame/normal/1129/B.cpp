#include<cstdio>
#include<algorithm>
using namespace std;
int N;
int A[2020];
long long f()
{
	long long res=0;
	long long cur=0;
	int k=-1;
	for(int i=0;i<N;i++)
	{
		cur+=A[i];
		if(cur<0)cur=0,k=i;
		res=max(res,(i-k)*cur);
	}
	return res;
}
long long g()
{
	long long res=0,cur=0;
	for(int i=N;i--;)
	{
		cur+=A[i];
		res=max(res,(N-i)*cur);
	}
	return res;
}
int K;
main()
{
	scanf("%d",&K);
	for(int n=2;n<=2000;n++)
	{
		int a=(n-1-K%(n-1))%(n-1);
		int x=(K+a)/(n-1)+n+a;
		if(x>1000000)continue;
		for(int i=0;i<n-2;i++)A[i]=-1;
		A[n-2]=-1-a;
		A[n-1]=x;
		N=n;
		if(f()+K!=g())
		{
			N=0;
			continue;
		}
		break;
	}
	if(N==0)
	{
		puts("-1");
		return 0;
	}
	printf("%d\n",N);
	for(int i=0;i<N;i++)printf("%d%c",A[i],i+1==N?10:32);
}