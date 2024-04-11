//Coded by leapfrog on 2021.11.05 {{{
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
const int N=1005;
int n,m,a[N];
int main()
{
	read(n,m);for(int i=1;i<=m;i++) a[1ll*i*i%m]+=n/m;
	for(int i=n/m*m+1;i<=n;i++) a[(i%m)*(i%m)%m]++;
	ll rs=1ll*a[0]*a[0];for(int i=1;i<m;i++) rs+=1ll*a[i]*a[m-i];
	return printf("%lld\n",rs),0;
}