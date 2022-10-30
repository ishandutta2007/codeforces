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
int T,n,Q,v[200005];struct seg{int mn,mx,sm;}t[800005];
inline seg operator+(seg a,seg b)
{
	seg r;r.sm=a.sm+b.sm;
	r.mn=min(a.mn,a.sm+b.mn),r.mx=max(a.mx,a.sm+b.mx);
	return r;
}
inline char gc() {char c=getchar();while(c^'+'&&c^'-') c=getchar();return c;}
inline void build(int x,int l,int r)
{
	if(l==r) return t[x]=(seg){min(v[l],0),max(v[l],0),v[l]},void();
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),t[x]=t[x<<1]+t[x<<1|1];
}
inline seg query(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return(seg){0,0,0};else if(dl<=l&&r<=dr) return t[x];
	return query(x<<1,l,(l+r)>>1,dl,dr)+query(x<<1|1,((l+r)>>1)+1,r,dl,dr);
}
inline void solve()
{
	read(n),read(Q);for(int i=1;i<=n;i++) if(gc()=='+') v[i]=1;else v[i]=-1;
	build(1,1,n);for(int l,r;Q--;)
	{
		read(l),read(r);seg x=query(1,1,n,1,l-1)+query(1,1,n,r+1,n);
		printf("%d\n",x.mx-x.mn+1);
	}
}
int main() {for(read(T);T--;) solve();return 0;}