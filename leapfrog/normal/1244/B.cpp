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
int n;char ch[100005];
inline void solve()
{
	read(n),scanf("%s",ch+1);int l=0,r=0;
	for(int i=1;i<=n;i++) if(ch[i]^48) {r=i;if(!l) l=i;}
	if(!l) return printf("%d\n",n),void();
	printf("%d\n",max(2*r,2*(n-l+1)));
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}