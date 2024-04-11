//
#include<bits/stdc++.h>
#define ri register
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int n,bit[(1<<21)+5];long long a[(1<<21)+5],b[(1<<21)+5],c[(1<<21)+5];
inline void FwtOr(int n,long long *a,int fg)
{
	for(int d=1;d<n;d<<=1)
		for(int i=0;i<n;i+=(d<<1))
			for(int j=0;j<d;j++)
				a[i|j|d]+=a[i|j]*fg;
}
int main()
{
	read(n);for(int i=1;i<(1<<n);i++) bit[i]=bit[i>>1]+(i&1);
	for(int i=0;i<(1<<n);i++) scanf("%1lld",a+i),a[i]<<=(bit[i]<<1);
	for(int i=0;i<(1<<n);i++) scanf("%1lld",b+i),b[i]<<=(bit[i]<<1);
	FwtOr(1<<n,a,1),FwtOr(1<<n,b,1);
	for(int i=0;i<(1<<n);i++) c[i]=a[i]*b[i];
	FwtOr(1<<n,c,-1);
	for(int i=0;i<(1<<n);i++) printf("%lld",(c[i]>>(bit[i]<<1))&3);
	return putchar('\n'),0;
}