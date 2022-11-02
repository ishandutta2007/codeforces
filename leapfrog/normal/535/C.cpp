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
int A,B,q;ll a[1000005],s[1000005];
int main()
{
	read(A),read(B),read(q);for(int i=1;i<=1000000;i++)
		a[i]=A+1ll*(i-1)*B,s[i]=s[i-1]+a[i];
	for(int l,x,y;q--;)
	{
		read(l),read(x),read(y);
		int l1=upper_bound(a+1,a+1000001,1ll*x)-a-1;
		int l2=upper_bound(s+1,s+1000001,s[l-1]+1ll*x*y)-s-1;
		if(min(l1,l2)<l) puts("-1");else printf("%d\n",min(l1,l2));
	}
	return 0;
}