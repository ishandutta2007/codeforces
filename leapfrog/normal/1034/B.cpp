//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int n,m;
int main()
{
	read(n),read(m);if(n>m) swap(n,m);//4+5+6
	if(n==1) return printf("%d\n",m/6*6+(max(0,m%6-3)<<1)),0;
	if(n>=3) return printf("%lld\n",1ll*n*m-((n&1)&(m&1))),0;
	if(m<=2) return puts("0");else if(m==3) return puts("4"),0;
	if(m==7) return puts("12"),0;else return printf("%d\n",m<<1),0;
}