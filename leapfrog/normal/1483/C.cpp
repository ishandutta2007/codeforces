//
#include<bits/stdc++.h>
#define int long long
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int n,a[300005],b[300005],ls[300005];
ll T[1200005],fg[1200005],qw[300005],dp[300005];
inline void pushup(int x) {T[x]=max(T[x<<1],T[x<<1|1]);}
inline void allc(int x,int c) {T[x]+=c,fg[x]+=c;}
inline void pushdw(int x) {if(fg[x]) allc(x<<1,fg[x]),allc(x<<1|1,fg[x]),fg[x]=0;}
inline void modif(int x,int l,int r,int dl,int dr,ll dc)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allc(x,dc);else pushdw(x);
	modif(x<<1,l,(l+r)>>1,dl,dr,dc),modif(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc),pushup(x);
}
inline ll query(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return -1e18;else if(dl<=l&&r<=dr) return T[x];else pushdw(x);
	return max(query(x<<1,l,(l+r)>>1,dl,dr),query(x<<1|1,((l+r)>>1)+1,r,dl,dr));
}
signed main()
{
	read(n);for(int i=0;i<n;i++) read(a[i]);
	for(int i=0;i<n;i++) read(b[i]);
	stack<pair<int,int> >s;s.push(make_pair(-1,-1));
	for(int i=0;i<n;i++)
	{
		while(s.top().first>a[i]) s.pop();
		ls[i]=s.top().second,s.push(make_pair(a[i],i));
	}
	memset(T,0,sizeof(T));
	for(int i=0;i<n;i++)
	{
		qw[i]=query(1,-1,n,ls[i],i-1)+b[i];
		if(~ls[i]) qw[i]=max(qw[i],qw[ls[i]]);
		dp[i]=qw[i],modif(1,-1,n,i,i,dp[i]);
	}
	return printf("%lld\n",dp[n-1]),0;
}