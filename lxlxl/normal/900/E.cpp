#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 210000;

int n,m;
char str[maxn];
int s[maxn],pre[maxn];

int v1[maxn],v2[maxn];
int c[maxn],f[maxn],g[maxn];

int main()
{
	scanf("%d",&n); scanf("%s",str+1);
	scanf("%d",&m);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+(str[i]=='?'?1:0);
		if(str[i-1]!='?') pre[i]=i-1;
		else pre[i]=pre[i-1];
	}
	v1[0]=v2[0]=1;
	for(int i=1;i<=n;i++)
	{
		v1[i]=v1[i-1],v2[i]=v2[i-1];
		c[i]=-1;
		char cc=str[i];
		if(i&1)
		{
			if(cc=='a') v2[i]=i+1;
			if(cc=='b') v1[i]=i+1;
			if(m&1)
			{
				if(i-v1[i]+1>=m) c[i]=s[i]-s[i-m];
			}
			else
			{
				if(i-v2[i]+1>=m) c[i]=s[i]-s[i-m];
			}
		}
		else
		{
			if(cc=='a') v1[i]=i+1;
			if(cc=='b') v2[i]=i+1;
			if(m&1)
			{
				if(i-v2[i]+1>=m) c[i]=s[i]-s[i-m];
			}
			else
			{
				if(i-v1[i]+1>=m) c[i]=s[i]-s[i-m];
			}
		}
	}
	int now=0,nows=0;
	for(int i=1;i<=n;i++)
	{
		if(i-m>0)
		{
			if(now<f[i-m]) now=f[i-m],nows=g[i-m];
			else if(now==f[i-m]) nows=min(nows,g[i-m]);
		}
		if(c[i]!=-1) f[i]=now+1,g[i]=nows+c[i];
	}
	int re=0,res=0;
	for(int i=1;i<=n;i++)
	{
		if(re<f[i]) re=f[i],res=g[i];
		else if(re==f[i]) res=min(res,g[i]);
	}
	printf("%d\n",res);
	
	return 0;
}