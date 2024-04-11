#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc ((p<<1)+1)
#define rc ((p<<1)+2)
using namespace std;
const int N=2e5+5,S=N+1,Q=5e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct line
{
	int next,to;
}e[N];
struct query
{
	int x,y,t,p;
	bool operator<(query b)const{return x<b.x;}
}queries[2*Q];
int n,q,p[N],l[N],to[S][26],size=1,fail[S],ans[Q],qu[S],qf,qr,tp[N];
int hd[S],cnt,siz[S],dfn[S],ind,sum[4*S];
char s[N+1];
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
int insert(const char *str)
{
	int j=0;
	for(int i=0;str[i];++i)
	{
		int x=str[i]-'a';
		if(!to[j][x])to[j][x]=size++;
		j=to[j][x];
	}
	return j;
}
void build()
{
	F(i,0,26)if(to[0][i])qu[qr++]=to[0][i];
	while(qf<qr)
	{
		int u=qu[qf++];
		adline(fail[u],u);
		F(i,0,26)if(to[u][i])fail[qu[qr++]=to[u][i]]=to[fail[u]][i];
		else to[u][i]=to[fail[u]][i];
	}
}
void dfs(int u)
{
	dfn[u]=ind++;
	siz[u]=1;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;
		dfs(v);
		siz[u]+=siz[v];
	}
}
void update(int p,int l,int r,int x)
{
	int mid=(l+r)>>1;
	++sum[p];
	if(r-l<2)return;
	if(x<mid)update(lc,l,mid,x);
	else update(rc,mid,r,x);
}
int querysum(int p,int l,int r,int x,int y)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return 0;
	if(x<=l&&r<=y)return sum[p];
	return querysum(lc,l,mid,x,y)+querysum(rc,mid,r,x,y);
}
int main()
{
	int ii=0;
	read(n);read(q);
	F(i,0,n)
	{
		scanf("%s",s+p[i]);
		tp[i]=insert(s+p[i]);
		while(s[p[i]+l[i]])++l[i];
		if(i!=n-1)p[i+1]=p[i]+l[i];
	}
	F(i,0,size)hd[i]=-1;
	build();
	dfs(0);
	F(i,0,q)
	{
		int l,r,k;read(l);read(r);read(k);
		--l;--k;
		queries[(i<<1)+0].x=l;
		queries[(i<<1)+0].y=k;
		queries[(i<<1)+0].t=-1;
		queries[(i<<1)+0].p=i;
		queries[(i<<1)+1].x=r;
		queries[(i<<1)+1].y=k;
		queries[(i<<1)+1].t=1;
		queries[(i<<1)+1].p=i;
	}
	sort(queries,queries+2*q);
	for(int i=0;i<n;++i)
	{
		int j=0;
		for(;ii<2*q&&queries[ii].x==i;++ii)
		{
			query qq=queries[ii];
			ans[qq.p]+=qq.t*querysum
			(0,0,size,dfn[tp[qq.y]],dfn[tp[qq.y]]+siz[tp[qq.y]]);
		}
		for(int k=p[i];k<p[i]+l[i];++k)
		{
			j=to[j][s[k]-'a'];
			update(0,0,size,dfn[j]);
		}
	}
	for(;ii<2*q;++ii)
	{
		query qq=queries[ii];
		ans[qq.p]+=qq.t*querysum
		(0,0,size,dfn[tp[qq.y]],dfn[tp[qq.y]]+siz[tp[qq.y]]);
	}
	F(i,0,q)printf("%d\n",ans[i]);
	return 0;
}