//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
const int N=120005;struct node{int mn,cn,lz,ti;ll rs;}T[N<<2];int n,q,a[N];
ll rs[N];int s1[N],s2[N],t1,t2;vector<pair<int,int> >v[N];
inline void all1(int x,int w) {T[x].mn+=w,T[x].lz+=w;}
inline void all2(int x,int w) {T[x].rs+=1ll*T[x].cn*w,T[x].ti+=w;}
inline void push1(int x) {if(T[x].lz) all1(x<<1,T[x].lz),all1(x<<1|1,T[x].lz),T[x].lz=0;}
inline void push2(int x)
{
	if(!T[x].ti) return;
	if(T[x<<1].mn==T[x].mn) all2(x<<1,T[x].ti);
	if(T[x<<1|1].mn==T[x].mn) all2(x<<1|1,T[x].ti);
	T[x].ti=0;
}
inline void pushdw(int x) {push1(x),push2(x);}
inline node operator+(node a,node b)
{
	node rs;rs.mn=min(a.mn,b.mn),rs.rs=a.rs+b.rs,rs.lz=rs.ti=0;
	return rs.cn=(rs.mn==a.mn)*a.cn+(rs.mn==b.mn)*b.cn,rs;
}
inline void build(int x,int l,int r) {T[x].mn=l,T[x].cn=1;if(l^r) build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r);}
inline void modif(int x,int l,int r,int dl,int dr,int dc)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return all1(x,dc);else pushdw(x);
	modif(x<<1,l,(l+r)>>1,dl,dr,dc),modif(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc),T[x]=T[x<<1]+T[x<<1|1];
}
inline ll query(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return 0;else if(dl<=l&&r<=dr) return T[x].rs;else pushdw(x);
	return query(x<<1,l,(l+r)>>1,dl,dr)+query(x<<1|1,((l+r)>>1)+1,r,dl,dr);
}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	read(q);for(int i=1,l,r;i<=q;i++) read(l),read(r),v[r].push_back(make_pair(l,i));
	build(1,1,n),all1(1,-1);for(int i=1;i<=n;s1[++t1]=i,s2[++t2]=i++,all1(1,-1))
	{
		for(;t1&&a[i]>a[s1[t1]];t1--) modif(1,1,n,s1[t1-1]+1,s1[t1],a[i]-a[s1[t1]]);
		for(;t2&&a[i]<a[s2[t2]];t2--) modif(1,1,n,s2[t2-1]+1,s2[t2],a[s2[t2]]-a[i]);
		all2(1,1);for(int j=0;j<(int)v[i].size();j++) rs[v[i][j].second]=query(1,1,n,v[i][j].first,i);
	}
	for(int i=1;i<=q;i++) printf("%lld\n",rs[i]);
	return 0;
}