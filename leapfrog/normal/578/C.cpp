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
#define double long double
int n,a[200005];
inline double solve(double dx)
{
	double rs=0,na=0,nb=0,zr=0;
	for(int i=1;i<=n;i++)
		na=max(zr,na+a[i]-dx),nb=min(zr,nb+a[i]-dx),rs=max(rs,max(na,-nb));
	return rs;
}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	double l=-10005,r=10005;for(int i=60;i;i--)
		{double md=(l+r)/2;if(solve(md)>=solve(md+1e-12)) l=md;else r=md+1e-12;}
	return printf("%.6Lf\n",solve(l)),0;
}