#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const int mod1=1e9+7,p=17;
int has11[222222],has12[222222];
int has21[222222],has22[222222],x,y,z,n,q,pw1[222222],pw2[222222],num[222222];
int h1,h2,h3,h4;
char s[222222];
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	pw1[0]=pw2[0]=1;
	for (int i=1;i<=n;i++) 
	{
		pw1[i]=1ll*pw1[i-1]*p%mod1;
	}
	for (int i=1;i<=n;i++)
	{
		if (s[i-1]=='1')
		{
			has11[i]=has11[i-1];has12[i]=has12[i-1];
		}
		else
		{
			if (i&1)
			{
				has11[i]=(1ll*has11[i-1]*p+1)%mod1;
			}
			else
			{
				has11[i]=(1ll*has11[i-1]*p+2)%mod1;
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (s[i-1]=='1')
		{
			has21[i]=has21[i-1];has22[i]=has22[i-1];
		}
		else
		{
			if (i%2==0)
			{
				has21[i]=(1ll*has21[i-1]*p+1)%mod1;
			}
			else
			{
				has21[i]=(1ll*has21[i-1]*p+2)%mod1;
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (s[i-1]=='0') num[i]=num[i-1]+1;
		else num[i]=num[i-1];
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d",&x,&y,&z);
		int nx=num[x+z-1]-num[x-1],ny=num[y+z-1]-num[y-1];
		if (nx!=ny) 
		{
			printf("No\n");
			continue;
		}
		if (x&1)
		{
			h1=(1ll*has11[x+z-1]-1ll*pw1[nx]*has11[x-1])%mod1;
			h1=(h1+mod1)%mod1;
		}
		else
		{
			h1=(1ll*has21[x+z-1]-1ll*pw1[nx]*has21[x-1])%mod1;
			h1=(h1+mod1)%mod1;
		}
		if (y&1)
		{
			h3=(1ll*has11[y+z-1]-1ll*pw1[ny]*has11[y-1])%mod1;
			h3=(h3+mod1)%mod1;
		}
		else
		{
			h3=(1ll*has21[y+z-1]-1ll*has21[y-1]*pw1[ny])%mod1;
			h3=(h3+mod1)%mod1;
		}
		if (h1==h3) printf("Yes\n");
		else printf("No\n");
	}
	return Accepted;
}