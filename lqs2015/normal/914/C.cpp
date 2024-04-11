#include<iostream>
#include<string>
using namespace std;
const long long mod=1e9+7;
long long a[1111],k,as[1111],t,sum,ans,c[1111][1111],cur,sz;
string s;
int main()
{
	for (long long i=0;i<=1000;i++) c[i][0]=1;
	for (long long i=1;i<=1000;i++)
	{
		for (long long j=1;j<=i;j++)
		{
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		}
	}
	cin>>s>>k;
	sz=s.size();
	if (k==0) 
	{
		cout<<1<<endl;
		return 0;
	}
	if (k==1)
	{
		cout<<sz-1<<endl;
		return 0;
	}
	k--;
	a[1]=0;
	for (long long i=2;i<=sz;i++)
	{
		t=i;sum=0;
		while(t)
		{
			if (t&1) sum++;
			t>>=1;
		}
		a[i]=a[sum]+1;
	}
	for (int i=0;i<sz;i++)
	{
		if (s[i]=='1')
		{
			for (int j=1;j<=sz;j++)
			if (j>=cur) as[j]=(as[j]+c[sz-i-1][j-cur])%mod;
			cur++;
		}
	}
	as[cur]=(as[cur]+1)%mod;
	for (long long i=1;i<=sz;i++)
	{
		if (a[i]==k) ans=(ans+as[i])%mod;
	}
	cout<<ans<<endl;
	return 0;
}