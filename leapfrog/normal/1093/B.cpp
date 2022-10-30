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
int T;string s;
inline void solve()
{
	cin>>s,sort(s.begin(),s.end());
	string t=s;reverse(t.begin(),t.end());
	if(t==s) puts("-1");else cout<<s<<endl;
}
int main() {for(read(T);T--;) solve();return 0;}