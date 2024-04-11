#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
int n,mx,a[N],b[N],ps[N],ordA[N],ordB[N];ll ans;bool vs[N];
int cntZ;struct Node {int l,r;}z[N];
bool cmpA(int x,int y) {return a[x]<a[y];}
bool cmpB(int x,int y) {return b[x]<b[y];}
bool cmp(Node x,Node y) {return x.l==y.l?x.r<y.r:x.l<y.l;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d %d",&a[i],&b[i]);ans+=b[i];
		b[i]+=a[i];ordA[i]=ordB[i]=i; 
	}sort(ordA+1,ordA+n+1,cmpA);
	sort(ordB+1,ordB+n+1,cmpB);
	for(int i=1;i<=n;++i) ps[ordB[i]]=ordA[i];
	for(int i=1;i<=n;++i) if(!vs[i])
	{
		Node t;t=(Node) {a[i],b[i]};vs[i]=1;
		for(int j=ps[i];j!=i;j=ps[j])	
			t.l=min(t.l,a[j]),t.r=max(t.r,b[j]),vs[j]=1;z[++cntZ]=t;
	}sort(z+1,z+cntZ+1,cmp);mx=z[1].l;
	for(int i=1;i<=n;++i)
		ans+=max(z[i].l-mx,0),mx=max(mx,z[i].r);
	printf("%lld\n",ans);return 0;
}