//
//
#include<bits/stdc++.h>
using namespace std;const int P=1e9+7;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,a[1000005],ls[1000005];long long f[1000005],s;
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) f[i]=f[i-1]+i-ls[a[i]],s+=f[i],ls[a[i]]=i;
	return printf("%.10lf\n",1.0*(s*2-n)/n/n),0;
}