//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n;string s;
inline void solve()
{
	read(n),cin>>s;string res="1";
	for(int i=1;i<n;i++) if(s[i]+'1'!=res[i-1]+s[i-1]) res+="1";else res+="0";
	cout<<res<<endl;
}
int main() {for(read(T);T--;) solve();return 0;}