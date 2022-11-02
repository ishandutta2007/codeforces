//
//
#include<bits/stdc++.h>
using namespace std;const int P=1e9+7;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,m,k,f[1005][1005];
int main()
{
	read(n),read(m),read(k),memset(f,0,sizeof(f));if(n<m) swap(n,m);
	for(int i=1;i<=n;i++) f[0][i]=1;
	for(int i=1;i<=k;i++) for(int p=1;p<=n;p++) if(f[i-1][p])
		for(int q=p+2;q<=n;q++) f[i][q]=(f[i][q]+1ll*f[i-1][p]*(q-p-1)%P)%P;
	return printf("%lld\n",1ll*f[k][n]*f[k][m]%P),0;
}