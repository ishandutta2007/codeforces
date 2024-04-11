//Coded by Kamiyama_Shiki on 2021.11.12 {{{
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
int n,a[N],mx,v[100005];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	int m;read(m);for(int i=1,l,r;i<=m;i++) {read(l,r);for(int i=l;i<=r;i++) v[i]=1;}
	int sm=0;for(int i=1;i<=n;i++) sm+=a[i];
	for(int i=sm;i<=100000;i++) if(v[i]) return printf("%d\n",i),0;
	return puts("-1"),0;
}