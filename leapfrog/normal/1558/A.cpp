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
inline void solve()
{
	int n,m;read(n),read(m);if(n>m) swap(n,m);
	map<int,int>mp;for(int i=(m-n+1)/2;i<=n*2+(m-n+1)/2;i+=2) mp[i]=1,mp[n+m-i]=1;
	printf("%d\n",(int)mp.size());for(auto x:mp) printf("%d ",x.first);
	putchar('\n');
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}