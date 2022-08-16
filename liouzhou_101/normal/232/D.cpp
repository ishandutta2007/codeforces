#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

const int MaxN=400010;
const int INF=1000000010;

int n0;
int h[MaxN];

int n;
int s[MaxN],p[MaxN];

int sum[MaxN],wv[MaxN],sa[MaxN],x[MaxN],y[MaxN];
void build_sa()
{
	int m=n;
	for (int i=1;i<=m;++i) sum[i]=0;
	for (int i=1;i<=n;++i) sum[x[i]=s[i]]++;
	for (int i=1;i<=m;++i) sum[i]+=sum[i-1];
	for (int i=n;i>=1;--i) sa[sum[x[i]]--]=i;
	for (int j=1,p=1;p<n;j*=2,m=p)
	{
		p=0;
		for (int i=n-j+1;i<=n;++i) y[++p]=i;
		for (int i=1;i<=n;++i) if (sa[i]>j) y[++p]=sa[i]-j;
		for (int i=1;i<=n;++i) wv[i]=x[y[i]];
		for (int i=1;i<=m;++i) sum[i]=0;
		for (int i=1;i<=n;++i) sum[wv[i]]++;
		for (int i=1;i<=m;++i) sum[i]+=sum[i-1];
		for (int i=n;i>=1;--i) sa[sum[wv[i]]--]=y[i];
		for (int i=1;i<=n;++i) y[i]=x[i];
		x[sa[1]]=p=1;
		for (int i=2;i<=n;++i)
		{
			++p;
			if (y[sa[i]]==y[sa[i-1]]&&y[sa[i]+j]==y[sa[i-1]+j]) --p;
			x[sa[i]]=p;
		}
	}
}

int rank[MaxN],height[MaxN],RMQ[MaxN][20];
void build_height()
{
	for (int i=1;i<=n;++i) rank[sa[i]]=i;
	int k=0;
	for (int i=1;i<=n;++i)
	{
		if (k) --k;
		while (s[i+k]==s[sa[rank[i]-1]+k]) ++k;
		height[rank[i]]=k;
	}
	for (int i=1;i<=n;++i)
		RMQ[i][0]=height[i];
	for (int k=1;k<20;++k)
		for (int i=1;i<=n;++i)
			RMQ[i][k]=min(RMQ[i][k-1],RMQ[i+(1<<(k-1))][k-1]);
}

int tot;
struct node
{
	node *Lc,*Rc;
	int L,R,mid;
	int sum;
}tree[MaxN*20],*root[MaxN];

node *build(int L,int R)
{
	node *it=&tree[++tot];
	it->L=L;
	it->R=R;
	if (L<R)
	{
		it->mid=(L+R)>>1;
		it->Lc=build(L,it->mid);
		it->Rc=build(it->mid+1,R);
	}
	return it;
}

inline node *rebuild(node *p,int x)
{
	node *it=&tree[++tot];
	*it=*p;
	it->sum++;
	if (p->L==p->R) return it;
	if (x<=p->mid)
		it->Lc=rebuild(p->Lc,x);
	else
		it->Rc=rebuild(p->Rc,x);
	return it;
}

inline int calc(node *p,node *q,int x,int y)
{
	if (p->L==x&&p->R==y)
		return p->sum-q->sum;
	if (y<=p->mid)
		return calc(p->Lc,q->Lc,x,y);
	if (x>p->mid)
		return calc(p->Rc,q->Rc,x,y);
	return calc(p->Lc,q->Lc,x,p->mid)+calc(p->Rc,q->Rc,p->mid+1,y);
}

int LOG[MaxN];

void init()
{
	cin>>n0;
	for (int i=1;i<=n0;++i)
		scanf("%d",&h[i]);
	for (int i=1;i<n0;++i)
		s[++n]=h[i+1]-h[i];
	s[++n]=INF;
	for (int i=1;i<n0;++i)
		s[++n]=h[i]-h[i+1];
	for (int i=1;i<=n;++i)
		p[i]=s[i];
	sort(p+1,p+n+1);
	for (int i=1;i<=n;++i)
		s[i]=lower_bound(p+1,p+n+1,s[i])-p;
	build_sa();
	build_height();
	root[0]=build(1,n);
	for (int i=1;i<=n;++i)
		root[i]=rebuild(root[i-1],sa[i]);
	for (int i=2;i<=n;++i)
		LOG[i]=LOG[i>>1]+1;
}

inline int getRMQ(int x,int y)
{
	int k=LOG[y-x+1];
	return min(RMQ[x][k],RMQ[y-(1<<k)+1][k]);
}

inline int getL(int x,int k)
{
	int L=1,R=x-1,get=x;
	while (L<=R)
	{
		int mid=(L+R)>>1;
		if (getRMQ(mid+1,x)>=k)
		{
			get=mid;
			R=mid-1;
		}
		else
			L=mid+1;
	}
	return get;
}

inline int getR(int x,int k)
{
	int L=x+1,R=n,get=x;
	while (L<=R)
	{
		int mid=(L+R)>>1;
		if (getRMQ(x+1,mid)>=k)
		{
			get=mid;
			L=mid+1;
		}
		else
			R=mid-1;
	}
	return get;
}

inline void solve(int x,int k)
{
	int L=getL(rank[x+n0],k);
	int R=getR(rank[x+n0],k);
	int ans=0;
	if (x-k-1>0) ans+=calc(root[R],root[L-1],1,x-k-1);
	if (x+k+1<n0) ans+=calc(root[R],root[L-1],x+k+1,n0-1);
	printf("%d\n",ans);
}

void work()
{
	int T;
	cin>>T;
	while (T--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if (x==y)
		{
			printf("%d\n",n0-1);
			continue;
		}
		solve(x,y-x);
	}
}

int main()
{
	init();
	work();
	return 0;
}