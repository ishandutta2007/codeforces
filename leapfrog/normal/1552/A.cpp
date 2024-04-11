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
int n,m,K,a[2000005],b[2000005];char ch[100005],t[100005];
inline void solve()
{
	read(n),scanf("%s",ch+1);
	for(int i=1;i<=n;i++) t[i]=ch[i];
	sort(t+1,t+n+1);int cnt=0;
	for(int i=1;i<=n;i++) if(t[i]!=ch[i]) cnt++;
	printf("%d\n",cnt);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}