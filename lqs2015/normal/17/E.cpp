#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const long long mod=51123987;
long long n,p[4444444],mx,id,a[4444444],ans,cnt;
char str[4444444],s[4444444];
int main()
{
	scanf("%I64d%s",&n,str);
	s[0]='#';
	for (long long i=0;i<n;i++)
	{
		s[++cnt]=str[i];
		s[++cnt]='#';
	}
	s[++cnt]='\0';
	for (long long i=1;i<cnt-1;i++)
	{
		if (i<mx)
		{
			p[i]=min(mx-i,p[2*id-i]);
		}
		else p[i]=0;
		while(i-p[i]-1>=0 && i+p[i]+1<cnt && s[i+p[i]+1]==s[i-p[i]-1]) 
		{
			p[i]++;
		}
		if (i+p[i]>=mx)
		{
			mx=i+p[i];
			id=i;
		}
	}
	for (long long i=1;i<cnt-1;i++)
	{
		long long cur=i+p[i];
		a[i/2+1]++;a[(cur+1)/2+1]--;
	}
	for (long long i=1;i<=n;i++) a[i]=(a[i]+a[i-1])%mod;
	for (long long i=1;i<=n;i++) ans=(ans-(a[i]%mod)*((a[i]%mod)+1)/2)%mod;
	for (long long i=1;i<=n;i++) a[i]=(a[i]+a[i-1])%mod;
	for (long long i=1;i<=n;i++) a[i]=(a[i]+a[i-1])%mod;
	for (long long i=1;i<cnt-1;i++)
	{
		if (s[i]=='#')
		{
			long long len=p[i]/2,s=i/2;
			ans=(ans+a[s+len]-a[s])%mod;
			if (s-len-1>=0) ans=(ans-a[s-1]+a[s-len-1])%mod;
			else ans=(ans-a[s-1])%mod;
		}
		else
		{
			long long len=p[i]/2,s=i/2+1;
			ans=(ans+a[s+len]-a[s-1])%mod;
			if (s-len-2>=0) ans=(ans-a[s-1]+a[s-len-2])%mod;
			else ans=(ans-a[s-1])%mod;
		}
	}
	cout<<(ans+mod)%mod<<endl;
	return 0;
}