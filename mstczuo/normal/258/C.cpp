# include <iostream>
# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;
const int maxn=100010;
const int Mod=1000000007;
#define For(i,a,b) for(int i=a;i<=b;i++)
int a[maxn],c[maxn],s[maxn],M;

long long power(long long a,int b)
{
	long long t=1;
	for( ;b;a=a*a%Mod,b>>=1)if(b&1)t=t*a%Mod;
	return t;
}

long long res1,res2;
long long func(int K)
{
	int i,m=0;
	for(i=1;i*i<K;i++)
		if(K%i==0)
			c[m++]=i,c[m++]=K/i;
	if(i*i==K)c[m++]=i;
	sort(c,c+m);
	
	c[m]=M+1;res1=res2=1;
	For(i,0,m-1)res1*=power(i+1,s[c[i+1]]-s[c[i]]),res1%=Mod;
	c[--m]=M+1;
	For(i,0,m-1)res2*=power(i+1,s[c[i+1]]-s[c[i]]),res2%=Mod;
	res1-=res2; return res1<0?res1+Mod:res1;
}

int main()
{
	int n,x; scanf("%d",&n);
	For(i,1,n){scanf("%d",&x);a[x]++;if(x>M)M=x;}
	For(i,1,M)s[i+1]=s[i]+a[i];
	
	long long ans=1;
	For(i,2,M)ans+=func(i),ans-=ans>Mod?Mod:0;
	cout<<ans<<endl;
}