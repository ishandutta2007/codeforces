#include<iostream>
using namespace std;
int N,K;
int A[1<<17],c[1<<17];
int R[1<<17];
void calc(int p,int t)
{
	for(int i=0;i<N;i++)
	{
		c[i]=0;
		while(A[i]%p==0)
		{
			A[i]/=p;
			c[i]++;
		}
	}
	int r=0;
	for(int i=0;i<N;i++)
	{
		while(r<N&&t>0)t-=c[r++];
		if(t>0)R[i]=N+1;
		if(R[i]<r)R[i]=r;
		t+=c[i];
	}
}
main()
{
	cin>>N>>K;
	for(int i=0;i<N;i++)cin>>A[i];
	for(int i=0;i<N;i++)R[i]=i+1;
	for(int i=2;i*i<=K;i++)if(K%i==0)
	{
		int nc=0;
		while(K%i==0)K/=i,nc++;
		calc(i,nc);
	}
	if(K>1)calc(K,1);
	long long ans=0;
	for(int i=0;i<N;i++)ans+=N+1-R[i];
	cout<<ans<<endl;
}