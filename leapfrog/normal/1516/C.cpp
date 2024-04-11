//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}int Ca;
int n,a[2005],sm=0;bitset<200005>bt;
inline void solve()
{
	read(n),sm=0;for(int i=1;i<=n;i++) read(a[i]),sm+=a[i];
	bt.reset(),bt[0]=1;for(int i=1;i<=n;i++) bt|=bt<<a[i];
	if((sm&1)||!bt[sm>>1]) return puts("0"),void();
	puts("1");while(1)
	{
		int fg=0;for(int i=1;i<=n;i++) if(a[i]&1) fg=i;
		if(fg) return printf("%d\n",fg),void();else for(int i=1;i<=n;i++) a[i]>>=1;
	}
}
int main() {solve();return 0;}