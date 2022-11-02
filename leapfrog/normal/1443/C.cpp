//
//
#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct node{int a,b;bool operator<(node x) const {return a>x.a;}}t[200005];
int Q,n;
signed main()
{
	for(read(Q);Q--;)
	{
		read(n),t[n+1].a=0;
		for(int i=1;i<=n;i++) read(t[i].a);
		for(int i=1;i<=n;i++) read(t[i].b);
		sort(t+1,t+n+1);long long mn=t[1].a,sm=0;
		for(int i=1;i<=n;i++) sm+=t[i].b,mn=min(mn,max(sm,t[i+1].a));
		printf("%lld\n",mn);
	}
	return 0;
}