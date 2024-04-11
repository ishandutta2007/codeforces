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
int n,a[100005];ll rs=1e18;
int main()
{
	read(n);for(int i=0;i<n;i++) read(a[i]);
	sort(a,a+n);int lim=0;
	for(int i=1;i<=100001;i++) if(pow(i,n-1)>=1e10) {lim=i+1;break;}
	for(int i=1;i<=lim;i++)
	{
		ll vl=1,sm=0;char fg=0;
		for(int j=0;j<n;j++)
		{
			sm+=abs(a[j]-vl);
			if(1.0*vl*i>1e18) fg=1;else vl*=i;
		}
		if(!fg) rs=min(rs,sm);
	}return printf("%lld\n",rs),0;
}