#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define mid ((l+r)/2)
#define pb push_back
int n,ans,dsX[N],dsY[N];bool vs[N];struct Rect {int x1,y1,x2,y2;}a[N];
struct Node {int l,r,w;};vector<Node> vc1[N],vc2[N];
struct Seg {int mn,mx,vl,ps;set<int> z;}sg[N*4];
void build(int p,int l,int r)
{sg[p].z.insert(0);if(l==r) return;build(p*2,l,mid);build(p*2+1,mid+1,r);}
void pu(int p,int l,int r)
{
	sg[p].mn=max((l<r?min(sg[p*2].mn,sg[p*2+1].mn):0),sg[p].mx);
	sg[p].ps=max((l<r?max(sg[p*2].ps,sg[p*2+1].ps):0),sg[p].vl);
	if(sg[p].ps<sg[p].mn) sg[p].ps=0;
}
void mdf1(int p,int w,int mx)
{
	if(w>=max(mx,sg[p].mn)) vs[w]=1;else sg[p].vl=max(sg[p].vl,w);
	sg[p].mx=max(sg[p].mx,w);sg[p].z.insert(w);
}
void mdf2(int p,int w,int mx)
{
	while(sg[p].vl==w || vs[sg[p].vl]) sg[p].vl=*--sg[p].z.find(sg[p].vl);
	sg[p].z.erase(w);sg[p].mx=*--sg[p].z.end();
}
void mdf(int p,int mx)
{
	while(sg[p].vl && sg[p].vl>=max(mx,sg[p].mn))
	{vs[sg[p].vl]=1;while(vs[sg[p].vl]) sg[p].vl=*--sg[p].z.find(sg[p].vl);}
}
void upd1(int p,int l,int r,int qL,int qR,int w,int mx)
{
	mx=max(mx,sg[p].mx);
	if(l>=qL && r<=qR) {mdf1(p,w,mx);pu(p,l,r);return;}
	if(qL<=mid) upd1(p*2,l,mid,qL,qR,w,mx);
	if(qR>mid) upd1(p*2+1,mid+1,r,qL,qR,w,mx);pu(p,l,r); 
}
void upd2(int p,int l,int r,int qL,int qR,int w,int mx)
{
	mx=max(mx,sg[p].mx);
	if(l>=qL && r<=qR) {mdf2(p,w,mx);pu(p,l,r);return;}
	if(qL<=mid) upd2(p*2,l,mid,qL,qR,w,mx);
	if(qR>mid) upd2(p*2+1,mid+1,r,qL,qR,w,mx);pu(p,l,r);
}
void upd(int p,int l,int r,int mx)
{
	mx=max(mx,sg[p].mx);if(!sg[p].ps || sg[p].ps<mx) return;
	mdf(p,mx);if(l==r) {pu(p,l,r);return;}
	upd(p*2,l,mid,mx);upd(p*2+1,mid+1,r,mx);pu(p,l,r);
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x1,y1,x2,y2;i<=n;++i)
	{
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);a[i]=(Rect) {x1+1,y1+1,x2,y2};
		dsX[++dsX[0]]=x1;dsX[++dsX[0]]=x2;dsY[++dsY[0]]=y1;dsY[++dsY[0]]=y2;
	}sort(dsX+1,dsX+dsX[0]+1);dsX[0]=unique(dsX+1,dsX+dsX[0]+1)-dsX-1;
	sort(dsY+1,dsY+dsY[0]+1);dsY[0]=unique(dsY+1,dsY+dsY[0]+1)-dsY-1;
	for(int i=n;i;--i)
	{
		a[i].x1=lower_bound(dsX+1,dsX+dsX[0]+1,a[i].x1)-dsX;
		a[i].x2=lower_bound(dsX+1,dsX+dsX[0]+1,a[i].x2)-dsX;
		a[i].y1=lower_bound(dsY+1,dsY+dsY[0]+1,a[i].y1)-dsY;
		a[i].y2=lower_bound(dsY+1,dsY+dsY[0]+1,a[i].y2)-dsY;
		vc1[a[i].x1].pb((Node) {a[i].y1,a[i].y2,i});
		vc2[a[i].x2].pb((Node) {a[i].y1,a[i].y2,i});
	}build(1,1,dsY[0]);
	for(int i=1;i<=dsX[0];++i)
	{
		for(auto j:vc1[i]) upd1(1,1,dsY[0],j.l,j.r,j.w,0);upd(1,1,dsY[0],0);
		for(auto j:vc2[i]) upd2(1,1,dsY[0],j.l,j.r,j.w,0);
	}for(int i=1;i<=n;++i) if(vs[i]) ++ans;printf("%d\n",ans+1);return 0;
}