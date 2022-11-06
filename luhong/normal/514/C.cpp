#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#define mod 100000000014647
using namespace std;
map<long long,bool> used;
char c[601000];int len;
long long w[601000];
long long hash()
{
	long long sum=0;
	for(int i=0;i<len;i++)sum=(sum+(c[i]-'a'+1)*w[i])%mod;
	return sum;
}
int main()
{
	int n,m;scanf("%d%d",&n,&m);
	w[0]=1;for(int i=1;i<=600000;i++)w[i]=w[i-1]*73%mod; 
	for(int i=1;i<=n;i++)
	{
		scanf("%s",c);
		len=strlen(c);used[hash()]=1;
		for(int j=0;j<len;j++)c[j]='\0';
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%s",c);
		len=strlen(c);
		bool ok=0;
		long long ha=hash();
		for(int j=0;j<len;j++)
		{
			for(int k=0;k<3;k++)
			{
				if(c[j]==k+'a')continue;
				long long now=(ha-(c[j]-'a'+1)*w[j]%mod+(k+1)*w[j]%mod+mod)%mod;
				if(used[now]){ok=1;break;}
			}
			if(ok)break;
		}
		if(ok)puts("YES");
		else puts("NO");
		for(int j=0;j<len;j++)c[j]='\0';
	}
	return 0;
}