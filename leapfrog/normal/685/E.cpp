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
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=1005,M=200005;int n,m,q,fr[M],tw[M],ds[N][N];
struct ${int id,r,s,t;};vector<$>v[M];int rs[M];
int main()
{
	read(n,m,q);for(int i=1;i<=m;i++) read(fr[i],tw[i]);
	for(int i=1,l,r,s,t;i<=q;i++) read(l,r,s,t),v[l].push_back(($){i,r,s,t});
	memset(ds,0x3f,sizeof(ds));for(int i=m;i>=1;i--)
	{
		ds[fr[i]][tw[i]]=ds[tw[i]][fr[i]]=i;
		for(int j=1;j<=n;j++)
			ds[fr[i]][j]=min(ds[tw[i]][j],ds[fr[i]][j]),
			ds[tw[i]][j]=min(ds[fr[i]][j],ds[tw[i]][j]);
		for(auto x:v[i]) rs[x.id]=(ds[x.s][x.t]<=x.r);
	}
	for(int i=1;i<=q;i++) puts(rs[i]?"Yes":"No");
	return 0;
}