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
int n,a[1000005],rs=0;
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) while(a[i]^i) swap(a[a[i]],a[i]),rs++;
	return puts((rs&1)^(n&1)?"Um_nik":"Petr"),0;
}