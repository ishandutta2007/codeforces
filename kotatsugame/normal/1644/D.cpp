#include<iostream>
using namespace std;
const int mod=998244353;
int T,N,M,K,Q;
int X[2<<17],Y[2<<17];
bool uX[2<<17],uY[2<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M>>K>>Q;
		for(int i=0;i<Q;i++)cin>>X[i]>>Y[i];
		long long ans=1;
		for(int i=Q;i--;)
		{
			bool fn=(uX[X[i]]||M==0)&&(uY[Y[i]]||N==0);
			if(!uX[X[i]])N--;
			if(!uY[Y[i]])M--;
			uX[X[i]]=uY[Y[i]]=true;
			if(!fn)ans=ans*K%mod;
		}
		for(int i=0;i<Q;i++)uX[X[i]]=uY[Y[i]]=false;
		cout<<ans<<"\n";
	}
}