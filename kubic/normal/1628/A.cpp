#include <bits/stdc++.h>
using namespace std;
#define N 200005
int T,n,m,a[N],b[N],mx[N];bool vs[N];
void slv()
{
	scanf("%d",&n);m=0;for(int i=0;i<=n+1;++i) mx[i]=0;
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]),mx[a[i]]=max(mx[a[i]],i);
	for(int i=1,lst=0,t=0;i<=n;++i)
	{
		vs[a[i]]=1;while(vs[t]) ++t;if(mx[t]>i) continue;
		b[++m]=t;t=0;for(int j=i;j>lst;--j) vs[a[j]]=0;lst=i;
	}printf("%d\n",m);
	for(int i=1;i<=m;++i) printf("%d ",b[i]);puts("");
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}