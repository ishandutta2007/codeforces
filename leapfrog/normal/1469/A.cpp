//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int Ca,n;char ch[100005];
inline void solve()
{
	scanf("%s",ch+1),n=strlen(ch+1);if(n&1) return puts("NO"),void();
	if(ch[1]==')'||ch[n]=='(') return puts("NO"),void();else puts("YES");
}
int main() {for(read(Ca);Ca--;) solve();return 0;}