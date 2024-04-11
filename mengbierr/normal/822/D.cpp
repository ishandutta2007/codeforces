#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{f=(f<<1)+(f<<3)+ch-'0';
	ch=getchar();}
	return f;
}
long long mod=1000000007,ans;
long long prime[2000006],f[5000006],tot;bool check[5000006];
int main()
{
	long long t=read(),l=read(),r=read();long long s=1;
	for(int i=2;i<=r;i++)
	{
		if(!check[i])
		{
			prime[tot++]=i;
			long long x=i;
			f[i]=((x*(x-1))/2)%mod;
		}
		for(int j=0;j<tot;j++)
		{
			if(i*prime[j]>r)
			break;
			check[i*prime[j]]=1;
			f[i*prime[j]]=((f[prime[j]]*i%mod)+f[i])%mod;
			//if(i*prime[j]==15)
			//cout<<f[prime[j]]*i<<" "<<f[i]<<" "<<i<<" "<<prime[j]<<endl;
			if(i%prime[j]==0)
			break;
		}
	}
	for(int i=l;i<=r;i++)
	{
		ans+=(f[i]*s)%mod;
		//cout<<(f[i]*s)%mod<<" ";
		ans%=mod;s=(s*t)%mod;
	}
	cout<<ans;
}