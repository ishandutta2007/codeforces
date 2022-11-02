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
int n,m;
inline void solve()
{
	read(n),read(m);if(n>m) swap(n,m);
	int qw=m-n,l=0,r=44722,rs=0;
	while(l<=r) {int md=(l+r)>>1;if(md*(md+1)/2>=qw) rs=md,r=md-1;else l=md+1;}
	if((rs*(rs+1)/2-qw)&1) rs++;
	if((rs*(rs+1)/2-qw)&1) rs++;
	printf("%d\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}