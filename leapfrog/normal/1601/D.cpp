//Coded by leapfrog {{{
//Gened on 2021.10.25
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
const int N=500005;
struct node{int s,a;}a[N];int n,D;
inline char cmp(node a,node b)
{
	if(max(a.s,a.a)^max(b.s,b.a)) return max(a.s,a.a)<max(b.s,b.a);
	if(a.s^b.s) return a.s<b.s;
	if(a.a^b.a) return a.a<b.a;
	return 0;
}
int main()
{
	read(n,D);for(int i=1;i<=n;i++) read(a[i].s,a[i].a);
	sort(a+1,a+n+1,cmp);int cn=0;
	for(int i=1;i<=n;i++) if(D<=a[i].s) cn++,D=max(D,a[i].a);
	return printf("%d\n",cn),0;
}