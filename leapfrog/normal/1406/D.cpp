//Coded by Kamiyama_Shiki on 2021.11.15 {{{
//
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=100005;
int n,Q;ll nw[N],a[N],rs,a1;
inline ll get(ll x) {return x>=0?(x+1)/2:-(-x)/2;}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	a1=a[1];for(int i=1;i<n;i++) rs+=max(nw[i]=a[i+1]-a[i],0ll);
	read(Q),printf("%lld\n",get(a1+rs));for(int l,r,x;Q--;)
	{
		read(l,r,x);if(l==1) a1+=x;
		if(l!=1) rs-=max(nw[l-1],0ll),nw[l-1]+=x,rs+=max(nw[l-1],0ll);
		if(r!=n) rs-=max(nw[r],0ll),nw[r]-=x,rs+=max(nw[r],0ll);
		printf("%lld\n",get(rs+a1));
	}return 0;
}