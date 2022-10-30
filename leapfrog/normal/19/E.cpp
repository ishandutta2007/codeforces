//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
int n,m,fa[20005],ds[20005],tp,rs[10005],ct;pair<int,int>st[20005];vector<pair<int,int> >v[40005];
inline int getf(int x) {return fa[x]==x?x:getf(fa[x]);}
inline void mrg(int a,int b)
{
	a=getf(a),b=getf(b);if(a==b) return;else if(ds[a]<ds[b]) swap(a,b);
	st[++tp]=make_pair(b,ds[b]),ds[a]+=ds[a]==ds[b],fa[b]=a;
}
inline void goback() {fa[st[tp].first]=st[tp].first,ds[st[tp].first]=st[tp].second,tp--;}
inline void update(int x,int l,int r,int dl,int dr,int dc1,int dc2)
{
	if(l>dr||dl>r||dl>dr) return;else if(dl<=l&&r<=dr) return(void)(v[x].push_back(make_pair(dc1,dc2)));
	update(x<<1,l,(l+r)>>1,dl,dr,dc1,dc2),update(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc1,dc2);
}
inline void solve(int x,int l,int r)
{
	int tag=1,nwtp=tp;if(l>r) return;
	for(int i=0;i<(int)v[x].size()&&tag;i++)
	{
		int U=getf(v[x][i].first),V=getf(v[x][i].second);
		if(U==V) tag=0;else mrg(v[x][i].first+n,V),mrg(U,v[x][i].second+n);
	}
	if(tag&&l==r) rs[++ct]=l;else if(tag) solve(x<<1,l,(l+r)>>1),solve(x<<1|1,((l+r)>>1)+1,r);
	while(tp>nwtp) goback();
}
int main()
{
	read(n),read(m);for(int i=1;i<=n+n;i++) ds[i]=1,fa[i]=i;
	for(int i=1,x,y;i<=m;i++) read(x),read(y),update(1,1,m,1,i-1,x,y),update(1,1,m,i+1,m,x,y);
	solve(1,1,m),printf("%d\n",ct);for(int i=1;i<=ct;i++) printf("%d%c",rs[i],i==ct?'\n':' ');
	return 0;
}