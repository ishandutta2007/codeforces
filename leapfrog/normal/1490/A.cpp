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
int n,T,a[1005],res;
inline void solve()
{
	read(n),res=0;for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<n;i++)
	{
		int x=min(a[i],a[i+1]),y=a[i]^a[i+1]^x;
		while(y>x*2) x<<=1,res++;
	}
	printf("%d\n",res);
}
int main() {for(read(T);T--;) solve();return 0;}