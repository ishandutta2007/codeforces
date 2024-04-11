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
int n,a[1000005],tp;
struct seg{int l,r;ll sm;}st[1000005];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	st[++tp]=(seg){1,1,a[1]};for(int i=2;i<=n;i++)
	{
		st[++tp]=(seg){i,i,a[i]};while(tp>1)
		{
			seg a=st[tp-1],b=st[tp];
			double av=1.0*a.sm/(a.r-a.l+1),bv=1.0*b.sm/(b.r-b.l+1);
			if(av>=bv) tp--,st[tp]=(seg){a.l,b.r,a.sm+b.sm};else break;
		}
	}
	for(int i=1;i<=tp;i++)
	{
		seg a=st[i];double w=1.0*a.sm/(a.r-a.l+1);
		for(int i=a.l;i<=a.r;i++) printf("%.10lf\n",w);
	}
	return 0;
}