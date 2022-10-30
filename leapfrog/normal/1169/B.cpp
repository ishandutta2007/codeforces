#include<bits/stdc++.h>
using namespace std;
struct edge{int to,w,nxt;}e[400005];
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
template<typename T>inline void write(T x) {{if(x<0) putchar('-'),x=-x;}{if(x>9) write(x/10);}putchar(x%10+48);}
int n,m,v[300005],a[300005],b[300005];
inline char wrk(int x) {int f=0;memset(v,0,sizeof(v));for(int i=1;i<=m;i++) if(a[i]==x||b[i]==x) v[i]=1;else f=1;return !f;}
inline char chk(int x) {for(int i=1;i<=m;i++) if(!v[i]&&a[i]!=x&&b[i]!=x) return 0;return 1;}
int main()
{
	read(n),read(m);
	for(int i=1;i<=m;i++) read(a[i]),read(b[i]);
	{if(wrk(a[1])) return puts("YES"),0;}for(int i=1;i<=m;i++) if(!v[i]) {if(chk(a[i])||chk(b[i])) return puts("YES"),0;else break;}
	{if(wrk(b[1])) return puts("YES"),0;}for(int i=1;i<=m;i++) if(!v[i]) {if(chk(a[i])||chk(b[i])) return puts("YES"),0;else break;}
	return puts("NO"),0;
}