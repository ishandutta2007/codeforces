//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n,m,a[100005];
inline void solve(double k)
{
	int n=k;for(int i=1;i<=n;i++) a[i]=sqrt(k*k-1ll*i*i);
	a[n+1]=0;int i;for(i=1;i<=n;i++) if(i+1>a[i+1]) break;
	int j;for(j=0;a[i+j+1]==i;j++);
	if(((a[i]-i)&1)||(j&1)) puts("Ashish");else puts("Utkarsh");
}
int main()
{
	for(read(T);T--;) read(n),read(m),solve(1.0*n/m);
	return 0;
}