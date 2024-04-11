#include<iostream>
using namespace std;
int T,N,E,A[2<<17];
bool isp[1<<20];
int prv[2][2<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int i=2;i<1<<20;i++)isp[i]=true;
	for(int i=2;i<1<<20;i++)if(isp[i])
	{
		for(int j=i+i;j<1<<20;j+=i)isp[j]=false;
	}
	cin>>T;
	for(;T--;)
	{
		cin>>N>>E;
		for(int i=0;i<N;i++)cin>>A[i];
		for(int i=0;i<E;i++)
		{
			prv[0][i]=-1;
			prv[1][i]=-1;
		}
		long long ans=0;
		for(int i=N;i--;)
		{
			int j=i%E;
			if(A[i]!=1)
			{
				prv[1][j]=prv[0][j];
				prv[0][j]=i;
			}
			if(prv[0][j]==-1)continue;
			if(!isp[A[prv[0][j]]])continue;
			int L=max(i+E,prv[0][j]);
			int R;
			if(prv[1][j]!=-1)R=prv[1][j];
			else R=i+(N-i+E-1)/E*E;
			ans+=R-L;
		}
		cout<<ans/E<<"\n";
	}
}