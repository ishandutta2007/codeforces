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
int T,n,m;string s1,s2,s,c;
inline void solve()
{
	cin>>s1>>s2,n=s1.size(),m=s2.size(),s="",c="";
	for(int i=1;i<=n/__gcd(n,m);i++) s=s+s2;
	for(int i=1;i<=m/__gcd(n,m);i++) c=c+s1;
	if(s==c) cout<<s<<endl;else puts("-1");
}
int main() {for(read(T);T--;) solve();return 0;}