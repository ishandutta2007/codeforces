#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,m,K;
inline void solve()
{
	read(n),read(m),read(K);
	if(n&1)
	{
		if(K<m/2) return puts("NO"),void();
		K-=m/2;if(K&1) return puts("NO"),void();
		return puts("YES"),void();
	}
	if(m&1)
	{
		int kk=n*m/2-K;if(kk<n/2) return puts("NO"),void();
		kk-=n/2;if(kk&1) return puts("NO"),void();
		return puts("YES"),void();
	}
	if(K&1) return puts("NO"),void();else puts("YES");
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}