//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,Q,a[200005],lz[800005][105];
inline void down(int x)
{
	for(int i=1;i<=100;i++) lz[x<<1][i]=lz[x][lz[x<<1][i]],lz[x<<1|1][i]=lz[x][lz[x<<1|1][i]];
	for(int i=1;i<=100;i++) lz[x][i]=i;
}
inline void chang(int x,int l,int r,int dl,int dr,int dx,int dy)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) for(int i=1;i<=100;i++) {if(lz[x][i]==dx) lz[x][i]=dy;}
	else down(x),chang(x<<1,l,(l+r)>>1,dl,dr,dx,dy),chang(x<<1|1,((l+r)>>1)+1,r,dl,dr,dx,dy);
}
inline void paint(int x,int l,int r)
{
	if(l==r) return(void)(printf("%d ",lz[x][a[l]]));else down(x);
	paint(x<<1,l,(l+r)>>1),paint(x<<1|1,((l+r)>>1)+1,r);
}
int main()
{
	read(n);for(int i=1;i<=(n<<2);i++) for(int j=1;j<=100;j++) lz[i][j]=j;
	for(int i=1;i<=n;i++) read(a[i]);read(Q);
	for(int l,r,x,y;Q--;) read(l),read(r),read(x),read(y),chang(1,1,n,l,r,x,y);
	return paint(1,1,n),putchar('\n'),0;
}