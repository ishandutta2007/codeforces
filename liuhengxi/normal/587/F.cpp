#include<cstdio>
#include<cmath>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using std::sqrt;using std::min;using std::max;using std::sort;
const int N=1e5+5,Sigma=27;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,Q,s[N],t[N][Sigma],fail[N],ind,queue[N],qf,qr,m,pos[N];
long long ans[N],c[N];
char str[N];
struct query
{
	int r,k,type,id;
	bool operator<(query b)const
	{return type!=b.type?type<b.type:(type?
	(__builtin_expect(k!=b.k,1)?k<b.k:r<b.r):r<b.r);}
}q[2*N];
struct dec
{
	int n,m,bl[N],a[N],b[N];
	void init(int n1,int m1)
	{
		n=n1;m=m1;
		F(i,0,n+1)bl[i]=i/m;
	}
	void add(int l,int r,int v)
	{
		F(i,bl[l],bl[r])b[i]+=v;
		F(i,bl[l]*m,l)a[i]-=v;
		F(i,bl[r]*m,r)a[i]+=v;
	}
	int query(int x){return b[bl[x]]+a[x];}
}d;
namespace fail_tree
{
	struct line
	{
		int next,to;
	}e[2*N];
	int hd[N],cnt,dfn[N],ind,siz[N];
	inline void init(int n){F(i,0,n)hd[i]=-1;}
	inline void adline(int u,int v)
	{
		e[cnt].to=v;
		e[cnt].next=hd[u];
		hd[u]=cnt++;
	}
	void dfs(int u)
	{
		dfn[u]=ind++;
		for(int i=hd[u];~i;i=e[i].next){int v=e[i].to;dfs(v);siz[u]+=siz[v];}
		++siz[u];
	}
	void dfs2(int u)
	{
		for(int i=hd[u];~i;i=e[i].next){int v=e[i].to;dfs2(v);c[u]+=c[v];}
	}
}
using fail_tree::dfn;using fail_tree::siz;
int insert(char *s)
{
	int j=0;
	for(int i=0;s[i];++i)
	{
		int x=s[i]^=96;
		if(!t[j][x])t[j][x]=++ind;
		j=t[j][x];
	}
	return j;
}
void build()
{
	F(i,1,27)if(t[0][i])queue[qr++]=t[0][i];
	while(qf<qr)
	{
		int u=queue[qf++];
		fail_tree::adline(fail[u],u);
		F(i,1,27)if(t[u][i])fail[queue[qr++]=t[u][i]]=t[fail[u]][i];
		else t[u][i]=t[fail[u]][i];
	}
}
void small(int k)
{
	int j=0;
	F(i,0,k)
	{
		int contrib=0,u=0;
		while(j<q[i].r)d.add(dfn[s[j]],dfn[s[j]]+siz[s[j]],1),++j;
		F(p,pos[q[i].k],pos[q[i].k+1])contrib+=d.query(dfn[u=t[u][(int)str[p]]]);
		ans[q[i].id>>1]+=(((q[i].id&1)<<1)-1)*contrib;
	}
}
inline void big(int l,int r,int k)
{
	int j=0,u=0;long long tot=0;
	F(i,0,ind)c[i]=0;
	F(p,pos[k],pos[k+1])++c[u=t[u][(int)str[p]]];
	fail_tree::dfs2(0);
	F(i,l,r)
	{
		while(j<q[i].r)tot+=c[s[j++]];
		ans[q[i].id>>1]+=(((q[i].id&1)<<1)-1)*tot;
	}
}
int main()
{
	read(n);read(Q);
	F(i,0,n)
	{
		scanf("%s",str+pos[i]),s[i]=insert(str+pos[i]);
		for(pos[i+1]=pos[i];str[pos[i+1]];++pos[i+1]);
	}
	fail_tree::init(++ind);
	build();
	fail_tree::dfs(0);
	m=max(min((int)sqrt(ind<<3),ind),1);
	d.init(ind,m);
	F(i,0,Q)
	{
		int l,r,k;read(l);read(r);read(k);--l;--k;
		q[i<<1].r=l,q[i<<1].k=k;
		q[i<<1|1].r=r,q[i<<1|1].k=k;
		q[i<<1].type=q[i<<1|1].type=pos[k+1]-pos[k]>=m;
	}
	Q<<=1;
	F(i,0,Q)q[i].id=i;
	sort(q,q+Q);
	q[Q].type=1;
	F(i,0,Q+1)if(q[i].type)
	{
		small(i);
		F(j,0,n)
		{
			int I=i;while(I<Q&&q[I].k==j)++I;
			if(I>i)big(i,I,j);
			i=I;
		}
	}
	Q>>=1;
	F(i,0,Q)printf("%lld\n",ans[i]);
	return 0;
}