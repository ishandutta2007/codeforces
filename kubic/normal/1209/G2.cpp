#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define mid ((l+r)/2)
const int lim=2e5;
int n,m,a[N];set<int> z[N];struct Seg {int mn,mx,pr,sf,vl,tg;}sg[N*4];
void pu(int p)
{
	sg[p].mn=min(sg[p*2].mn,sg[p*2+1].mn);sg[p].mx=max(sg[p*2].mx,sg[p*2+1].mx);
	sg[p].pr=sg[p].mn==sg[p*2].mn?sg[p*2].pr:max(sg[p*2].mx,sg[p*2+1].pr);
	sg[p].sf=sg[p].mn==sg[p*2+1].mn?sg[p*2+1].sf:max(sg[p*2].sf,sg[p*2+1].mx);
	if(sg[p*2].mn==sg[p*2+1].mn) sg[p].vl=sg[p*2].vl+sg[p*2+1].vl+max(sg[p*2].sf,sg[p*2+1].pr);
	else sg[p].vl=sg[p].mn==sg[p*2].mn?sg[p*2].vl:sg[p*2+1].vl;
}
void mdf(int p,int vl) {sg[p].mn+=vl;sg[p].tg+=vl;}
void pd(int p) {if(sg[p].tg) mdf(p*2,sg[p].tg),mdf(p*2+1,sg[p].tg),sg[p].tg=0;}
void upd1(int p,int l,int r,int x,int vl)
{
	if(l==r) {sg[p].mx=sg[p].pr=vl;return;}pd(p);
	if(x<=mid) upd1(p*2,l,mid,x,vl);else upd1(p*2+1,mid+1,r,x,vl);pu(p);
}
void upd2(int p,int l,int r,int qL,int qR,int vl)
{
	if(qL>qR) return;if(l>=qL && r<=qR) {mdf(p,vl);return;}pd(p);
	if(qL<=mid) upd2(p*2,l,mid,qL,qR,vl);if(qR>mid) upd2(p*2+1,mid+1,r,qL,qR,vl);pu(p); 
}
void ins(int x,int vl)
{
	int l,r;if(!z[vl].empty()) l=*z[vl].begin(),r=*--z[vl].end(),upd1(1,1,n,l,0),upd2(1,1,n,l,r-1,-1);
	z[vl].insert(x);l=*z[vl].begin();r=*--z[vl].end();upd1(1,1,n,l,z[vl].size());upd2(1,1,n,l,r-1,1);
}
void dlt(int x,int vl)
{
	int l,r;l=*z[vl].begin();r=*--z[vl].end();upd1(1,1,n,l,0);upd2(1,1,n,l,r-1,-1);z[vl].erase(x);
	if(!z[vl].empty()) l=*z[vl].begin(),r=*--z[vl].end(),upd1(1,1,n,l,z[vl].size()),upd2(1,1,n,l,r-1,1);
}
void slv() {printf("%d\n",n-sg[1].vl-sg[1].pr-sg[1].sf);}
int main()
{
	scanf("%d %d",&n,&m);for(int i=1;i<=n;++i) scanf("%d",&a[i]),z[a[i]].insert(i);
	for(int i=1,l,r;i<=lim;++i) if(!z[i].empty())
		l=*z[i].begin(),r=*--z[i].end(),upd1(1,1,n,l,z[i].size()),upd2(1,1,n,l,r-1,1);slv();
	for(int i=1,x,vl;i<=m;++i) scanf("%d %d",&x,&vl),dlt(x,a[x]),a[x]=vl,ins(x,a[x]),slv();return 0;
}