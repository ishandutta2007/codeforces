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
const int N=105;
int n,fg[N];
int main()
{
	read(n);for(int i=1,k,w;i<=n;i++) {read(k);while(k--) read(w),fg[w]++;}
	for(int i=1;i<=100;i++) if(fg[i]==n) printf("%d ",i);
	return putchar('\n'),0;
}