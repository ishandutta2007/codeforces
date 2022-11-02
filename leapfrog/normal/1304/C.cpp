//
//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct node{int t,l,r;bool operator<(node b) const {return t<b.t;}}a[10005];
int T,n,m;
int main()
{
	for(read(T);T--;)
	{
		read(n),read(m),a[0].t=0;
		for(int i=1;i<=n;i++) read(a[i].t),read(a[i].l),read(a[i].r);
		sort(a+1,a+n+1);int mx=m,mn=m,tag=0;
		for(int i=1;i<=n;i++)
		{
			int dl=mn-a[i].t+a[i-1].t,dr=mx+a[i].t-a[i-1].t;
			if(dl>a[i].r||a[i].l>dr) {tag=1;break;}
//			printf("zk : %d , %d\n",mn,mx);
			mn=max(dl,a[i].l),mx=min(dr,a[i].r);
		}
		if(tag) puts("NO");else puts("YES");
	}
	return 0;
}