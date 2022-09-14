#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
long long mod=1e9+7,dp[2][30000],*p,*q,n;
int k;
long long make[11111][100];
vector<long long>d;
map<long long,int>M;
long long inv[100];
void func(long long s,int cnt,long long*p,long long*q)
{
	for(int i=0;i<=k;i++)for(int j=0;j<=cnt;j++)make[i][j]=0;
	make[0][cnt]=1;
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<=cnt;j++)
		{
			long long div=inv[j+1];
			for(int l=0;l<=j;l++)make[i+1][l]=(make[i+1][l]+make[i][j]%mod*div%mod)%mod;
		}
	}
	for(int i=0;i<d.size();i++)q[i]=0;
	long long take=1;
	for(int i=0;i<=cnt;i++)
	{
		long long mul=make[k][i];
		for(int j=0;j<d.size();j++)
		{
			if(p[j]==0)continue;
			q[M[d[j]*take]]=(q[M[d[j]*take]]+p[j]%mod*mul%mod)%mod;
		}
		take*=s;
	}
}
main()
{
	inv[0]=inv[1]=1;
	for(long long i=2;i<100;i++)inv[i]=(mod-mod/i*inv[mod%i]%mod)%mod;
	cin>>n>>k;
	p=dp[0];
	q=dp[1];
	for(long long i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			d.push_back(i);
			if(n/i!=i)d.push_back(n/i);
		}
	}
	sort(d.begin(),d.end());
	for(int i=0;i<d.size();i++)M[d[i]]=i;
	p[M[1]]=1;
	for(long long i=2;i*i<=n;i++)
	{
		if(n%i!=0)continue;
		long long cnt=0;
		while(n%i==0)
		{
			n/=i;
			cnt++;
		}
		func(i,cnt,p,q);
		swap(p,q);
	}
	if(n>1)
	{
		func(n,1,p,q);
		swap(p,q);
	}
	long long ans=0;
	for(int i=0;i<d.size();i++)ans=(ans+d[i]%mod*p[i]%mod)%mod;
	cout<<ans<<endl;
}