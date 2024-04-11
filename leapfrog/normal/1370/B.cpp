//Coded by leapfrog on 2021.10.29 {{{
//
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
const int N=2005;int n,a[N];
inline void solve()
{
	read(n);int cnt=n+n;for(int i=1;i<=n+n;i++) read(a[i]);
	vector<int>v[2];for(int i=1;i<=n+n;i++) v[a[i]&1].push_back(i);
	for(size_t i=1;i<v[0].size();i+=2) if((cnt-=2)>=2) printf("%d %d\n",v[0][i-1],v[0][i]);
	for(size_t i=1;i<v[1].size();i+=2) if((cnt-=2)>=2) printf("%d %d\n",v[1][i-1],v[1][i]);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}