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
int Ca,n,K,fg[300005];char ch[300005];
inline void solve()
{
	read(n),read(K),scanf("%s",ch+1);for(int i=0;i<K;i++) fg[i]=-1;
	for(int i=1;i<=n;i++) if(ch[i]!='?')
	{
		if(!~fg[i%K]) {fg[i%K]=ch[i]^48;continue;}
		if(fg[i%K]^48^ch[i]) return puts("NO"),void();
	}
	int c0=0,c1=0;for(int i=0;i<K;i++) c0+=fg[i]==0,c1+=fg[i]==1;
	if(K-max(c0,c1)>=max(c0,c1)) puts("YES");else puts("NO");
}
int main() {for(read(Ca);Ca--;) solve();return 0;}