//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int n,a[200005];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1,greater<int>());ll v[2]={0,0};
	for(int i=1;i<=n;i++) if((i&1)^(a[i]&1)) v[i&1]+=a[i];
	if(v[0]==v[1]) puts("Tie");else if(v[0]<v[1]) puts("Alice");else puts("Bob");
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}