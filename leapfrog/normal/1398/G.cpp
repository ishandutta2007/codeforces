//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
int n,X,Y,a[200005],fg[1000005];bitset<200005>b,bs;
int main()
{
	read(n,X,Y);for(int i=0;i<=n;i++) read(a[i]),bs[a[i]]=1;
	int Q;read(Q),memset(fg,-1,sizeof(fg));for(int i=0;i<=n;i++) b|=bs>>a[i];
	for(int i=1;i<=200000;i++) if(b[i]) for(int L=(i+Y)*2,j=L;j<=1000000;j+=L) fg[j]=max(fg[j],L);
	for(int x;Q--;) read(x),printf("%d%c",fg[x],Q?' ':'\n');
	return 0;
}