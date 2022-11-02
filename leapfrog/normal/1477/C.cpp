#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct pnt{ll x,y;}a[5005];int n;char vs[5005];
inline ll ds(pnt a,pnt b) {return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i].x),read(a[i].y);
	vs[1]=1,printf("%d ",1);for(int i=2,nw=1;i<=n;i++)
	{
		ll mn=0;int wh;for(int j=1;j<=n;j++) if(!vs[j]&&mn<ds(a[nw],a[j])) mn=ds(a[nw],a[j]),wh=j;
		printf("%d%c",wh,i==n?'\n':' '),nw=wh,vs[wh]=1;
	}
	return 0;
}