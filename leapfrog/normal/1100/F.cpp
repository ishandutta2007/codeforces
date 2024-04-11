#include<bits/stdc++.h>
using namespace std;
const int N=500005,M=25;
struct que{int id,le,ri;bool operator<(que b) const {return ri<b.ri;}}q[N];
int n,m,r[N],a[M],p[M],ans[N];
inline void add(int x,int id)
{
	for(int i=20;i>=0;i--)
		if((x>>i)&1)
		{
			if(!a[i]) return (void)(a[i]=x,p[i]=id);
			if(p[i]<id) swap(p[i],id),swap(a[i],x);
			x^=a[i];
		}
}
inline int query(int id)
{
	int ans=0;
	for(int i=20;i>=0;i--) if(p[i]>=id&&ans<(ans^a[i])) ans^=a[i];
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",r+i);
	scanf("%d",&m);
	for(int i=1;i<=m;i++) scanf("%d%d",&q[i].le,&q[i].ri),q[i].id=i;
	sort(q+1,q+m+1);
	for(int i=1,x=0;i<=m;i++)
	{
		while(x<q[i].ri) x++,add(r[x],x);
		ans[q[i].id]=query(q[i].le);
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}