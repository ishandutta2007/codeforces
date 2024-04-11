#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long
int T,n,a[N];ll s;bool fl;
void slv()
{
	scanf("%d",&n);s=fl=0;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	if(n==3)
	{
		if(a[2]&1) puts("-1");
		else printf("%d\n",a[2]/2);return;
	}for(int i=2;i<n;++i) if(a[i]>1) fl=1;
	for(int i=2;i<n;++i) s+=a[i]+(a[i]&1);
	if(!fl) puts("-1");else printf("%lld\n",s/2);
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}