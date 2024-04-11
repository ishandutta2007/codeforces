#include<bits/stdc++.h>
using namespace std;
#define re register
struct nd
{
	int v;
	nd*ch[2],*fa;
	bool rt(){return (!fa)||(fa->ch[0]!=this&&fa->ch[1]!=this);}
	bool tp(){return fa->ch[1]==this;}
	void rotate()
	{
		re bool k=tp();re nd*x=fa;v=x->v;
		fa=x->fa;if(!x->rt())x->fa->ch[x->tp()]=this;
		x->ch[k]=ch[!k];if(ch[!k])ch[!k]->fa=x;
		ch[!k]=x;x->fa=this;
	}
	void splay()
	{
		for(;!rt();rotate())if(!fa->rt())(fa->tp()==tp()?fa->rotate():rotate());
	}
}nn[200100];
int dep[200100],p[200100],q[200100],xx[200100],yy[200100],ans[200100];
struct par{int x,y,no;}pp[200100];
inline bool cmp(const par&A,const par&B){return A.y==B.y?A.x<B.x:A.y<B.y;}
int access(re int a,re int t)
{
	re nd*x=&nn[a],*y=0;
	for(;x!=(&nn[0]);x=x->fa)
	{
		x->splay();
		if(x->v+2*dep[x-nn]>t)break;
		if(x->ch[1])x->ch[1]->v=x->v;x->ch[1]=y;y=x;
	}
	if(y)y->v=t-dep[x-nn]*2;
	return t-dep[x-nn]*2+dep[a];
}
int main()
{
	re int n,m;
	scanf("%d%d",&n,&m);
	for(re int i=1;i<=n;i++)scanf("%d",&p[i]),dep[i]=dep[p[i]]+1,nn[i].v=-1e9,nn[i].fa=&nn[p[i]];
	for(re int i=1;i<=m;i++)
	{
		scanf("%d%d",&xx[i],&yy[i]);
		pp[i]=(par){xx[i],yy[i]+dep[xx[i]],i};
	}
	sort(pp+1,pp+m+1,cmp);
	for(re int i=1;i<=m;i++)
	{
		ans[pp[i].no]=access(pp[i].x,pp[i].y);
	}
	for(re int i=1;i<=m;i++)printf("%d ",ans[i]);
}