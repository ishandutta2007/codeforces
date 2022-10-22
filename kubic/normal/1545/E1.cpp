#include <bits/stdc++.h>
using namespace std;
#define N 5005
#define pb push_back
const int INF=1e9;
int n,m,tp,tp1,tp2,ans=INF,ds[N],vl[N];bool vs[N];vector<int> vc1[N],vc2[N];
struct Rect {int x1,y1,x2,y2;}a[N];struct Node {int x,w;}z[N],z1[N],z2[N];
bool cmp1(Rect x,Rect y) {return x.y1<y.y1;}
bool cmp2(Node x,Node y) {return x.x<y.x;}
int id(int x) {return lower_bound(ds+1,ds+ds[0]+1,x)-ds;}
void W1(int x)
{
	int lst=0,t=1,t1,t2,t3;tp1=0;
	for(int i=1;i<=n;++i) if(vs[i])
	{
		if(lst<=a[i].y1)
		{
			while(t<=tp && z[t].x<lst) ++t;
			while(t<=tp && z[t].x<=a[i].y1)
			{
				t1=z[t].x+x;t2=z[t].w;t3=a[i].y1;
				if(t1>t3) t2+=t1-t3,t1=t3;z1[++tp1]=(Node) {t1,t2};++t;
			}
		}lst=max(lst,a[i].y2);
	}while(t<=tp && z[t].x<lst) ++t;
	while(t<=tp) z1[++tp1]=(Node) {z[t].x+x,z[t].w},++t;swap(z,z1);tp=tp1;
}
void W(int l,int r)
{
	for(int i=l,mn=INF;i<=r;++i)
		mn=min(mn,z[i].w-z[i].x),z[i].w=min(z[i].w,mn+z[i].x);
	for(int i=r,mn=INF;i>=l;--i)
		mn=min(mn,z[i].w+z[i].x),z[i].w=min(z[i].w,mn-z[i].x);
}
void W2()
{
	int lst=0,t=1,tmp;tp2=0;sort(z1+1,z1+tp1+1,cmp2);
	for(int i=1;i<=tp;++i)
	{while(t<=tp1 && z[i].x>z1[t].x) z2[++tp2]=z1[t++];z2[++tp2]=z[i];}
	while(t<=tp1) z2[++tp2]=z1[t++];swap(z,z2);tp=tp2;t=1;
	for(int i=1;i<=n;++i) if(vs[i])
	{
		if(lst<=a[i].y1)
		{
			while(t<=tp && z[t].x<lst) ++t;tmp=t;
			while(t<=tp && z[t].x<=a[i].y1) ++t;W(tmp,t-1);
		}lst=max(lst,a[i].y2);
	}while(t<=tp && z[t].x<lst) ++t;W(t,tp);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1,x1,y1,x2,y2;i<=n;++i)
	{
		scanf("%d %d %d %d",&x1,&x2,&y1,&y2);--x1;++x2;--y1;++y2;
		a[i]=(Rect) {x1,y1,x2,y2};ds[++ds[0]]=x1;ds[++ds[0]]=x2;
	}sort(a+1,a+n+1,cmp1);
	sort(ds+1,ds+ds[0]+1);ds[0]=unique(ds+1,ds+ds[0]+1)-ds-1;
	for(int i=1;i<=n;++i) vc1[id(a[i].x1)].pb(i),vc2[id(a[i].x2)].pb(i);
	z[++tp]=(Node) {m+ds[1],0};
	for(int i=1;i<ds[0];++i)
	{
		for(auto j:vc2[i]) vs[j]=0;tp1=0;
		for(auto j:vc1[i])
			z1[++tp1]=(Node) {a[j].y1,INF},z1[++tp1]=(Node) {a[j].y2,INF};
		W2();for(auto j:vc1[i]) vs[j]=1;W1(ds[i+1]-ds[i]);
	}for(int i=1;i<=tp;++i) ans=min(ans,z[i].w);printf("%d\n",ans);return 0;
}