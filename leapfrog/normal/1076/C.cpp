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
int Ca;double d,del;
inline void solve()
{
	scanf("%lf",&d),del=d*d-4*d;if(del<0) return puts("N"),void();else puts("Y");
	del=sqrt(del),printf("%.10lf %.10lf\n",(d-del)/2,(d+del)/2);
}
int main() {for(read(Ca);Ca--;) solve();return 0;}