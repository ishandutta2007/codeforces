//Coded by Kamiyama_Shiki on 2021.11.09 {{{
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
const int N=300005;
struct ${int t,b;}a[N];int n,K;
int main()
{
	read(n,K);for(int i=1;i<=n;i++) read(a[i].t,a[i].b);
	sort(a+1,a+n+1,[&]($ x,$ y){return x.b>y.b;});priority_queue<int>q;
	ll tot=0,rs=0;for(int i=1;i<=K;i++) tot+=a[i].t,rs=max(rs,tot*a[i].b),q.push(-a[i].t);
	for(int i=K+1;i<=n;i++) tot+=q.top()+a[i].t,q.pop(),q.push(-a[i].t),rs=max(rs,tot*a[i].b);
	return printf("%lld\n",rs),0;
}