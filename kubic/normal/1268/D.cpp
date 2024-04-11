//????
#include <bits/stdc++.h>
using namespace std;
#define N 2005
int n,ans,dg[N],z[N],st[N];char a[N][N];
bool chk(int u)
{
	for(int i=1;i<=n;++i) z[i]=dg[i];z[u]=0;
	for(int i=1;i<=n;++i) if(u!=i)
	{if(a[u][i]-48) ++z[i];else --z[i],++z[u];}
	sort(z+1,z+n+1);
	for(int i=1,s=0;i<n;++i)
	{s+=z[i];if(s==i*(i-1)/2) return 0;}return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",a[i]+1);
		for(int j=1;j<=n;++j) dg[i]+=a[i][j]-48;
	}for(int i=1;i<=n;++i) z[i]=dg[i];sort(z+1,z+n+1);
	for(int i=1,s=0,lst=0;i<=n;++i)
	{s+=z[i];if(s==i*(i-1)/2) st[++st[0]]=i-lst,lst=i;}
	if(st[0]==1) {puts("0 1");return 0;}
	for(int i=1;i<=n;++i) if(chk(i)) ++ans;
	if(ans) {printf("1 %d\n",ans);return 0;}
	if(st[1]>1 && st[2]>1)
	{printf("2 %d\n",st[1]*st[2]*2);return 0;}
	puts("-1");return 0;
}