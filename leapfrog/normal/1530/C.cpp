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
int n,a[100005],b[100005];
inline char chk(int num)
{
	int tot=num+n,rst=tot-(tot/4);
	int sa=num*100;for(int i=1;i<=rst-num;i++) sa+=a[i];
	int sb=0;for(int i=1;i<=rst&&i<=n;i++) sb+=b[i];
	return sa>=sb;
}
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) read(b[i]);
	sort(a+1,a+n+1,greater<int>()),sort(b+1,b+n+1,greater<int>());
	//return printf("%d\n",chk(2)),void();
	int l=0,r=n*4,rs=n*4;
	while(l<=r) {int md=(l+r)>>1;if(chk(md)) rs=md,r=md-1;else l=md+1;}
	printf("%d\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}