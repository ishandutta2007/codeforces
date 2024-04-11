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
inline double ef(double v)
{
	double l=max(0.0,v-5),r=v,md;
	for(int i=100;i;i--) {md=(l+r)/2;if(md+abs(2*sin(md/2))<v) l=md;else r=md;}
	return r;//printf("%.10lf %.10lf\n",v,r);
}
int main()
{
	int n,r,v;read(n,r,v);double q=0;
	for(int s,t;n--;) read(s,t),q=ef((t-s)/1.0/r),printf("%.10lf\n",q*r/v);
	return 0;
}