#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
inline ll max(ll a,ll b) {return a>b?a:b;}
inline ll min(ll a,ll b) {return a>b?b:a;}
int n,d,b;ll a[100010],rs;
int main()
{
	read(n),read(d),read(b);
	for(int i=1;i<=n;i++) read(a[i]),a[i]+=a[i-1];
	for(int i=1;i<=(n+1)>>1;i++) rs=max(rs,max(i-a[min(n,1ll*i*(d+1))]/b,i-(a[n]-a[max(0ll,n-1ll*i*(d+1))])/b));
	return printf("%lld\n",rs),0;
}