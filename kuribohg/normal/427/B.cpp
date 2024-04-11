#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=200010;
int n,t,c,ans,a[MAXN],f[MAXN],r[MAXN],inq,tot;
int main()
{
	scanf("%d%d%d",&n,&t,&c);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=t)
		{
			if(!inq) inq=true,f[++tot]=i;
			else continue;
		}
		else
		{
			if(inq) r[tot]=i-1,inq=false;
			else continue;
		}
	}
	if(inq) r[tot]=n;
	for(int i=1;i<=tot;i++)
		ans+=max(0,r[i]-f[i]-c+2);
	printf("%d\n",ans);
	return 0;
}