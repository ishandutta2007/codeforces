//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int main()
{
	int hh,mm,h,d,c,n;read(hh),read(mm),read(h),read(d),read(c),read(n);
	if(hh>=20) return printf("%.10lf\n",0.8*c*((h+n-1)/n)),0;
	double v1=1.0*c*((h+n-1)/n),v2=0.8*c*(((h+((20-hh)*60-mm)*d)+n-1)/n);
	return printf("%.10lf\n",min(v1,v2)),0;
}