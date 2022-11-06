#include<bits/stdc++.h>
#define re register
int k,dfn[200100],dep[200100],ed[200100],dfr[200100],fa[200100][20],tot,nwdep,nwv;
long long nnm;
struct nd
{
	int x,y,sz,tt;
	nd*ch[2],*fa;
	void pu(){sz=(ch[0]?ch[0]->sz:0)+(ch[1]?ch[1]->sz:0)+1;}
	void rotate()
	{
		re nd*x=fa;re bool k=(x->ch[1]==this);
		fa=x->fa;if(x->fa)x->fa->ch[x==x->fa->ch[1]]=this;
		x->ch[k]=ch[!k];if(ch[!k])ch[!k]->fa=x;
		ch[!k]=x;x->fa=this;
		x->pu();pu();
	}
	void splay()
	{
		for(;fa;rotate())if(fa->fa)
		{
			if((fa->ch[1]==this)==(fa->fa->ch[1]==fa))fa->rotate();
			else rotate();
		}
	}
}nn[1001000],*rt[150010],*cct=nn,*A;
struct eg{int to;eg*nx;}e[300100],*la[150100],*cnt=e;
inline void addE(re int a,re int b)
{
	*++cnt=(eg){b,la[a]};la[a]=cnt;
	*++cnt=(eg){a,la[b]};la[b]=cnt;
}
void dfs(re int a)
{
	dfn[a]=++tot;dfr[tot]=a;
	for(re eg*i=la[a];i;i=i->nx)if(i->to!=fa[a][0])
	{
		fa[i->to][0]=a;dep[i->to]=dep[a]+1;dfs(i->to);
	}
	ed[a]=tot;
}
int LCA(re int a,re int b)
{
	if(dep[a]<dep[b])std::swap(a,b);
	for(re int i=19;i>=0;i--)if(dep[a]-(1<<i)>=dep[b])a=fa[a][i];
	for(re int i=19;i>=0;i--)if(fa[a][i]!=fa[b][i])a=fa[a][i],b=fa[b][i];
	return a==b?a:fa[a][0];
}
int up(re int a,re int b)
{
	for(re int i=19;i>=0;i--)if(b>=(1<<i))a=fa[a][i],b-=(1<<i);
	return a;
}
void dfsm(re nd*b)
{
	if(!b)return;
	dfsm(b->ch[0]);
	if(nwdep-b->x>=k)
	{
		nnm+=nwv;
	}
	else if(b->tt&&dep[dfr[b->y]]-(2*b->x-nwdep+k)>=0)
	{
		//printf("***a***%d %d %d %d %d\n",nwv,nwdep,b->x,k,nnm);
		re int ww=up(dfr[b->y],dep[dfr[b->y]]-(2*b->x-nwdep+k));
		re nd*ala=0;
		for(re nd*i=A;i;)
		{
			if(i->x<b->x||(i->x==b->x&&i->y<=ed[ww]))ala=i,i=i->ch[1];
			else A=i,i=i->ch[0];
		}
		if(ala)ala->splay();
		A->splay();
		if(A->x<b->x||(A->x==b->x&&A->y<=ed[ww]))nnm+=A->sz;
		else if(A->ch[0])nnm+=A->ch[0]->sz;
		ala=0;
		for(re nd*i=A;i;)
		{
			if(i->x<b->x||(i->x==b->x&&i->y<dfn[ww]))ala=i,i=i->ch[1];
			else A=i,i=i->ch[0];
		}
		if(ala)ala->splay();
		A->splay();
		if(A->x<b->x||(A->x==b->x&&A->y<dfn[ww]))nnm-=A->sz;
		else if(A->ch[0])nnm-=A->ch[0]->sz;
		//printf("***a***%d %d %d %d %d\n",nwv,nwdep,b->x,k,nnm);
	}
		if(b->tt&&dep[dfr[b->y]]-b->x>=k)
		{
			re int ww=up(dfr[b->y],dep[dfr[b->y]]-b->x-k);
			re nd*ala=0;
			for(re nd*i=A;i;)
			{
				if(i->x<b->x||(i->x==b->x&&i->y<=ed[ww]))ala=i,i=i->ch[1];
				else A=i,i=i->ch[0];
			}
			if(ala)ala->splay();
			A->splay();
			if(A->x<b->x||(A->x==b->x&&A->y<=ed[ww]))nnm-=A->sz;
			else if(A->ch[0])nnm-=A->ch[0]->sz;
			ala=0;
			for(re nd*i=A;i;)
			{
				if(i->x<b->x||(i->x==b->x&&i->y<dfn[ww]))ala=i,i=i->ch[1];
				else A=i,i=i->ch[0];
			}
			if(ala)ala->splay();
			A->splay();
			if(A->x<b->x||(A->x==b->x&&A->y<dfn[ww]))nnm+=A->sz;
			else if(A->ch[0])nnm+=A->ch[0]->sz;
		}
	dfsm(b->ch[1]);
}
void dfsa(re nd*b)
{
	if(!b)return;
	dfsa(b->ch[0]);
	re nd*vv=b->ch[1];
	re int wkw=0;
	b->ch[0]=b->ch[1]=b->fa=0;b->sz=1;
	for(re nd*i=A;i;)
	{
		i->sz++;
		if(i->x<b->x||(i->x==b->x&&i->y<b->y))A=i,i=i->ch[1],wkw=1;
		else A=i,i=i->ch[0],wkw=0;
	}
	b->fa=A;A->ch[wkw]=b;A=b;A->splay();
	dfsa(vv);
}
nd*meg(re nd*a,re nd*b)
{
	if(!a)return b;
	if(!b)return a;
	if(a->sz<b->sz)std::swap(a,b);
	re nd*ala=0;
	for(re nd*i=a;i;)
	{
		if(nwdep-i->x>=k)ala=i,i=i->ch[1];
		else a=i,i=i->ch[0];
	}
	if(ala)ala->splay();
	a->splay();
	if(nwdep-a->x>=k)nwv=a->sz;
	else nwv=(a->ch[0]?a->ch[0]->sz:0);
	A=a;
	dfsm(b);
	dfsa(b);
	return A;
}
void ddfs(re int a,re int fa)
{
	for(re eg*i=la[a];i;i=i->nx)if(i->to!=fa)
	{
		ddfs(i->to,a);
		if(rt[i->to])
		{
			re nd*aa=rt[i->to];
			for(re nd*j=aa;j;)
			{
				if(j->x<dep[a])aa=j,j=j->ch[1];
				else j=j->ch[0];
			}
			aa->splay();
			if(aa->x<dep[a])
			{
				aa->ch[1]=0;
				rt[i->to]=aa;aa->pu();
			}else rt[i->to]=0;
			nwdep=dep[a];
			rt[a]=meg(rt[a],rt[i->to]);
			//printf("**a**%d %d %d %d %lld\n",a,i->to,rt[i->to]?rt[i->to]->x:-1,rt[i->to]?rt[i->to]->sz:-1,nnm);
		}
	}
}
int main()
{
	re int n,m,x,y;
	scanf("%d%d%d",&n,&m,&k);
	for(re int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		addE(x,y);
	}
	dep[1]=1;dfs(1);
	for(re int j=1;j<=19;j++)
		for(re int i=1;i<=n;i++)fa[i][j]=fa[fa[i][j-1]][j-1];
	for(re int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		if(dfn[x]>dfn[y])std::swap(x,y);
		re int z=dep[LCA(x,y)];
		*++cct=(nd){z,dfn[y],1,1};
		nwdep=dep[x];
		if(dep[x]!=z)rt[x]=meg(rt[x],cct);
		*++cct=(nd){z,dfn[x],1,0};
		nwdep=dep[y];
		if(dep[y]!=z)rt[y]=meg(rt[y],cct);
	}
	ddfs(1,0);
	printf("%lld\n",nnm);
}