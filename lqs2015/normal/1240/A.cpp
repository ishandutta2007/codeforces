#include<bits/stdc++.h>
#define Accepted 0 
using namespace std;
int n,p[222222],x,a,y,b,q,l,r,mid,cnt[222222],g[222222];
long long k;
bool check()
{
	for (int i=1;i<=mid;i++) g[i]=cnt[i];
	sort(g+1,g+mid+1);
	reverse(g+1,g+mid+1);
	long long ans=0;
	for (int i=1;i<=mid;i++) ans+=(1ll*g[i]*p[i]);
	ans/=100;
	if (ans>=k) return 1;
	return 0;
}
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&p[i]);
		scanf("%d%d%d%d",&x,&a,&y,&b);
		scanf("%lld",&k);
		sort(p+1,p+n+1);
		reverse(p+1,p+n+1);
		for (int i=1;i<=n;i++) cnt[i]=0;
		for (int i=a;i<=n;i+=a) cnt[i]+=x;
		for (int i=b;i<=n;i+=b) cnt[i]+=y;
		l=0;r=n;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if (check()) r=mid-1;
			else l=mid+1;
		}
		if (l>n) printf("-1\n");
		else printf("%d\n",l);
  	}
	return Accepted;
}