//{{{
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
const int dx[6]={-1,1,0,0,0,0},dy[6]={0,0,-1,1,0,0},dz[6]={0,0,0,0,-1,1};
int n,m,k,a[2000005];vector<int>v[2000005];
inline int ID(int x,int y,int z) {return (x-1)*m*k+(y-1)*k+z;}
inline char in(int x,int y,int z) {return 1<=x&&x<=n&&1<=y&&y<=m&&1<=z&&z<=k;}
inline void fail(int c) {if(c) puts("-1"),exit(0);}
inline void ers(int x,int y,int z);
inline void ins(int x,int y,int z,int wy,int cl)
{
	int id=ID(x,y,z);if(!in(x,y,z)) return fail(cl);
	if(!cl) return (a[id]>0?ers(x,y,z),0:0),a[id]=-1,ins(x+dx[wy],y+dy[wy],z+dz[wy],wy,cl);
	else if(!a[id]||a[id]==cl) a[id]=cl,v[id].push_back(wy);
	else if(!~a[id]) ins(x+dx[wy],y+dy[wy],z+dz[wy],wy,cl);
	else ers(x,y,z),a[id]=-1,ins(x+dx[wy],y+dy[wy],z+dz[wy],wy,cl);
}
inline void ers(int x,int y,int z)
{
	int id=ID(x,y,z);while(!v[id].empty())
		{int w=*--v[id].end();v[id].pop_back(),ins(x+dx[w],y+dy[w],z+dz[w],w,a[id]);}
}
int main()
{
	read(n,m,k);
	for(int i=1;i<=m;i++) for(int j=1,x;j<=k;j++) read(x),ins(1,i,j,1,x);
	for(int i=1;i<=m;i++) for(int j=1,x;j<=k;j++) read(x),ins(n,i,j,0,x);
	for(int i=1;i<=n;i++) for(int j=1,x;j<=k;j++) read(x),ins(i,1,j,3,x);
	for(int i=1;i<=n;i++) for(int j=1,x;j<=k;j++) read(x),ins(i,m,j,2,x);
	for(int i=1;i<=n;i++) for(int j=1,x;j<=m;j++) read(x),ins(i,j,1,5,x);
	for(int i=1;i<=n;i++) for(int j=1,x;j<=m;j++) read(x),ins(i,j,k,4,x);
	for(int i=1;i<=n;i++,putchar('\n')) for(int j=1;j<=m;j++,putchar('\n'))
		for(int l=1;l<=k;l++) printf("%d ",~a[ID(i,j,l)]?a[ID(i,j,l)]:0);
	return 0;
}