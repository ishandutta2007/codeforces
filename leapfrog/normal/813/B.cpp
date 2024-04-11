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
ll L,R,x,y,a[105],b[105],c[10005],at,bt,ct;
int main()
{
	read(x,y,L,R);ll nw;
	nw=1;for(;;) {a[++at]=nw;if(1.0*nw*x>2e18) break;else nw*=x;}
	nw=1;for(;;) {b[++bt]=nw;if(1.0*nw*y>2e18) break;else nw*=y;}
	for(int i=1;i<=at;i++) for(int j=1;j<=bt;j++) c[++ct]=a[i]+b[j];
	//for(int i=1;i<=ct;i++) printf("%lld%c",c[i],i==ct?'\n':' ');
	c[++ct]=R+1,sort(c+1,c+ct+1);ll rs=0;
	for(int i=1;i<=ct;i++) rs=max(rs,min(R,c[i]-1)-max(L,c[i-1]+1)+1);
	return printf("%lld\n",rs),0;
}