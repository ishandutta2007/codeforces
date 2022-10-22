#include <bits/stdc++.h>
using namespace std;
#define N 10000005
const int al=(1<<20)-1; 
int n,m,cntP,rt,bin[N];
struct Point {int vl,vl1,vl2,tg,ch[2];}pt[N];
int New()
{
	int p=bin[0]?bin[bin[0]--]:++cntP;
	pt[p]=(Point) {0,0,0,0,{0,0}};return p;
} 
void mdf(int p,int d,int vl)
{
	if(!p) return;int t1=pt[p].vl1,t2=pt[p].vl2;pt[p].tg^=vl;
	pt[p].vl1=(t1&(vl^al))|(t2&vl);pt[p].vl2=(t1&vl)|(t2&(vl^al));
	if(d>=0 && vl>>d&1) swap(pt[p].ch[0],pt[p].ch[1]);
}
void pd(int p,int d)
{
	if(pt[p].tg)
	{
		mdf(pt[p].ch[0],d-1,pt[p].tg);
		mdf(pt[p].ch[1],d-1,pt[p].tg);pt[p].tg=0;
	}
}
void pu(int p)
{
	pt[p].vl=pt[pt[p].ch[0]].vl+pt[pt[p].ch[1]].vl;
	pt[p].vl1=pt[pt[p].ch[0]].vl1|pt[pt[p].ch[1]].vl1;
	pt[p].vl2=pt[pt[p].ch[0]].vl2|pt[pt[p].ch[1]].vl2;
}
void ins(int &p,int d,int vl)
{
	if(!p) p=New();if(d<0) {pt[p]=(Point) {1,vl,vl^al};return;}
	ins(pt[p].ch[vl>>d&1],d-1,vl);pu(p);
}
void split(int p,int d,int vl,int &p1)
{
	if(!p || d<0) {p1=0;return;}pd(p,d);p1=New();
	if(vl>>d&1) split(pt[p].ch[1],d-1,vl,pt[p1].ch[1]);
	else
	{
		pt[p1].ch[1]=pt[p].ch[1];pt[p].ch[1]=0;
		split(pt[p].ch[0],d-1,vl,pt[p1].ch[0]);
	}pu(p);pu(p1);
}
int merge(int pL,int pR,int d)
{
	if(!pL || !pR) return pL|pR;
	if(d<0) {bin[++bin[0]]=pR;return pL;}pd(pL,d);pd(pR,d); 
	pt[pL].ch[0]=merge(pt[pL].ch[0],pt[pR].ch[0],d-1);
	pt[pL].ch[1]=merge(pt[pL].ch[1],pt[pR].ch[1],d-1);
	pu(pL);bin[++bin[0]]=pR;return pL; 
}
void upd(int p,int d,int vl)
{
	if(!p || d<0) return;vl&=pt[p].vl2;
	if(!(vl&pt[p].vl1)) {mdf(p,d,vl);return;}pd(p,d);
	if(vl>>d&1)
	{
		mdf(pt[p].ch[0],d-1,1<<d);
		pt[p].ch[1]=merge(pt[p].ch[0],pt[p].ch[1],d-1);
		pt[p].ch[0]=0;upd(pt[p].ch[1],d-1,vl);
	}else upd(pt[p].ch[0],d-1,vl),upd(pt[p].ch[1],d-1,vl);pu(p);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1,x;i<=n;++i) scanf("%d",&x),ins(rt,19,x);
	for(int i=1,op,l,r,vl,p1,p2;i<=m;++i)
	{
		scanf("%d %d %d",&op,&l,&r);split(rt,19,r,p1);
		if(l) split(rt,19,l-1,p2);else p2=rt,rt=0;
		if(op==1)
		{
			scanf("%d",&vl);mdf(p2,19,al);
			upd(p2,19,vl^al);mdf(p2,19,al);
		}if(op==2) scanf("%d",&vl),upd(p2,19,vl);
		if(op==3) scanf("%d",&vl),mdf(p2,19,vl);
		if(op==4) printf("%d\n",pt[p2].vl);
		rt=merge(merge(rt,p2,19),p1,19);
	}return 0;
}