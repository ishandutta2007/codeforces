//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int Ca,n,a[200005];char v[200005];const int P=1e9+7;
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),v[i]=1;
	for(int k=0;k<31;k++)
	{
		int cnt=0;for(int i=1;i<=n;i++) cnt+=(a[i]>>k)&1;
		if(cnt==n) continue;
		for(int i=1;i<=n;i++) if((a[i]>>k)&1) v[i]=0;
	}
	int qwq=0;for(int i=1;i<=n;i++) qwq+=v[i];
	int res=1ll*qwq*(qwq-1)%P;for(int i=1;i<=n-2;i++) res=1ll*res*i%P;
	printf("%d\n",res);
}
int main() {for(read(Ca);Ca--;) solve();return 0;}