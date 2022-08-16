#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int MaxN=1<<18;

int N,K,n,len;
char s[MaxN];
int _s[MaxN];
int from[MaxN],used[MaxN],limit[MaxN];
int x[MaxN<<1],y[MaxN<<1],sum[MaxN],wv[MaxN],sa[MaxN],rank[MaxN],h[MaxN];
void build_sa()
{
	int m=N+255;
	for (int i=1;i<=m;++i) sum[i]=0;
	for (int i=1;i<=n;++i) sum[x[i]]++;
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
		p=x[sa[1]]=1;
		for (int i=2;i<=n;++i)
		{
			if (!(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+j]==y[sa[i-1]+j])) ++p; 
			x[sa[i]]=p;
		}
	}
}

int pow[20],lg[MaxN];
int RMQ[MaxN][20];

void build_height()
{
	for (int i=1;i<=n;++i) rank[sa[i]]=i;
	int k=0;
	for (int i=1;i<=n;++i)
	{
		if (k) --k;
		while (x[i+k]==x[sa[rank[i]-1]+k]) ++k;
		h[rank[i]]=k;
	}
}

void build_RMQ()
{
	for (int i=pow[0]=1;i<20;++i) pow[i]=pow[i-1]<<1;
	for (int i=2;i<=n;++i) lg[i]=lg[i/2]+1;
	for (int i=1;i<=n;++i) RMQ[i][0]=h[i];
	for (int k=1;k<20;++k)
		for (int i=1;i<=n;++i)
		{
			RMQ[i][k]=RMQ[i][k-1];
			if (i+pow[k-1]<=n) RMQ[i][k]=min(RMQ[i][k],RMQ[i+pow[k-1]][k-1]);
		}
}

inline int get_RMQ(int L,int R)
{
	if (L>R) return limit[sa[L-1]];
	int x=lg[R-L+1];
	return min(RMQ[L][x],RMQ[R-pow[x]+1][x]);
}

void init()
{
	scanf("%d%d\n",&N,&K);
	for (int i=1;i<=N;++i)
	{
		gets(s+1);
		len=strlen(s+1);
		for (int p=1;p<=len;++p)
		{
			x[++n]=s[p];
			from[n]=i;
			limit[n]=len-p+1;
		}
		x[++n]=i+255;
	}
	for (int i=1;i<=n;++i) _s[i]=x[i];
	build_sa();
	for (int i=1;i<=n;++i) x[i]=_s[i];
	build_height();
	build_RMQ();
}

int up[MaxN],gv[MaxN];
long long ans[MaxN];
int tree[MaxN<<1];

inline void add(int k,int L,int R,int x,int y,int d)
{
	if (L==x&&R==y)
	{
		tree[k]=max(tree[k],d);
		return;
	}
	int mid=(L+R)>>1;
	if (y<=mid)
		add(k<<1,L,mid,x,y,d);
	else if (x>mid)
		add(k<<1|1,mid+1,R,x,y,d);
	else
	{
		add(k<<1,L,mid,x,mid,d);
		add(k<<1|1,mid+1,R,mid+1,y,d);
	}
}

inline int get(int x)
{
	int p=0;
	for (int k=x+MaxN-1;k;k>>=1)
		p=max(p,tree[k]);
	return p;
}

void work()
{
	int now=1;
	int j=1;
	used[from[sa[1]]]=1;
	for (int i=1;i<=n;++i)
	{
		while (now<K)
		{
			++j;
			if (j>n) break;
			if (!(used[from[sa[j]]]++)) ++now;
		}
		if (j>n) break;
		int p=get_RMQ(i+1,j);
		add(1,1,MaxN,i,j,p);
		up[j+1]=max(up[j+1],p);
		if (!--used[from[sa[i]]]) --now;
	}
	for (int i=1;i<=n;++i)
		gv[i]=get(i);
	int p=0;
	for (int i=1;i<=n;++i)
	{
		p=min(max(p,up[i]),h[i]);
		gv[i]=max(gv[i],p);
	}
	for (int i=1;i<=n;++i)
		ans[from[sa[i]]]+=gv[i];
	for (int i=1;i<=N;++i)
		printf("%I64d ",ans[i]);
}

int main()
{
	init();
	work();
	return 0;
}