#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
#define re register
struct edge
{
	int to,w;edge*next;
}e[900100];
edge*cnt=e,*last[300100],*p[300100];
inline void add(re edge**la,re int a1,re int a2,re int w){*(++cnt)=(edge){a2,w,la[a1]};la[a1]=cnt;}
struct heap
{
	heap *l,*r;int de,len;
	long long f,mi,add;
	inline void pd(){if(add)f+=add,mi+=add,(l?l->add+=add:0),(r?r->add+=add:0),add=0;}
	inline void mar()
	{
		mi=min((r?r->mi+r->add:1ll<<60),(l?l->mi+l->add:1ll<<60));mi=min(mi,f);
		if(r&&(!l||l->len<r->len)){re heap* tmp=l;l=r;r=tmp;}
		len=(r?r->len+1:1);
	}
}h[300100];
heap*now=h,*root[300100];
int dep[300100];
heap* marge(re heap* x1,re heap* x2)
{
	if(!x1)return x2;
	if(!x2)return x1;
	x1->pd(),x2->pd();
	if(x1->de>x2->de){x1->r=marge(x1->r,x2);x1->mar();return x1;}
	else{x2->r=marge(x1,x2->r);x2->mar();return x2;}
}
void init(re int a,re int ff)
{
	re int x;
	for(re edge*i=last[a];i!=e;i=i->next)if((x=i->to)!=ff)
	dep[x]=dep[a]+1,init(x,a);
}
void dfs(re int a,re int ff)
{
	re int x,x1=dep[a];
	re long long y1=0;
	for(re edge*i=last[a];i!=e;i=i->next)if((x=i->to)!=ff)
	{
		dfs(x,a);
		while(root[x]&&root[x]->de>x1)root[x]=marge(root[x]->l,root[x]->r);
		if(!root[x])puts("-1"),exit(0);
		y1+=root[x]->mi;
	}
	for(re edge*i=p[a];i!=e;i=i->next)
	{
		*(++now)=(heap){0,0,i->to,1,(y1+(i->w)),(y1+(i->w)),0};
		root[a]=marge(now,root[a]);
	}
	for(re edge*i=last[a];i!=e;i=i->next)if((x=i->to)!=ff)
	{
		(root[x]->add)+=y1-(root[x]->mi);
		root[a]=marge(root[a],root[x]);
	}
	if(!root[a])puts("-1"),exit(0);
}
int main()
{
	re int n,m,x,y,z;h->mi=1ll<<60;
	scanf("%d%d",&n,&m);
	for(re int i=1;i<=n;i++)last[i]=p[i]=e;
	for(re int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		add(last,x,y,0),add(last,y,x,0);
	}dep[1]=1;
	init(1,0);
	add(p,1,dep[1],0);
	for(re int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		add(p,x,dep[y],z);
	}
	dfs(1,0);
	printf("%lld",(root[1]->mi)+(root[1]->add));
}