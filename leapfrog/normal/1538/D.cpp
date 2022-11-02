//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int a,b,k;
inline int cal(int x)
{
	int cnt=0;
	for(int i=2;i*i<=x;i++) while(x%i==0) x/=i,cnt++;
	return cnt+(x!=1);
}
inline void solve()
{
	read(a),read(b),read(k);
	if(cal(a)+cal(b)<k) return puts("NO"),void();
	int x=__gcd(a,b),ccc=(a!=x)+(b!=x);
	if(k==1&&a==b) return puts("NO"),void();
	if(ccc>k) return puts("NO"),void();else puts("YES");
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}