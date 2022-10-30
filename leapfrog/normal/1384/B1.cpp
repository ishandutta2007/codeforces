//Coded by Katou_Umi on 2021.10.31 {{{
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
const int N=300005;int n,K,l,d[N];
inline void solve()
{
	read(n,K,l);for(int i=1;i<=n;i++) read(d[i]);
	for(int i=1,ls=0;i<=n;i++)
	{
		if(d[i]>l) return puts("No"),void();
		else if(d[i]+K<=l) ls=0;
		else if(ls<K) ls=max(ls+1,K-l+d[i]);
		else if(K+l-d[i]<ls+1) return puts("No"),void();
		else ls++;
	}puts("Yes");
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}