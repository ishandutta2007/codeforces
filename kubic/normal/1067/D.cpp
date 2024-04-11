#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
#define db long double
const db EPS=1e-15;
int n,a[N],b[N],h[N];ll t,m;db w,nw,tmp,p[N],pw[N],s[N];
struct Point
{
	int id;db x,y;Point(db _x=0,db _y=0) {id=0;x=_x;y=_y;}
	Point operator - (Point t) {return Point(x-t.x,y-t.y);}
}z[N];
bool cmp(Point x,Point y) {return fabs(x.x-y.x)<EPS?x.y>y.y:x.x<y.x;}
db crsMul(Point x,Point y) {return x.x*y.y-x.y*y.x;}
bool chk(int x,db w)
{
	w=-w;if(x>1 && crsMul(z[h[x]]-z[h[x-1]],Point(1,w))>0) return 0;
	if(x<h[0] && crsMul(z[h[x+1]]-z[h[x]],Point(1,w))<0) return 0;return 1;
}
int main()
{
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%d %d %Lf",&a[i],&b[i],&p[i]);
		w=max(w,p[i]*b[i]);z[i]=Point(p[i],p[i]*a[i]);z[i].id=i;
	}sort(z+1,z+n+1,cmp);
	for(int i=1;i<=n;++i)
	{
		if(fabs(z[i].x-z[i-1].x)<EPS) continue;
		while(h[0]>1 && crsMul(z[i]-z[h[h[0]-1]],z[h[h[0]]]-z[h[h[0]-1]])<0)
			--h[0];h[++h[0]]=i;
	}
	for(int i=1,id;i<=h[0];++i) if(t<m && chk(i,nw))
	{
		id=z[h[i]].id;pw[0]=1-p[id];s[0]=1;
		for(int j=1;j<=40;++j) pw[j]=pw[j-1]*pw[j-1],s[j]=s[j-1]*(pw[j-1]+1);
		for(int j=40;j>=0;--j) if(t+(1ll<<j)<=m)
		{tmp=nw*pw[j]+s[j]*(w-p[id]*a[id]);if(chk(i,tmp)) t+=1ll<<j,nw=tmp;}
		if(t<m) ++t,nw=nw*pw[0]+s[0]*(w-p[id]*a[id]);
	}printf("%.10Lf\n",w*m-nw);return 0;
}