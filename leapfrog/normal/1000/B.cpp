//Coded by Kamiyama_Shiki on 2021.11.10 {{{
//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=100005;int n,m,a[N],ln[N];ll q1[N],q2[N];
int main()
{
	read(n,m);for(int i=1;i<=n;i++) read(a[i]);
	a[n+1]=m,sort(a+1,a+n+2);for(int i=1;i<=n+1;i++) ln[i]=a[i]-a[i-1];
	ll rs=0;for(int i=1;i<=n+1;i+=2) rs+=ln[i];
	for(int i=1;i<=n+1;i++) q1[i]=q1[i-1]+(i&1?ln[i]:0),q2[i]=q2[i-1]+(i&1?0:ln[i]);
	for(int i=1;i<=n+1;i++) if(ln[i]^1) rs=max(rs,q1[i-1]+ln[i]-1+q2[n+1]-q2[i]);
	return printf("%lld\n",rs),0;
}