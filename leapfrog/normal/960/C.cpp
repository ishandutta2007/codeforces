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
ll X,d,pw[50];
int main()
{
	for(int i=0;i<=40;i++) pw[i]=(1<<i)-1;
	read(X,d);ll nw=1;vector<ll>rs;
	while(X)
	{
		int ps=upper_bound(pw+1,pw+41,X)-pw-1;
		X-=pw[ps];for(int i=1;i<=ps;i++) rs.push_back(nw);
		nw+=1000000005;
	}
	printf("%d\n",(int)rs.size());
	for(ll x:rs) printf("%lld ",x);
	return putchar('\n'),0;
}