#include<bits/stdc++.h>
using namespace std;
int n,c,a[555555],pre[555555],suf[555555],f[555555],g[555555],lst[555555],ans;
int pos[555555];
int main()
{
	scanf("%d%d",&n,&c);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) pre[i]=pre[i-1]+(a[i]==c);
	for (int i=n;i>=1;i--) suf[i]=suf[i+1]+(a[i]==c);
	for (int i=1;i<=n;i++)
	{
		lst[i]=pos[a[i]];
		pos[a[i]]=i;
	}
	for (int i=1;i<=n;i++)
	{
		g[i]=max(g[lst[i]]+1,pre[i-1]+1);
		f[i]=max(f[i-1],g[i]);
	}
	for (int i=1;i<=n;i++)
	{
		ans=max(ans,f[i]+suf[i+1]);
	}
	printf("%d\n",ans);
	return 0;
}