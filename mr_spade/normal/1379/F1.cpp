#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,inf=1e8,ninf=-1e8;
int n,m,q;
int Min[N],Max[N];
int x[N],y[N];
int ptr[N];
inline bool check(int k)
{
	int lp,rp;
	register int i;
	for(i=1;i<=2*n;i++)
		Min[i]=inf,Max[i]=ninf;
	for(i=1;i<=k;i++)
		Min[x[i]]=min(Min[x[i]],y[i]),Max[x[i]]=max(Max[x[i]],y[i]);
	ptr[0]=0;
	for(i=0;i<n;i++)
	{
		lp=max(ptr[i],m-(2*m-Max[2*i+1])/2);
		rp=min(m,(Min[2*i+2]-1)/2);
		if(lp>rp)
			return 0;
		ptr[i+1]=lp;
	}
	return 1;
}
signed main()
{
	register int i;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=q;i++)
		scanf("%d%d",&x[i],&y[i]),x[i]=2*n+1-x[i];
	int l=0,r=q,mid;
	while(l<r)
	{
		mid=(l+r+1)>>1;
		if(check(mid))
			l=mid;
		else
			r=mid-1;
	}
	for(i=1;i<=l;i++)
		puts("YES");
	for(i=l+1;i<=q;i++)
		puts("NO");
	return 0;
}