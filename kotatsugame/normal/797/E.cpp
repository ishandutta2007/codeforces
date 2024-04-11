#include<iostream>
using namespace std;
int N,A[1<<17];
int ans[400][1<<17];
main()
{
	cin>>N;
	for(int i=1;i<=N;i++)cin>>A[i];
	for(int k=1;k*k<=N;k++)
	{
		for(int i=N;i>=1;i--)
		{
			int np=i+A[i]+k;
			if(np>N)ans[k][i]=1;
			else ans[k][i]=ans[k][np]+1;
		}
	}
	int Q;cin>>Q;
	for(;Q--;)
	{
		int p,k;cin>>p>>k;
		if(k<=N/k)cout<<ans[k][p]<<"\n";
		else
		{
			int ret=0;
			while(p<=N)p+=A[p]+k,ret++;
			cout<<ret<<"\n";
		}
	}
}