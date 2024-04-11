#include<bits/stdc++.h>
using namespace std;
#define re register
int w[200100],sz[200100],szh,n;
bool bo[200100];
struct eg{int to,l;eg*nx;}e[400100],*la[200100],*cnt=e;
inline void addE(re int a,re int b,re int c)
{
	*++cnt=(eg){b,c,la[a]};la[a]=cnt;
	*++cnt=(eg){a,c,la[b]};la[b]=cnt;
}
double ans,nans=1e100;
int hv,ansc;
void clac(re int a,re int fa,re int len)
{
	ans+=sqrt(len)*w[a];
	for(re eg*i=la[a];i;i=i->nx)if(i->to!=fa)clac(i->to,a,len+i->l);
}
void clas(re int a,re int fa,re int len)
{
	ans+=len*sqrt(len)*w[a];
	for(re eg*i=la[a];i;i=i->nx)if(i->to!=fa)clas(i->to,a,len+i->l);
}
void dfs(re int a,re int fa)
{
	sz[a]=1;
	for(re eg*i=la[a];i;i=i->nx)if(!bo[i->to]&&i->to!=fa)dfs(i->to,a),sz[a]+=sz[i->to];
}
void dfs1(re int a,re int fa)
{
	bool hvb=1;
	for(re eg*i=la[a];i;i=i->nx)if(!bo[i->to]&&i->to!=fa)dfs1(i->to,a),hvb&=sz[i->to]<=szh/2;
	hvb&=(szh-sz[a])<=szh/2;
	if(hvb)hv=a;
}
void dc(re int a)
{
	dfs(a,0);szh=sz[a];
	dfs1(a,0);
	a=hv;
	bo[a]=1;
	ans=0;
	clas(a,0,0);
	if(ans<nans)nans=ans,ansc=a;
	re double nw=-1e100;re int ck=0;
	for(re eg*i=la[a];i;i=i->nx)
	if(!bo[i->to]){
		ans=0;
		clac(i->to,a,i->l);
		if(ans>nw)nw=ans,ck=i->to;
	}
	if(ck)dc(ck);
}
int main()
{
	re int x,y,l;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)scanf("%d",&w[i]);
	for(re int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&l);
		addE(x,y,l);
	}
	dc(1);
	printf("%d %.10lf\n",ansc,nans);
}