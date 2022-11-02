#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,l[1000005],f[1000005],s[10000005];
int main()
{
	read(n),memset(l,0,sizeof(l));
	for(int i=1,a,b;i<=n;i++) read(a),a++,read(b),l[a]=max(b,l[a]),s[a]++;
	int mx=0;for(int i=1;i<=1000001;i++) if(!s[i]) f[i]=f[i-1];else if(l[i]>=i) f[i]=1;else f[i]=f[i-l[i]-1]+1;
	for(int i=1;i<=1000001;i++) mx=max(mx,f[i]);
	return printf("%d\n",n-mx),0;
}