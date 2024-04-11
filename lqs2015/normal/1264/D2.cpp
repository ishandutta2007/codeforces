#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,maxn=2e6;
int jc[maxn+5],injc[maxn+5],l,n,m,p1,p2,ans;
char s[1111111];
int binpow(int a,int t)
{
	int res=1,p=a;
	for (int i=t;i;i>>=1)
	{
		if (i&1) res=1ll*res*p%mod;
		p=1ll*p*p%mod;
	}
	return res;
}
void Init()
{
	jc[0]=1;
	for (int i=1;i<=maxn;i++) jc[i]=1ll*jc[i-1]*i%mod;
	injc[maxn]=binpow(jc[maxn],mod-2);
	for (int i=maxn-1;i>=0;i--) injc[i]=1ll*injc[i+1]*(i+1)%mod;
}
int C(int n,int k)
{
	if (n<0 || k<0 || n<k) return 0;
	return (1ll*jc[n]*injc[k]%mod)*injc[n-k]%mod;
}
int func(int n,int m,int p,int x)
{
	return (1ll*x*C(n+m,m-p)+1ll*n*C(n+m-1,m-1-p))%mod;
}
int main()
{
	scanf("%s",s);
	Init();
	l=strlen(s);
	for (int i=0;i<l;i++)
	{
		if (s[i]==')') p2++;
		else if (s[i]=='?') m++;
	}
	for (int i=0;i<l-1;i++)
	{
		if (s[i]=='?') 
		{
			n++;m--;
		} 
		else if (s[i]=='(')
		{
			p1++;
		}
		else 
		{
			p2--;
		}
		ans=(ans+func(n,m,p1-p2,p1))%mod;
	}
	printf("%d\n",(ans+mod)%mod);
	return 0;
}