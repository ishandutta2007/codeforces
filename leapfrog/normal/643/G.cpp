//
#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
typedef vector<pair<int,int> > vpi;vpi ept;const int N=150005;
struct node{vpi v;int ln,tg;}T[N<<2];int n,m,p,a[N];
inline vpi operator+(vpi a,vpi b)
{
	for(int i=0;i<(int)a.size();i++)
	{
		int fg=0;for(int j=0;j<(int)b.size()&&!fg;j++) if(a[i].fr==b[j].fr) b[j].sc+=a[i].sc,fg=1;
		if(fg) continue;else {b.push_back(a[i]);if((int)b.size()<=p) continue;}
		int mn=1e9;for(int j=0;j<(int)b.size();j++) mn=min(mn,b[j].sc);
		for(int j=0;j<(int)b.size();j++) if(!(b[j].sc-mn)) b.erase(b.begin()+j),j--;else b[j].sc-=mn;
	}
	return b;
}
inline void allc(int x,int c) {T[x].v.clear(),T[x].v.push_back(make_pair(c,T[x].ln)),T[x].tg=c;}
inline void pushdw(int x) {if(T[x].tg) allc(x<<1,T[x].tg),allc(x<<1|1,T[x].tg),T[x].tg=0;}
inline void pushup(int x) {T[x].v=T[x<<1].v+T[x<<1|1].v,T[x].ln=T[x<<1].ln+T[x<<1|1].ln;}
inline void build(int x,int l,int r)
{
	T[x].ln=r-l+1;if(l==r) return T[x].v.push_back(make_pair(a[l],T[x].ln)),void();
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),pushup(x);
}
inline void modif(int x,int l,int r,int dl,int dr,int dc)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allc(x,dc);else pushdw(x);
	modif(x<<1,l,(l+r)>>1,dl,dr,dc),modif(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc),pushup(x);
}
inline vpi query(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return ept;else if(dl<=l&&r<=dr) return T[x].v;else pushdw(x);
	return query(x<<1,l,(l+r)>>1,dl,dr)+query(x<<1|1,((l+r)>>1)+1,r,dl,dr);
}
int main()
{
	read(n),read(m),read(p),p=100/p;for(int i=1;i<=n;i++) read(a[i]);
	build(1,1,n);for(int op,l,r,x;m--;)
	{
		read(op),read(l),read(r);if(op&1) {read(x),modif(1,1,n,l,r,x);continue;}
		vpi v=query(1,1,n,l,r);printf("%d",(int)v.size());
		for(int i=0;i<(int)v.size()||!putchar('\n');i++) printf(" %d",v[i].fr);
	}
	return 0;
}