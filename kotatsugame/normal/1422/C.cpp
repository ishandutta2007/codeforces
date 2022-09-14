#include<iostream>
using namespace std;
const long long mod=1e9+7;
string N;
long long p10[1<<17];
main()
{
	p10[0]=1;
	for(int i=1;i<1<<17;i++)p10[i]=p10[i-1]*10%mod;
	cin>>N;
	long long ans=0,L=0,cum=0,R=0;
	for(int i=0;i<N.size();i++)R=(R+p10[N.size()-i-1]*(N[i]-'0'))%mod;
	for(int i=0;i<N.size();i++)
	{
		R=(R+mod-p10[N.size()-i-1]*(N[i]-'0')%mod)%mod;
		(ans+=L*p10[N.size()-i-1]%mod+R*(i+1)%mod)%=mod;
		cum=(cum*10+N[i]-'0')%mod;
		L=(L+cum)%mod;
	}
	cout<<ans<<endl;
}