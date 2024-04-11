//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,fa[600005],sz1[600005],sz2[600005],ds[600005];
struct node{int x,y,s1,s2,ds;ll rs;}st[600005];int tp;ll res=0;
map<pair<int,int>,int>mp;vector<pair<int,int> >T[1200005];
inline int getf(int x) {return fa[x]==x?x:getf(fa[x]);}
inline void mrg(int x,int y)
{
	x=getf(x),y=getf(y);if(x==y) return;else if(ds[x]>ds[y]) swap(x,y);
	st[++tp]=(node){x,y,sz1[y],sz2[y],ds[y],res},res-=1ll*sz1[x]*sz2[x]+1ll*sz1[y]*sz2[y];
	ds[y]+=ds[x]==ds[y],fa[x]=y,sz1[y]+=sz1[x],sz2[y]+=sz2[x],res+=1ll*sz1[y]*sz2[y];
}
inline void pop() {int x=st[tp].x,y=st[tp].y;fa[x]=x,ds[y]=st[tp].ds,sz1[y]=st[tp].s1,sz2[y]=st[tp].s2,res=st[tp].rs,tp--;}
inline void back(int x) {while(tp>x) pop();}
inline void modif(int x,int l,int r,int dl,int dr,pair<int,int>dc)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return T[x].push_back(dc);
	modif(x<<1,l,(l+r)>>1,dl,dr,dc),modif(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc);
}
inline void solve(int x,int l,int r)
{
	int wh=tp;for(int i=0;i<(int)T[x].size();i++) {int a=T[x][i].first,b=T[x][i].second;mrg(a,b);}
	if(l==r) return printf("%lld ",res),back(wh);else solve(x<<1,l,(l+r)>>1),solve(x<<1|1,((l+r)>>1)+1,r);
	back(wh);
}
int main()
{
	read(n);for(int i=1,x,y;i<=n;i++)
	{
		read(x),read(y);pair<int,int>p=make_pair(x,y+300000);
		if(mp[p]) modif(1,1,n,mp[p],i-1,p),mp.erase(p);else mp[p]=i;
	}
	for(int i=1;i<=600000;i++) fa[i]=i,(i<=300000?sz1[i]:sz2[i])=1;
	for(auto i:mp) modif(1,1,n,i.second,n,i.first);
	return solve(1,1,n),putchar('\n'),0;
}