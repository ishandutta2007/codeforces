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
//#define debug
int n,Q,T[300005],ut,dx[300005],dy[300005],tn[300005],rs[100005];
vector<pair<int,int> >q[100005];vector<int>vc[100005],nx[100005];
struct fac
{
	int a,b;
	inline void init(int x,int y) {int g=__gcd(abs(x),abs(y));a=x/g,b=y/g;}
	inline char operator<(fac x) const {return a^x.a?a<x.a:b<x.b;}
};map<fac,int>mp;
inline void add(int x,int w) {for(;x<=n;x+=x&(-x)) T[x]+=w;}
inline int qry(int x) {int r=0;for(;x;x-=x&(-x)) r+=T[x];return r;}
int main()
{
	read(n);for(int i=1,k;i<=n;i++)
	{
		read(k);for(int j=1;j<=k;j++) read(dx[j]),read(dy[j]);
		for(int p=1;p<=k;p++)
		{
			int q=p%k+1;fac c;
#ifdef debug
	//		printf("%d %d\n",dx[p]-dx[q],dy[p]-dy[q]);
#endif
			c.init(dx[p]-dx[q],dy[p]-dy[q]);
			vc[i].push_back(mp[c]?mp[c]:(mp[c]=++ut));
		}
	}
	for(int i=1;i<=ut;i++) tn[i]=n+1;
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<(int)vc[i].size();j++) nx[i].push_back(tn[vc[i][j]]);
		for(int j=0;j<(int)vc[i].size();j++) tn[vc[i][j]]=i;
	}
#ifdef debug
	//for(int i=1;i<=n;i++,putchar('\n')) for(auto x:vc[i]) printf("%d ",x);
	for(int i=1;i<=n;i++,putchar('\n')) for(auto x:nx[i]) printf("%d ",x);
#endif
	read(Q);for(int i=1,l,r;i<=Q;i++) read(l),read(r),q[l].push_back(make_pair(r,i));
	for(int i=n;i>=1;i--)
	{
		for(auto x:nx[i]) add(x,-1),add(i,1);
		for(auto x:q[i]) rs[x.second]=qry(x.first);
#ifdef debug
		for(int i=1;i<=n;i++) printf("%d%c",qry(i)-qry(i-1),i==n?'\n':' ');
#endif
	}
	for(int i=1;i<=Q;i++) printf("%d\n",rs[i]);
	return 0;
}