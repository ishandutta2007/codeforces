//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	char c=getchar();int f=0;x=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	f?x=-x:x;
}
int T,q;ll p;
inline ll gt(int f,ll w) {int cnt=0;while(w%f==0) w/=f,cnt++;return cnt;}
inline char chk(int x) {for(int i=2;i*i<=x;i++) if(x%i==0) return 0;return 1;}
inline ll ksm(ll x,int q) {ll r=1;for(;q;q>>=1,x*=x) if(q&1) r*=x;return r;}
inline void solve()
{
	read(p),read(q);ll mx=1e18;
	for(int i=2,x=0,w;i*i<=q;i++,x=0) {while(q%i==0) q/=i,x++;w=gt(i,p);if(x&&x<=w+1) mx=min(mx,ksm(i,w-x+1));}
	if(q!=1) mx=min(mx,ksm(q,gt(q,p)));
	printf("%lld\n",mx==1000000000000000000ll?p:p/mx);
}
int main() {for(read(T);T--;) solve();return 0;}