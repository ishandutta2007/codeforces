//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename t>inline void read(t &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,Q,a[500005],tn[500005],ut,ls[500005],rs[500005];
vector<pair<int,int> >v[500005];int T[2000005];
inline void modif(int x,int l,int r,int dw,int dc)
{
	if(l==r) return T[x]=min(T[x],dc),void();
	if(dw<=((l+r)>>1)) modif(x<<1,l,(l+r)>>1,dw,dc),T[x]=min(T[x<<1],T[x<<1|1]);
	else modif(x<<1|1,((l+r)>>1)+1,r,dw,dc),T[x]=min(T[x<<1],T[x<<1|1]);
}
inline int query(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return 1e9;else if(dl<=l&&r<=dr) return T[x];
	return min(query(x<<1,l,(l+r)>>1,dl,dr),query(x<<1|1,((l+r)>>1)+1,r,dl,dr));
}
int main()
{
	read(n),read(Q);for(int i=1;i<=n;i++) read(a[i]),tn[i]=a[i];
	for(int i=1,x,y;i<=Q;i++) read(x),read(y),v[y].push_back(make_pair(x,i));
	sort(tn+1,tn+n+1),ut=unique(tn+1,tn+n+1)-tn-1,memset(T,0x3f,sizeof(T));
	for(int i=1;i<=n;i++) a[i]=lower_bound(tn+1,tn+ut+1,a[i])-tn;
	memset(tn,0,sizeof(tn));for(int i=1;i<=n;tn[a[i]]=i,i++) ls[i]=tn[a[i]];
	for(int i=1;i<=n;i++)
	{
		if(ls[i]) modif(1,1,n,ls[i],i-ls[i]);
		for(int j=0;j<(int)v[i].size();j++) rs[v[i][j].second]=query(1,1,n,v[i][j].first,i);
	}
	for(int i=1;i<=Q;i++) printf("%d\n",rs[i]>=1e9?-1:rs[i]);
	return 0;
}