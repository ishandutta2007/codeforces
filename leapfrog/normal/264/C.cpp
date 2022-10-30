#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[100005],c[100005],f[100005],lst,ans,ret;
signed main()
{
	scanf("%lld%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	for(int i=1;i<=n;i++) scanf("%lld",c+i);
	for(int l=0,l2=0,aa,bb;m--;l=0,l2=0)
	{
		scanf("%lld%lld",&aa,&bb),memset(f,~0x3f,sizeof(f)),ans=0,ret=0;
		for(int i=1;i<=n;i++)
		{
			ans=max(bb*a[i],f[c[i]]+aa*a[i]);
			if(c[i]!=l) ans=max(ans,f[l]+bb*a[i]);else ans=max(ans,f[l2]+bb*a[i]);
			if(ans>f[l]) {if(c[i]!=l) l2=l,l=c[i];else l=c[i];}else if(ans>f[l2]&&c[i]!=l) l2=c[i];
			f[c[i]]=max(f[c[i]],ans),ret=max(ret,ans);
		}
		printf("%lld\n",ret);
	}
	return 0;
}