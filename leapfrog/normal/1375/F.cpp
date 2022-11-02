//{{{
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
pair<ll,int>a[5];
inline void out(ll v)
{
	printf("%lld\n",v),fflush(stdout);ll x;read(x);
	for(int i=1;i<=3;i++) if(a[i].second==x) a[i].first+=v;
	sort(a+1,a+4);if(x==0) exit(0);
}
int main()
{
	for(int i=1;i<=3;i++) read(a[i].first),a[i].second=i;
	puts("First"),fflush(stdout);
	out(1000000005);
	out(a[3].first*2-a[2].first-a[1].first);
	out(a[3].first-a[2].first);
	return 0;
}