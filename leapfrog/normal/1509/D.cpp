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
int Ca,n;char a[200005],b[200005],c[200005];
inline void solve()
{
	read(n),scanf("%s%s%s",a+1,b+1,c+1);
	int nw=1,na=1,nb=1,nc=1;a[n+n+1]=b[n+n+1]=c[n+n+1]='.';
	while(nw<=n+n+n)
	{
		int c0=(a[na]=='0')+(b[nb]=='0')+(c[nc]=='0');
		int c1=(a[na]=='1')+(b[nb]=='1')+(c[nc]=='1');
		if(c0>c1) putchar('0'),na+=(a[na]=='0'),nb+=(b[nb]=='0'),nc+=(c[nc]=='0');
		else putchar('1'),na+=(a[na]=='1'),nb+=(b[nb]=='1'),nc+=(c[nc]=='1');
		nw++;if(na>n+n||nb>n+n||nc>n+n) break;
	}
	if(na==n+n+1&&nb>nc) for(int i=nb;i<=n+n;i++) putchar(b[i]);
	else if(na==n+n+1&&nb<=nc) for(int i=nc;i<=n+n;i++) putchar(c[i]);
	else if(nb==n+n+1&&na>nc) for(int i=na;i<=n+n;i++) putchar(a[i]);
	else if(nb==n+n+1&&na<=nc) for(int i=nc;i<=n+n;i++) putchar(c[i]);
	else if(nc==n+n+1&&na>nb) for(int i=na;i<=n+n;i++) putchar(a[i]);
	else if(nc==n+n+1&&na<=nb) for(int i=nb;i<=n+n;i++) putchar(b[i]);
}
int main() {for(read(Ca);Ca--;) solve(),putchar('\n');return 0;}