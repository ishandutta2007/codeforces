//
//!
//
//
//!
//
//
//
//
//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
template<typename T>inline void write(T x) {{if(x<0) putchar('-'),x=-x;}{if(x>9) write(x/10);}putchar(x%10+48);}
int n,k,a[505];
int main()
{
	read(n),read(k),memset(a,0,sizeof(a));int r=0;
	for(int i=1,x;i<=n;i++) read(x),a[x%k]++;
	r=a[0]>>1;for(int i=1;i<k/2;i++) r+=min(a[i],a[k-i]);
	if(k&1) r+=min(a[k>>1],a[(k>>1)+1]);else r+=a[k>>1]>>1;
	return printf("%d\n",r<<1),0;
}