//Coded by Kamiyama_Shiki on 2021.11.03 {{{
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
const int N=200005;
int n,a[N],bt[N],rs[N];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) for(int j=20;~j;j--) bt[j]+=(a[i]>>j)&1;
	for(int i=0;i<=20;i++) for(int j=1;j<=bt[i];j++) rs[j]|=1<<i;
	ll sm=0;for(int i=1;i<=n;i++) sm+=1ll*rs[i]*rs[i];
	return printf("%lld\n",sm),0;
}