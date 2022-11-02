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
int n;char ch[1005];
inline void solve()
{
	read(n),scanf("%s",ch+1);int cnt=0,fg=0;
	for(int i=1;i<=n;i++) cnt+=ch[i]=='0',fg|=ch[i]!=ch[n-i+1];
	if(!fg) puts(cnt?(cnt^1&&cnt&1?"ALICE":"BOB"):"DRAW");
	else puts(cnt==2&&n&1&&ch[(n+1)>>1]=='0'?"DRAW":"ALICE");
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}