#include <bits/stdc++.h>
using namespace std;
#define N 500005
#define ll long long
int n,cntP,rt,a[N];ll ans;struct Point {int w,sz,ch[2];ll vl,s,tg;}pt[N];
int New(ll vl) {pt[++cntP]=(Point) {rand(),1,{0,0},vl,vl,0};return cntP;}
void pu(int p)
{
	pt[p].sz=pt[pt[p].ch[0]].sz+pt[pt[p].ch[1]].sz+1;
	pt[p].s=pt[pt[p].ch[0]].s+pt[pt[p].ch[1]].s+pt[p].vl;
}
void mdf(int p,ll vl)
{if(!p) return;pt[p].vl+=vl;pt[p].s+=vl*pt[p].sz;pt[p].tg+=vl;}
void pd(int p)
{if(pt[p].tg) mdf(pt[p].ch[0],pt[p].tg),mdf(pt[p].ch[1],pt[p].tg),pt[p].tg=0;}
void split(int p,int x,int &pL,int &pR)
{
	if(!p) {pL=pR=0;return;}pd(p);
	if(x<=pt[pt[p].ch[0]].sz) pR=p,split(pt[p].ch[0],x,pL,pt[p].ch[0]);
	else pL=p,split(pt[p].ch[1],x-pt[pt[p].ch[0]].sz-1,pt[p].ch[1],pR);pu(p);
}
int merge(int pL,int pR)
{
	if(!pL || !pR) return pL|pR;
	if(pt[pL].w<pt[pR].w)
	{pd(pL);pt[pL].ch[1]=merge(pt[pL].ch[1],pR);pu(pL);return pL;}
	else {pd(pR);pt[pR].ch[0]=merge(pL,pt[pR].ch[0]);pu(pR);return pR;}
}
int find(ll vl)
{
	int p=rt,rk=0,t,res=pt[rt].sz+1;
	while(p)
	{
		pd(p);t=rk+pt[pt[p].ch[0]].sz+1;
		if(pt[p].vl<vl*t) res=t,p=pt[p].ch[0];else rk=t,p=pt[p].ch[1];
	}return res;
}
void upd(ll vl)
{
	int t=find(vl),p1,p2;split(rt,t-1,p1,p2);mdf(p2,vl);
	rt=merge(merge(p1,New(vl*t)),p2);
}
ll qry()
{
	int p=rt;ll s=0,t,res=0;
	while(p)
	{
		pd(p);t=s+pt[pt[p].ch[0]].s+pt[p].vl;res=max(res,t);
		if(pt[p].vl<0) p=pt[p].ch[0];else s=t,p=pt[p].ch[1];
	}return res;
}
int main()
{
	srand(time(0));scanf("%d",&n);
	for(int i=1,x;i<=n;++i) scanf("%d",&x),upd(x),ans=max(ans,qry());
	printf("%lld\n",ans);return 0;
}