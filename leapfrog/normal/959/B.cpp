//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
int n,m,K,fa[100005],ds[100005];map<string,int>mp;
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline void mrg(int x,int y) {x=getf(x),y=getf(y);if(x^y) ds[x]=min(ds[x],ds[y]),fa[y]=x;}
int main()
{
	read(n),read(K),read(m);string s;ll tt=0;
	for(int i=1;i<=n;i++) cin>>s,mp[s]=i,fa[i]=i;
	for(int i=1,x;i<=n;i++) read(x),ds[i]=x;
	for(int i=1,v,a1,x;i<=K;i++)
	{
		read(v),read(a1),v--;
		while(v--) read(x),mrg(a1,x);
	}
	for(int i=1;i<=m;i++) cin>>s,tt+=ds[getf(mp[s])];
	return printf("%lld\n",tt),0;
}