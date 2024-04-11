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
int T,p[100005],pc,d;char v[100005];
inline void init()
{
	const int N=100000;for(int i=2;i<=N;i++)
	{
		if(!v[i]) p[++pc]=i;
		for(int j=1;j<=pc&&i*p[j]<=N;j++) {v[i*p[j]]=1;if(i%p[j]==0) break;}
	}
}
inline void solve()
{
	read(d);int x=lower_bound(p+1,p+pc+1,d+1)-p;
	int y=lower_bound(p+1,p+pc+1,p[x]+d)-p;
	printf("%lld\n",1ll*p[x]*p[y]);
}
int main() {for(init(),read(T);T--;) solve();return 0;}