//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int n,K,Q,cf[200005];
int main()
{
	read(n),read(K),read(Q);
	for(int i=1,l,r;i<=n;i++) read(l),read(r),cf[l]++,cf[r+1]--;
	for(int i=1;i<=200000;i++) cf[i]+=cf[i-1];
	for(int i=1;i<=200000;i++) cf[i]=cf[i]>=K,cf[i]+=cf[i-1];
	for(int l,r;Q--;) read(l),read(r),printf("%d\n",cf[r]-cf[l-1]);
	return 0;
}