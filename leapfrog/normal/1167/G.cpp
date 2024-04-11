//Coded by leapfrog on 2021.10.27 {{{
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
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
const int N=200005;const double Pi=acos(-1);
int n,D,a[N],m,pos=0;
int main()
{
	read(n,D);for(int i=1;i<=n;i++) read(a[i]);
	read(m);for(int i=1,x;i<=m;i++)
	{
		read(x);while(pos<n&&a[pos+1]<x) pos++;
		if(a[pos]==x-1&&a[pos+1]==x) {printf("%.15lf\n",Pi);continue;}
		if(a[pos]==x-1||a[pos+1]==x) {printf("%.15lf\n",Pi/2);continue;}
		int lim=(min(a[pos+1]-x,x-a[pos]-1)+5)*4,pl=pos,pr=pos+1;double rs=0;
		if(pos) rs=max(rs,atan2(1.0,x-a[pos]-1));
		if(pos!=n) rs=max(rs,atan2(1.0,a[pos+1]-x));
		while(pr<=n&&pl>=1&&a[pr]-a[pl]<=lim)
		{
			int d1=a[pr]-x,d2=x-a[pl]-1;
			if(abs(d1-d2)<=1) {rs=max(rs,atan2(1.0,max(d1,d2))*2);break;}
			if(d1<d2) pr++;else pl--;
		}printf("%.15lf\n",rs);
	}return 0;
}