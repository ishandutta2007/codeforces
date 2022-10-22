#include <bits/stdc++.h>
using namespace std;
#define N 400005
#define mid ((l+r)/2)
int n,m,c;map<int,bool> vs[N];
struct Seg {int vl,tg;}sg[N*4];multiset<int> z;
void mdf(int p,int vl) {sg[p].vl+=vl;sg[p].tg+=vl;}
void pu(int p) {sg[p].vl=max(sg[p*2].vl,sg[p*2+1].vl);}
void pd(int p)
{if(sg[p].tg) mdf(p*2,sg[p].tg),mdf(p*2+1,sg[p].tg),sg[p].tg=0;}
void build(int p,int l,int r)
{
	if(l==r) {sg[p].vl=l-n*2-1;return;}
	build(p*2,l,mid);build(p*2+1,mid+1,r);pu(p);
}
void upd(int p,int l,int r,int qL,int qR,int vl)
{
	if(l>=qL && r<=qR) {mdf(p,vl);return;}pd(p);
	if(qL<=mid) upd(p*2,l,mid,qL,qR,vl);
	if(qR>mid) upd(p*2+1,mid+1,r,qL,qR,vl);pu(p);
}
int qMx(int p,int l,int r,int qL,int qR)
{
	if(l>=qL && r<=qR) return sg[p].vl;pd(p);int res=0;
	if(qL<=mid) res=qMx(p*2,l,mid,qL,qR);
	if(qR>mid) res=max(res,qMx(p*2+1,mid+1,r,qL,qR));return res;
}
int main()
{
	scanf("%d %d %d",&n,&m,&c);z.insert(0);build(1,1,n*2);
	for(int i=1,x,y,r,t;i<=c;++i)
	{
		scanf("%d %d",&x,&y);t=y+abs(x-m);
		if(vs[x][y]) z.erase(z.find(t)),upd(1,1,n*2,1,t,-1);
		else z.insert(t),upd(1,1,n*2,1,t,1);
		vs[x][y]^=1;r=max(n,*--z.end());
		printf("%d\n",max(qMx(1,1,n*2,1,r)+n,0));
	}return 0;
}