//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
const int INF=1e9,N=200005;int n,a[N],id[N],rs[N];
struct segm{int mx,mn,tg;}T[N<<2];vector<int>v[N];
inline segm operator+(segm a,segm b) {return(segm){max(a.mx,b.mx),min(a.mn,b.mn),0};}
inline void allc(int x,int c) {T[x].mx+=c,T[x].mn+=c,T[x].tg+=c;}
inline void pushdw(int x) {if(T[x].tg) allc(x<<1,T[x].tg),allc(x<<1|1,T[x].tg),T[x].tg=0;}
inline void build(int x,int l,int r)
{
	if(l==r) return T[x].mx=T[x].mn=l,void();//all is 1
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),T[x]=T[x<<1]+T[x<<1|1];
}
inline void modif(int x,int l,int r,int dl,int dr,int dc)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allc(x,dc);else pushdw(x);
	modif(x<<1,l,(l+r)>>1,dl,dr,dc),modif(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc),T[x]=T[x<<1]+T[x<<1|1];
}
inline segm query(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return(segm){-INF,INF,0};else if(dl<=l&&r<=dr) return T[x];else pushdw(x);
	return query(x<<1,l,(l+r)>>1,dl,dr)+query(x<<1|1,((l+r)>>1)+1,r,dl,dr);
}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),v[a[i]].push_back(i),id[i]=i;
	sort(id+1,id+n+1,[&](int x,int y){return a[x]<a[y];});
	build(1,0,n);for(int i=1,x=id[1];i<=n;x=id[++i])
	{
		if(a[x]^a[id[i-1]]) for(auto y:v[a[id[i]]]) modif(1,0,n,y,n,-2);
		modif(1,0,n,x,n,2);int mx=query(1,0,n,0,x-1).mx,mn=query(1,0,n,x,n).mn;
		rs[x]=max(rs[x],(mx-mn+1)>>1),modif(1,0,n,x,n,-2);
	}
	build(1,0,n);for(int i=1,x=id[1];i<=n;x=id[++i])
	{
		if(a[x]^a[id[i-1]]) for(auto y:v[a[id[i-1]]]) modif(1,0,n,y,n,-2);
		modif(1,0,n,x,n,-2);int mn=query(1,0,n,0,x-1).mn,mx=query(1,0,n,x,n).mx;
		rs[x]=max(rs[x],(mx-mn+2)>>1),modif(1,0,n,x,n,2);
	}
	for(int i=1;i<=n;i++) printf("%d%c",rs[i],i==n?'\n':' ');
	return 0;
}