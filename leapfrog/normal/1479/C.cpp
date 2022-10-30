//Coded by Kamiyama_Shiki on 2021.11.08 {{{
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
int L,R,tot,id[55],et=0,fr[5555],tw[5555],we[5555];
inline void adde(int x,int y,int w) {++et,fr[et]=x,tw[et]=y,we[et]=w;}
inline void flush()
{
	printf("YES\n%d %d\n",tot,et);
	for(int i=1;i<=et;i++) printf("%d %d %d\n",fr[i],tw[i],we[i]);
}
int main()
{
	read(L,R);int n=R-L+1,lg=0;for(;(1ll<<lg)<=n;lg++);
	int s=++tot;if(L!=1) adde(1,s=++tot,L-1);
	for(int i=0;i<lg;i++) id[i]=++tot;
	int o=++tot;swap(id[lg-1],o);
	for(int i=0;i<lg;i++) adde(s,id[i],1);
	for(int i=0;i<lg;i++) for(int j=i+1;j<lg;j++) adde(id[i],id[j],1<<i);
	for(int i=1;i<lg;i++) if((n>>(i-1))&1) adde(id[i-1],o,((n>>i)<<i)-1);
	return adde(o,tot,1),flush(),0;
}