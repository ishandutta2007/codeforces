//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int n,a[1005];const int Y[13]={31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	int ck=0;for(int i=1;i<=n;i++) ck+=a[i]==29;
	if(ck>1) return puts("NO"),0;
	for(int k=0;k<12;k++)
	{
		char ck=1;for(int i=1;i<=n;i++) if(a[i]==Y[(k+i)%12]||(a[i]==29&&Y[(k+i)%12]==28));else ck=0;
		if(ck) return puts("YES"),0;
	}
	return puts("NO"),0;
}