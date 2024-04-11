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
int n,a,b;char ch[2000005];ll N,M;
inline void solve()
{
	read(n),read(a),read(b),scanf("%s",ch+1);
	if(b>=0) return printf("%d\n",a*n+b*n),void();
	int cnt=0;for(int i=2;i<=n;i++) if(ch[i]!=ch[i-1]) cnt++;
	cnt++,cnt>>=1,cnt++;
	return printf("%d\n",a*n+b*cnt),void();
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}