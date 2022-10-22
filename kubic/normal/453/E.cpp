#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define M 5000005
#define ll long long
#define mid ((l+r)/2)
const int lim=1e5;
int n,m,a[N],vl[N][2];
struct Node
{
	int x,w;
	bool operator < (Node t) const {return x<t.x;}
};set<Node> z;set<Node>::iterator it;
int cntS,rt[N];struct Seg {int ch[2];ll vl[2];}sg[M];
ll min(ll x,ll y) {return x<y?x:y;}
void upd(int p,int &p1,int l,int r,int x,int vl,int fl)
{
	sg[p1=++cntS]=sg[p];sg[p1].vl[fl]+=vl;if(l==r) return;
	if(x<=mid) upd(sg[p].ch[0],sg[p1].ch[0],l,mid,x,vl,fl);
	else upd(sg[p].ch[1],sg[p1].ch[1],mid+1,r,x,vl,fl);
}
ll qSm(int p,int l,int r,int qL,int qR,int fl)
{
	if(!p || qL>qR) return 0;
	if(l>=qL && r<=qR) return sg[p].vl[fl];ll res=0;
	if(qL<=mid) res=qSm(sg[p].ch[0],l,mid,qL,qR,fl);
	if(qR>mid) res+=qSm(sg[p].ch[1],mid+1,r,qL,qR,fl);return res;
}
ll qry(int x,int y,int l,int r)
{
	int t;ll res=0;
	if(!y)
	{
		for(int i=l;i<=r;++i)
			res+=min(vl[i][0],a[i]+1ll*x*vl[i][1]);
		return res;
	}t=min(x,lim);res=qSm(rt[r],0,lim+1,t+1,lim+1,1);
	res-=qSm(rt[l-1],0,lim+1,t+1,lim+1,1);res*=x;
	res+=qSm(rt[r],0,lim+1,0,t,0)-qSm(rt[l-1],0,lim+1,0,t,0);
	return res;
}
int main()
{
	scanf("%d",&n);z.insert((Node) {0,0});	
	for(int i=1,t;i<=n;++i)
	{
		scanf("%d %d %d",&a[i],&vl[i][0],&vl[i][1]);
		z.insert((Node) {i,0});
		t=vl[i][1]?(vl[i][0]-1)/vl[i][1]+1:lim+1;
		upd(rt[i-1],rt[i],0,lim+1,t,vl[i][0],0);
		upd(rt[i],rt[i],0,lim+1,t,vl[i][1],1);
	}scanf("%d",&m);
	for(int i=1,w,l,r,lst;i<=m;++i)
	{
		ll res=0;scanf("%d %d %d",&w,&l,&r);lst=l-1;
		it=z.lower_bound((Node) {l-1,0});
		if(l<=it->x) z.insert((Node) {l-1,it->w});
		it=z.lower_bound((Node) {r,0});
		if(r<it->x) z.insert((Node) {r,it->w});
		while(1)
		{
			it=z.lower_bound((Node) {l,0});
			Node t=*it;res+=qry(w-t.w,t.w,lst+1,t.x);
			lst=t.x;z.erase(it);if(r<=t.x) break;
		}z.insert((Node) {r,w});printf("%lld\n",res);
	}return 0;
}