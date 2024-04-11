//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n;
inline void solve(int n)
{
	if(n==2) return puts("1\n2 1\n1\n2 1"),void();
	if(n==3) return puts("5\n2 3 1\n2\n1 3\n3 2"),void();
	ll res=1ll*(n-1)*(n-1)+1ll*(n&1)*(n>>1)*(n>>1);
	for(int i=(n>>1)+(n&1);i<n-1;i++) res+=2ll*i*i;
	printf("%lld\n%d ",res,(n>>1)+1);
	for(int i=2;i<(n>>1);i++) printf("%d ",i+1);
	printf("1 ");for(int i=(n>>1)+1;i<n;i++) printf("%d ",i+1);
	printf("2\n%d\n",n-1);for(int i=(n>>1)+1;i<n;i++) printf("%d 1\n",i);
	for(int i=2;i<=(n>>1);i++) printf("%d %d\n",i,n);
	printf("%d 1\n",n);
}
int main() {for(read(T);T--;) read(n),solve(n);return 0;}