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
const int N=100005;ll bt[65];int Q;
inline int lg(ll x) {int r=0;while(x) x>>=1,r++;return r;}
inline ll mod(ll w,ll d) {w=w&((1ll<<d)-1),w+=1ll<<d,w=w&((1ll<<d)-1);return w;}
int main()
{
	for(read(Q);Q--;)
	{
		int fg,d;ll x,k;read(fg,x),d=lg(x)-1;if(fg^3) read(k),k=mod(k,d);
		if(fg==1) {bt[d]=(bt[d]+k)&((1ll<<d)-1);continue;}
		if(fg==2) {for(;d<62;d++,k<<=1) bt[d]=(bt[d]+k)&((1ll<<d)-1);continue;}
		x=((x+bt[d])&((1ll<<d)-1))+(1ll<<d);
		for(;x;x>>=1,d--) printf("%lld ",((x-bt[d])&((1ll<<d)-1))+(1ll<<d));
		putchar('\n');
	}return 0;
}