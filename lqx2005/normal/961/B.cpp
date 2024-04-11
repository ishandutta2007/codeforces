#include<bits/stdc++.h>
using namespace std;
const int maxn=100000;
int n,k;
int a[maxn+5],t[maxn+5],sa[maxn+5],st[maxn+5];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&t[i]);
	for(int i=1;i<=n;i++) sa[i]=sa[i-1]+a[i],st[i]=st[i-1]+t[i]*a[i];
	int ans=-1;
	for(int i=k;i<=n;i++) ans=max(ans,sa[i]-sa[i-k]-(st[i]-st[i-k]));
	printf("%d\n",ans+st[n]);
	return 0;
}