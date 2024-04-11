#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=200000;
const int Log=30;
const int inf=1e9;
struct sea
{
	int id,las;
}a[maxn+5];
int b[maxn+5];
struct SegmentTree
{
	int sum[maxn*Log+5],lson[maxn*Log+5],rson[maxn*Log+5],tot;
	void up(int p)
	{
		sum[p]=sum[lson[p]]+sum[rson[p]];
		return;
	}
	void cha(int &p,int L,int R,int x,int v)
	{
		if(!p) p=++tot;
		if(L==x&&R==x) {sum[p]+=v;return;}
		int mid=(L+R)/2;
		if(x<=mid) cha(lson[p],L,mid,x,v);
		if(x>mid) cha(rson[p],mid+1,R,x,v);
		up(p);
		return;
	}
	int que(int p,int L,int R,int l,int r)
	{
		if(!p) return 0;
		if(l<=L&&R<=r) return sum[p];
		int mid=(L+R)/2;
		int sum=0;
		if(l<=mid) sum+=que(lson[p],L,mid,l,r);
		if(r>mid) sum+=que(rson[p],mid+1,R,l,r);
		return sum;
	}
}T;
int n,root;
bool cmp(sea a,sea b)
{
	return a.las<b.las;
}
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		a[i].id=i;
		scanf("%lld",&a[i].las);
		b[i]=a[i].las;
	}
	sort(a+1,a+n+1,cmp);
	int now=1,ans=0;
	for(int i=1;i<=n;i++)
	{
		while(now<=a[i].las&&now<=n) T.cha(root,1,inf,b[now],1),now++;
		ans+=T.que(root,1,inf,a[i].id,inf);
		if(a[i].id<=a[i].las) ans--;
	}
	
	printf("%lld\n",ans/2);
	return 0;
}