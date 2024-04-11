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
int Ca,n,a[200005],F[200005][2];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) F[i][0]=1e9,read(a[i]);
	F[0][0]=0,F[1][1]=a[1],F[0][1]=F[1][0]=1e9;for(int i=2;i<=n;i++)
		F[i][0]=min(F[i-1][1],F[i-2][1]),F[i][1]=min(F[i-1][0]+a[i],F[i-2][0]+a[i-1]+a[i]);
	printf("%d\n",min(F[n][0],F[n][1]));
}
int main() {for(read(Ca);Ca--;) solve();return 0;}