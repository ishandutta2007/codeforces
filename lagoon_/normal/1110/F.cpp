#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cmath>
using namespace std;
#define re register
#define cmin(a,b)((a)<(b)?(a):(b))
#pragma GCC optimize(2)
char B[1<<26],*S=B;int F(){for(;*S<'-';S++);register int x=*S++-'0';for(;*S>='0';x=(x<<3)+(x<<1)+*S++-'0');return x;}
char U[1<<26],*O=U,stk[200];
void pr(re unsigned long long x){if(!x)*O++='0';else{re int i=0;unsigned long long y;for(;x;y=x,stk[++i]=(y-((x/=10)<<3)-(x<<1))+'0');for(;i;*O++=stk[i--]);};*O++='\n';}
struct node
{
	long long f,tg;node*l,*r;
}nd[2000100],*cnt=nd,*bb;
int l1,r1,m1,dfn[500100],ed[500100],id[500100],tot;
struct edge{int to,v;edge*nx;}e[4000100],qq[500100],*la[500100],*qs[500100],*cmt=e,*cc;
long long d[500100],ans[500100];
void build(node*&a,re int l,re int r)
{
	if(!a)a=cnt++;
	if(l==r)a->f=la[l]?1ll<<60:d[l];
	else
	{
		re int mid=(l+r)>>1;
		build(a->l,l,mid);
		build(a->r,mid+1,r);
		a->f=cmin(a->l->f,a->r->f);
	}
}
long long query(re node*a,re int l,re int r)
{
	if(l>=l1&&r<=r1)return a->f;
	re long long x=1ll<<60,y=1ll<<60;
	re int mid=(l+r)>>1;
	if(l1<=mid)x=query(a->l,l,mid);
	if(r1>mid)y=query(a->r,mid+1,r);
	return cmin(x,y)+a->tg;
}
void add(re node*a,re int l,re int r)
{
	if(l>=l1&&r<=r1){a->f+=m1,a->tg+=m1;return;}
	re int mid=(l+r)>>1;
	if(l1<=mid)add(a->l,l,mid);
	if(r1>mid)add(a->r,mid+1,r);
	a->f=cmin(a->l->f,a->r->f)+a->tg;
}
inline void addE(re int a,re int b,re int c){*++cmt=(edge){b,c,la[a]};la[a]=cmt;}
inline void addQ(re int a,re int b,re int c){*++cmt=(edge){b,c,qs[a]};qs[a]=cmt;}
int nx;
inline bool cmp(const edge&A,const edge&B){return A.v<B.v;}
void dfs(re int a)
{
	dfn[a]=++tot;
	for(re edge*i=la[a];i;i=i->nx)d[i->to]=d[a]+i->v,dfs(i->to);
	ed[a]=tot+a-dfn[a];
}
void dfs1(re int a)
{
	for(re edge*i=qs[a];i;i=i->nx)
	{
		l1=i->to,r1=i->v;
		ans[i-cc]=query(nd,1,tot)+d[a];
	}
	for(re edge*i=la[a];i;i=i->nx)
	{
		l1=i->to,r1=ed[i->to],m1=-i->v*2;add(nd,1,tot);
		dfs1(i->to);
		l1=i->to,r1=ed[i->to],m1=i->v*2;add(nd,1,tot);
	}
}
int main()
{
	fread(B,1,1<<26,stdin);
	re int n=F(),q=F(),x,y,z;
	for(re int i=2;i<=n;i++)x=F(),y=F(),addE(x,i,y);
	dfs(1);cc=cmt;
	for(re int i=1;i<=q;i++)
	{
		x=F(),y=F(),z=F();
		addQ(x,y,z);
	}build(bb,1,tot);
	dfs1(1);
	for(re int i=1;i<=q;i++)
	{
		pr(ans[i]);
	}
	fwrite(U,1,O-U,stdout);
}