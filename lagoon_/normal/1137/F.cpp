#include<bits/stdc++.h>
using namespace std;
#define re register
inline int rl()
{
	re int x;re char c;
	for(c=getchar();!isdigit(c);c=getchar());x=c-'0';
	for(c=getchar();isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x;
}
struct node
{
	node*ch[2],*fa;
	int sz,vl;bool rev;
	inline bool rt(){return !fa||(fa->ch[0]!=this&&fa->ch[1]!=this);}
	inline void res()
	{
		rev^=1;swap(ch[0],ch[1]);
	}
	inline void pd()
	{
		if(rev)
		{
			if(ch[0])ch[0]->res();
			if(ch[1])ch[1]->res();
			rev=0;
		}if(ch[0])ch[0]->vl=vl;
		if(ch[1])ch[1]->vl=vl;
	}
	void pda()
	{
		if(!rt())fa->pda();
		pd();
	}
	inline void rotate()
	{
		re bool k=fa->ch[1]==this;
		re node*x=fa,*y=x->fa;
		fa=x->fa;if(!x->rt())y->ch[y->ch[1]==x]=this;
		sz=x->sz;x->sz-=(ch[k]?ch[k]->sz:0)+1;
		x->ch[k]=ch[!k];if(ch[!k])ch[!k]->fa=x;
		ch[!k]=x;x->fa=this;
	}
	void splay()
	{
		pda();
		while(!rt())
		{
			if(!fa->rt()){(fa->ch[1]==this)==(fa->fa->ch[1]==fa)?fa->rotate():rotate();}
			rotate();
		}
	}
}nd[200100];
int col[400100],n,q,nm,cnt,no[200100];
void add(re int a,re int ad){for(;a<=n+q;a+=a&-a)col[a]+=ad;}
int sum(re int a){re int sm=0;for(;a;a^=a&-a)sm+=col[a];return sm;}
void access(re int a)
{
	re node*x=nd+a,*y=0;
	for(;x;y=x,x=x->fa)
	{
		x->splay();
		if(x->ch[1])x->sz-=x->ch[1]->sz;
		add(x->vl,-x->sz);
		x->ch[1]=y;if(y)x->sz+=y->sz,y->fa=x;
	}
}
void makeroot(re int a)
{
	re node*x=nd+a;
	access(a);x->splay();x->res();
}
void mdf(re int a)
{
	makeroot(a);nd[a].vl=++nm;add(nm,nd[a].sz);
}
int qus(re int a)
{
	re node*x=nd+a;
	x->splay();
	return sum(x->vl-1)+(x->ch[1]?x->ch[1]->sz:0)+1;
}
struct edge{int to;edge*nx;}e[400100],*cct=e,*la[200100];
inline void addE(re int a,re int b)
{
	*++cct=(edge){b,la[a]};la[a]=cct;
	*++cct=(edge){a,la[b]};la[b]=cct;
}
void dfs(re int a,re int ff)
{
	nd[a].sz=1;nd[a].vl=no[a];add(no[a],1);
	for(re edge*i=la[a];i;i=i->nx)if(i->to!=ff)
	{nd[i->to].fa=nd+a;
		dfs(i->to,a);
	}
}
int d[200100],qq[200100],q1;
inline bool cmp(re int a,re int b){return a>b;}
int main()
{
	re int x,y;
	re char c;
	n=rl(),q=rl();
	for(re int i=1;i<n;i++)
	{
		x=rl(),y=rl();
		addE(x,y);d[x]++;d[y]++;
	}
	for(re int i=1;i<=n;i++)if(d[i]==1)qq[++q1]=i;
	make_heap(qq+1,qq+q1+1,cmp);
	for(re int i=1;i<=n;i++)
	{
		x=qq[1];pop_heap(qq+1,qq+q1+1,cmp);q1--;no[x]=i;
		for(re edge*ii=la[x];ii;ii=ii->nx)
		{
			d[ii->to]--;
			if(d[ii->to]==1)qq[++q1]=ii->to,push_heap(qq+1,qq+q1+1,cmp);
		}
	}
	dfs(n,0);nm=n;
	for(re int i=1;i<=q;i++)
	{
		for(c=getchar();c!='w'&&c!='c'&&c!='u';c=getchar());
		if(c=='u')
		{
			getchar();x=rl();
			mdf(x);
		}
		else if(c=='w')
		{
			getchar();getchar();getchar();x=rl();
			printf("%d\n",qus(x));
		}
		else
		{
			getchar();getchar();getchar();getchar();getchar();getchar();
			x=rl(),y=rl();
			printf("%d\n",qus(x)<qus(y)?x:y);
		}
	}
}