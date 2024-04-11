#include<bits/stdc++.h>
using namespace std;
const int N=100000;
const int INF=1e9;
struct node
{
	int a,r,sz,id;
}a[N+5],cpy[N+5];
struct question
{
	int x,y,id;
}q[N+5];
int t,n,k,s,x,y;
int p[N+5],sz[N+5],ans[N+5],b[N+5];
vector<int> g[N+5];
struct BIT
{
	int t[N+5];
	void clear()
	{
		for(int i=0;i<=n;i++) t[i]=0;
		return;
	}
	int lowbit(int x)
	{
		return x&(-x);
	}
	void Add(int x,int v)
	{
		for(int i=x;i<=n;i+=lowbit(i)) t[i]+=v;
		return;
	}
	int Sum(int x)
	{
		int sum=0;
		for(int i=x;i>0;i-=lowbit(i)) sum+=t[i];
		return sum;
	}
}T;

struct SegmentTree
{
	struct tree
	{
		int l,r,mx;
	};
	tree t[N*4+5];
	void build(int x,int l,int r)
	{
		t[x].l=l;
		t[x].r=r;
		if(l==r) 
		{
			t[x].mx=-INF;
			return;
		}
		int mid=(l+r)/2;
		build(x*2,l,mid);
		build(x*2+1,mid+1,r);
		t[x].mx=max(t[x*2].mx,t[x*2+1].mx);
		return;
	}
	void change(int x,int s,int v)
	{
		if(t[x].l==s&&t[x].r==s) 
		{
			t[x].mx=v;
			return;
		}
		int mid=(t[x].l+t[x].r)/2;
		if(s<=mid) change(x*2,s,v);
		if(s>mid) change(x*2+1,s,v);
		t[x].mx=max(t[x*2].mx,t[x*2+1].mx);
		return;
	}
	int query(int x,int l,int r)
	{
		if(l<=t[x].l&&t[x].r<=r) return t[x].mx;
		int mid=(t[x].l+t[x].r)/2;
		int ret=-INF;
		if(l<=mid) ret=max(ret,query(x*2,l,r));
		if(r>mid) ret=max(ret,query(x*2+1,l,r));
		return ret;
	}
}S;
bool cmpcmpcmp(question c,question d)
{
	return max(cpy[c.x].a,cpy[c.y].a)>max(cpy[d.x].a,cpy[d.y].a);
}
bool cmp(node a,node b)
{
	return a.r<b.r;
}
bool cmpcmp(node a,node b)
{
	return a.a<b.a;
}
int left(int x)
{
	int pos=lower_bound(p+1,p+n+1,x)-p;
	if(pos==n+1) return n+1;
	return pos;
}
int right(int x)
{
	int pos=upper_bound(p+1,p+n+1,x)-p;
	pos--;
	if(pos<=0) return 0;
	return pos;
}
void solve()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) g[i].clear();
	T.clear();
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i].a);
		b[i]=a[i].a;
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++) a[i].a=lower_bound(b+1,b+n+1,a[i].a)-b;
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i].r);
		p[i]=a[i].r;
	}
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++) cpy[i]=a[i];
	sort(a+1,a+n+1,cmp);
	
	for(int i=1;i<=n;i++) a[i].id=i;
	for(int i=1;i<=n;i++) g[a[i].a].push_back(i);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<g[i].size();j++) T.Add(a[g[i][j]].id,1);
		for(int j=0;j<g[i].size();j++) a[g[i][j]].sz=T.Sum(right(a[g[i][j]].r+k))-T.Sum(left(a[g[i][j]].r-k)-1);

	}
	S.build(1,0,n+1);
	scanf("%d",&s);
	for(int i=1;i<=s;i++) scanf("%d%d",&q[i].x,&q[i].y),q[i].id=i;
	int now=n;
	sort(q+1,q+s+1,cmpcmpcmp);
	sort(a+1,a+n+1,cmpcmp);
	for(int i=1;i<=s;i++)
	{
		int info=max(cpy[q[i].x].a,cpy[q[i].y].a);
		while(a[now].a>=info&&now>0) S.change(1,a[now].id,a[now].sz),now--;
		int l=max(cpy[q[i].x].r,cpy[q[i].y].r);
		int r=min(cpy[q[i].x].r,cpy[q[i].y].r);
		l=left(l-k);
		r=right(r+k);
		ans[q[i].id]=S.query(1,l,r);
		if(ans[q[i].id]==-INF) ans[q[i].id]=-1;
	}
	for(int i=1;i<=s;i++) printf("%d\n",ans[i]);
	return;
}
int main()
{
	solve();
	return 0;
	
}