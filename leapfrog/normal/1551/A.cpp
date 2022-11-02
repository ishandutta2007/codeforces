#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,m,K,a[2000005][5];char ch[2000005];ll N,M;
inline void solve()
{
	read(n);if(n%3==0) printf("%d %d\n",n/3,n/3);
	else if(n%3==1) printf("%d %d\n",n/3+1,n/3);
	else printf("%d %d\n",n/3,n/3+1);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}