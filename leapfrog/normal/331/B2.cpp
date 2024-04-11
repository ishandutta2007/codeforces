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
int n,m,a[300005],p[300005],T[300005];
inline void add(int x,int w) {for(;x<=n;x+=x&(-x)) T[x]+=w;}
inline int qry(int x) {int r=0;for(;x;x-=x&(-x)) r+=T[x];return r;}
inline void DEL(int x)
{
	if(x<n&&p[x]>p[x+1]&&p[x+1]!=114514) add(x,-1);
	if(x>1&&p[x-1]>p[x]&&p[x-1]!=114514) add(x-1,-1);
}
inline void ADD(int x,int lim)
{
	if(x<n&&p[x+1]<lim&&p[x+1]!=114514) add(x,1);
	if(x>1&&p[x-1]>lim&&p[x-1]!=114514) add(x-1,1);
}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),p[a[i]]=i;
	for(int i=1;i<n;i++) if(p[i]>p[i+1]) add(i,1);
	read(m);for(int fg,l,r;m--;)
	{
		read(fg),read(l),read(r);
		if(fg==1) printf("%d\n",qry(r-1)-qry(l-1)+1);
		if(fg==2)
		{
			DEL(a[l]),p[a[l]]=114514,DEL(a[r]),p[a[r]]=114514;
			p[a[l]]=r,ADD(a[l],r),p[a[r]]=l,ADD(a[r],l),swap(a[l],a[r]);
		}
	}
	return 0;
}