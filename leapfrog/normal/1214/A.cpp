//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
int n,m,K,a[2000005],b[2000005];char ch[2000005];ll N,M;
int main()
{
	int x,y,rs;read(n),read(x),read(y),y*=5,rs=n;
	for(int i=0;x*i<=n;i++) rs=min(rs,(n-x*i)%y);
	return printf("%d\n",rs),0;
}