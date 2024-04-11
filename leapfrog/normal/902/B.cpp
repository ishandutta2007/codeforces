//Coded by Kamiyama_Shiki on 2021.11.04 {{{
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
const int N=10005;int n,f[N],c[N],rs=0;
int main()
{
	read(n);for(int i=2;i<=n;i++) read(f[i]);
	for(int i=1;i<=n;i++) read(c[i]),rs+=c[i]!=c[f[i]];
	return printf("%d\n",rs),0;
}