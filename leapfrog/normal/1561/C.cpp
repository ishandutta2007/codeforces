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
const int N=100005;int n,K;pair<int,int>p[N];//queueforces
inline void solve()
{
	read(n);for(int i=1;i<=n;i++)
	{
		read(K);int mx=0;for(int i=1,x;i<=K;i++) read(x),mx=max(mx,x-i+2);
		p[i]=make_pair(mx,K);
	}
	sort(p+1,p+n+1);int rs=0,sm=0;
	for(int i=1;i<=n;i++) rs=max(rs,p[i].first-sm),sm+=p[i].second;
	printf("%d\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}