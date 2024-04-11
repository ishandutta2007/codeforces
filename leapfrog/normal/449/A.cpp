#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
int main()
{
	ll n,m,k;read(n,m,k);
	if(k>n+m-2) return puts("-1"),0;else if(n<m) swap(n,m);
	if(k<m) return printf("%lld\n",max(n/(k+1)*m,m/(k+1)*n)),0;
	else if(k<n) return printf("%lld\n",max(n/(k-m+2),n/(k+1)*m)),0;
	else return printf("%lld\n",max(n/(k-m+3),m/(k-n+2))),0;
}