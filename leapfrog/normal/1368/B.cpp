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
int cn[10];const char ch[11]="codeforces";
int main()
{
	ll n,nw=1;read(n);for(int i=0;i<10;i++) cn[i]=1;
	for(int i=0;nw<n;) nw/=cn[i],nw*=++cn[i++],i%=10;
	for(int i=0;i<10;i++) while(cn[i]--) putchar(ch[i]);
	return putchar('\n'),0;
}