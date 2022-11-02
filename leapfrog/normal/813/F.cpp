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
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
int n,q,fa[800005],ds[800005],tp;pair<int,int>st[800005];vector<pair<int,int> >v[800005];
inline int getf(int x) {return fa[x]==x?x:getf(fa[x]);}
inline void mrg(int a,int b)
{
	a=getf(a),b=getf(b);if(a==b) return;else if(ds[a]<ds[b]) swap(a,b);
	st[++tp]=make_pair(b,ds[b]),ds[a]+=ds[a]==ds[b],fa[b]=a;
}
inline void goback() {fa[st[tp].first]=st[tp].first,ds[st[tp].first]=st[tp].second,tp--;}
inline void update(int x,int l,int r,int dl,int dr,int dc1,int dc2)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return v[x].push_back(make_pair(dc1,dc2)),void();
	update(x<<1,l,(l+r)>>1,dl,dr,dc1,dc2),update(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc1,dc2);
}
inline void solve(int x,int l,int r)
{
	int tag=1,nwtp=tp;
	for(int i=0;i<(int)v[x].size()&&tag;i++)
	{
		int U=getf(v[x][i].first),V=getf(v[x][i].second);
		if(U==V) tag=0;else mrg(v[x][i].first+n,V),mrg(U,v[x][i].second+n);
	}
	if(!tag) for(int i=l;i<=r;i++) puts("NO");
	else if(l==r) puts("YES");else solve(x<<1,l,(l+r)>>1),solve(x<<1|1,((l+r)>>1)+1,r);
	while(tp>nwtp) goback();
}
map<pair<int,int>,int>mp;
int main()
{
	read(n),read(q);for(int i=1;i<=n+n;i++) ds[i]=1,fa[i]=i;
	for(int i=1,x,y;i<=q;i++)
	{
		read(x,y);pair<int,int>pi=make_pair(min(x,y),max(x,y));
		if(!mp.count(pi)) mp[pi]=i;
		else update(1,1,q,mp[pi],i-1,x,y),mp.erase(pi);
	}
	for(auto x:mp) if(x.second) update(1,1,q,x.second,q,x.first.first,x.first.second);
	return solve(1,1,q),0;
}