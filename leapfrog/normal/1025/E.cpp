//Coded by Kamiyama_Shiki on 2021.11.05 {{{
//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
struct pnt{int x,y,id;}a[55],b[55];int n,m,pos[55];
struct ${pnt a,b;}ra[10805],rb[10805];int ta,tb,v[55][55];
inline int sig(int x) {return x<0?-1:x>0?1:0;}
inline void move(pnt &a,pnt tw,pnt*list,int &cnt,$ *r)
{
	for(int nx,ny,nw;a.x!=tw.x||a.y!=tw.y;)
	{
		if(a.x!=tw.x)
		{
			nx=a.x+sig(tw.x-a.x),ny=a.y,nw=v[nx][ny];
			if(nw) move(list[nw],(pnt){nw,nw},list,cnt,r);
			if(!v[nx][ny]) swap(v[nx][ny],v[a.x][a.y]),r[++cnt].a=a,a.x+=sig(tw.x-a.x),r[cnt].b=a;
		}
		if(a.y!=tw.y)
		{
			nx=a.x,ny=a.y+sig(tw.y-a.y),nw=v[nx][ny];
			if(nw) move(list[nw],(pnt){nw,nw},list,cnt,r);
			if(!v[nx][ny]) swap(v[nx][ny],v[a.x][a.y]),r[++cnt].a=a,a.y+=sig(tw.y-a.y),r[cnt].b=a;
		}
	}
}
inline void move(pnt *a,int &cn,$ *r)
{
	sort(a+1,a+m+1,[&](pnt a,pnt b){return a.x<b.x||(a.x==b.x&&a.y<b.y);});
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) v[i][j]=0;
	for(int i=1;i<=m;i++) v[a[i].x][a[i].y]=i;
	for(int i=1;i<=m;i++) move(a[i],(pnt){i,i},a,cn,r);
	for(int i=1;i<=m;i++) pos[a[i].id]=i;
	for(int i=1;i<=m;i++) if(pos[i]!=i)
	{
		int j=pos[i],dx=j-i;r[++cn].a=a[i],a[i].x++,r[cn].b=a[i];
		for(int k=1;k<=dx;k++) r[++cn].a=a[j],a[j].x--,r[cn].b=a[j];
		for(int k=1;k<=dx;k++) r[++cn].a=a[j],a[j].y--,r[cn].b=a[j];
		for(int k=1;k<dx;k++) r[++cn].a=a[i],a[i].x++,r[cn].b=a[i];
		for(int k=1;k<=dx;k++) r[++cn].a=a[i],a[i].y++,r[cn].b=a[i];
		swap(pos[a[i].id],pos[a[j].id]),swap(a[i],a[j]);
	}
}
inline void flush()
{
	printf("%d\n",ta+tb);
	for(int i=1;i<=ta;i++) printf("%d %d %d %d\n",ra[i].a.x,ra[i].a.y,ra[i].b.x,ra[i].b.y);
	for(int i=tb;i>=1;i--) printf("%d %d %d %d\n",rb[i].b.x,rb[i].b.y,rb[i].a.x,rb[i].a.y);
}
int main()
{
	read(n,m);
	for(int i=1;i<=m;i++) read(a[i].x,a[i].y),a[i].id=i;
	for(int i=1;i<=m;i++) read(b[i].x,b[i].y),b[i].id=i;
	return move(a,ta,ra),move(b,tb,rb),flush(),0;
}