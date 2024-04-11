#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
template<typename T,typename... A>inline void read(T &t,A &...a) {read(t),read(a...);}
struct node{long long v;int _2,_3;bool operator<(node b) const {return _3>b._3||(_3==b._3&&_2<b._2);}}a[105];int n;
inline int get2(long long x) {int c=0;while(x%2==0) x/=2,c++;return c;}
inline int get3(long long x) {int c=0;while(x%3==0) x/=3,c++;return c;}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i].v),a[i]._2=get2(a[i].v),a[i]._3=get3(a[i].v);
	sort(a+1,a+n+1);for(int i=1;i<=n;i++) printf("%lld%c",a[i].v,i==n?'\n':' ');
	return 0;
}