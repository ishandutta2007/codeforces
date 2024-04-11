//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
struct pnt
{
	int x,y,id;
	char operator<(pnt b) const {return x^b.x?x<b.x:y>b.y;}
	char operator==(pnt b) const {return x==b.x&&y==b.y&&id==b.id;}
}a[200005],st[200005];
int n,m,tp,zkakioi,xxysb;
inline char chk(pnt a,pnt b,pnt c) {return 1ll*(a.x-b.x)*(b.y-c.y)<1ll*(b.x-c.x)*(a.y-b.y);}
int main()
{
	read(n),read(m),read(zkakioi),read(xxysb);
	for(int i=1;i<=n;i++) read(a[i].x),read(a[i].y),a[i].id=1;
	for(int i=1;i<=m;i++) read(a[i+n].x),read(a[i+n].y);
	sort(a+1,a+n+m+1);int cnt=unique(a+1,a+n+m+1)-a-1;
	for(int i=1;i<=cnt;i++)
	{
		while(tp&&st[tp].y<a[i].y) tp--;
		while(tp>1&&chk(st[tp],st[tp-1],a[i])) tp--;
		st[++tp]=a[i];
	}
	for(int i=1;i<=tp;i++) if(st[i].id) return puts("Max"),0;
	return puts("Min"),0;
}