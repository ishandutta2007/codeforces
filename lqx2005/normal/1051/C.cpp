#include <bits/stdc++.h>
using namespace std;
const int maxn=100;
int n;
int a[maxn+5],f[maxn+5],s[maxn+5];
char g[maxn+5];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&s[i]);
		a[s[i]]++;
	}
	int cnta=0,cntb=0;
	for(int i=1;i<=maxn;i++)
	{
		if(a[i]==2||a[i]==0) continue;
		if(a[i]==1) cnta++;
		if(a[i]>=3) cntb++;
	}
	if(cnta%2==1&&cntb==0)
	{
		printf("NO\n");
		return 0;
	}
	cntb=cnta%2;
	for(int i=1;i<=maxn;i++)
	{
		if(a[i]==2||a[i]==0) f[i]=a[i]/2;
		else if(a[i]==1)
		{
			if(cnta&1) f[i]=1,cnta--;
			else f[i]=0,cnta--;
		}
		else 
		{
			if(cntb==0) continue;
			if(cntb&1) f[i]=a[i]-1,cntb--;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(f[s[i]]>0) g[i]='A',f[s[i]]--;
		else g[i]='B';
	}
	printf("YES\n");
	printf("%s\n",g+1);
	return 0;
}