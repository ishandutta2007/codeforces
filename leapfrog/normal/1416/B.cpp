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
int T,n,a[10005];
inline void mv(int i,int j,int x) {printf("%d %d %d\n",i,j,x),a[i]-=i*x,a[j]+=i*x;}
inline void solve()
{
	read(n);ll sm=0;
	for(int i=1;i<=n;i++) read(a[i]),sm+=a[i];
	if(sm%n) return puts("-1"),void();else sm/=n,printf("%d\n",3*(n-1));
	for(int i=2;i<=n;i++) mv(1,i,(i-a[i]%i)%i),mv(i,1,a[i]/i);
	for(int i=2;i<=n;i++) mv(1,i,sm);
}
int main() {for(read(T);T--;) solve();return 0;}