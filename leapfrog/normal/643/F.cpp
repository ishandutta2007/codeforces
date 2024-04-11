//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,p,q,f[205][2];unsigned C[205];
inline int gcd(int x,int y) {return y?gcd(y,x%y):x;}
inline unsigned calc(int x)
{
	for(int i=1;i<=x;i++) f[i][0]=n+1-i,f[i][1]=i;
	for(int i=1,g;i<=x;i++) for(int j=1;j<=x;j++) g=gcd(f[i][0],f[j][1]),f[i][0]/=g,f[j][1]/=g;
	unsigned res=1;for(int i=1;i<=x;i++) res*=f[i][0];
	return res;
}
int main()
{
	read(n),read(p),read(q),p=min(p,n-1);unsigned res=0;
	unsigned pw;for(int i=0;i<=p;i++) C[i]=calc(i);
	for(int i=1,nw=0;i<=q;res^=nw*i,i++,nw=0) for(int j=(pw=1)-1;j<=p;j++,pw*=i) nw+=pw*C[j];
	return printf("%u\n",res),0;
}