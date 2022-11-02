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
int n,sz[505],rs;const int P=1e9+7;
inline int ksm(int x,int q) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
int main()
{
	read(n);for(int i=1,x;i<=n;i++) read(x),~x?sz[x]++:0;
	for(int i=1;i<=n;i++) sz[i]?(rs+=ksm(2,sz[i])-1)%=P:0;
	return printf("%d\n",(ksm(2,n-1)-1-rs+P)%P),0;
}