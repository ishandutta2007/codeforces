//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
struct node{int w,id,fr,tw;char fg;}a[100005];int n,m,l=2,r=3,id=1;
int main()
{
	read(n),read(m);for(int i=1;i<=m;i++) read(a[i].w),read(a[i].fg),a[i].id=i;
	sort(a+1,a+m+1,[](node a,node b){return a.w<b.w||(a.w==b.w&&a.fg>b.fg);});
	for(int i=1;i<=m;i++)
	{
		if(a[i].fg) {a[i].fr=1,a[i].tw=++id;continue;}
		if(r>id) return puts("-1"),0;
		a[i].fr=l++,a[i].tw=r;if(l==r) r++,l=2;
	}sort(a+1,a+m+1,[](node a,node b){return a.id<b.id;});
	for(int i=1;i<=m;i++) printf("%d %d\n",a[i].fr,a[i].tw);
	return 0;
}