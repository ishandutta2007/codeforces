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
int Ca,n,tn[26];char ch[1000005];
inline void solve()
{
	read(n),scanf("%s",ch+1),memset(tn,0,sizeof(tn)),tn[ch[1]-'A']=1;
	for(int i=2;i<=n;i++) if(tn[ch[i]-'A']&&ch[i-1]!=ch[i]) return puts("NO"),void();else tn[ch[i]-'A']=1;
	puts("YES");
}
int main() {for(read(Ca);Ca--;) solve();return 0;}