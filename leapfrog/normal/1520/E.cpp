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
int Ca,n,tot,wh[1000005];char ch[1000005];
inline void solve()
{
	read(n),scanf("%s",ch+1),tot=0;ll res=0;
	for(int i=1;i<=n;i++) if(ch[i]=='*') wh[++tot]=i;
	int qw=(tot+1)>>1;if(tot==0) return puts("0"),void();
	for(int i=1;i<qw;i++) res+=wh[qw]-wh[i]-qw+i;
	for(int i=qw+1;i<=tot;i++) res+=wh[i]-wh[qw]-i+qw;
	printf("%lld\n",res);
}
int main() {for(read(Ca);Ca--;) solve();return 0;}