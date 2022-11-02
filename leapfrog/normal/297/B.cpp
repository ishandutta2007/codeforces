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
int n,m,K,a[100005],b[100005];
int main()
{
	read(n),read(m),read(K);if(n>m) return puts("YES"),0;
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=m;i++) read(b[i]);
	sort(a+1,a+n+1),sort(b+1,b+m+1);
	for(int i=1;i<=n;i++) if(a[i]>b[m-n+i]) return puts("YES"),0;
	return puts("NO"),0;
}