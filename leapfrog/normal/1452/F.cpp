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
int n,Q,cn[35];
int main()
{
	read(n,Q);for(int i=0;i<n;i++) read(cn[i]);
	for(int fg,x;Q--;)
	{
		ll k;read(fg,x,k);if(fg&1) {cn[x]=k;continue;}
		int sm=0;ll rs=0;for(int i=0;i<=x;i++) sm+=cn[i];
		if(sm>=k) {printf("%d\n",0);continue;}else k-=sm;
		ll tt=0;for(int i=1;i<=x;i++) tt+=((1ll<<i)-1)*cn[i];
		ll wj=0;for(int i=0;i<n;i++) wj+=(1ll<<i)*cn[i];
		if(wj<k) {puts("-1");continue;}
		int jc=0;for(int i=x+1;i<n;i++)
		{
			int lf=min(1ll*cn[i],k>>(i-x));k-=(1ll<<(i-x))*lf;
			rs+=1ll*lf*((1ll<<(i-x))-1),tt+=((1ll<<i)-(1ll<<(i-x)))*lf;
			if(lf<cn[i]) {jc=i;break;}
		}if(k==0) {printf("%lld\n",rs);continue;}
		if(jc==0) {printf("%lld\n",tt>=k?rs+k:-1ll);continue;}
		ll as=1e18;for(int i=jc;i>x;)
		{
			if(tt>=k) as=min(as,rs+k);
			rs++,i--;if(k>=(1ll<<(i-x)))
				rs+=(1ll<<(i-x))-1,k-=1ll<<(i-x),tt+=((1ll<<i)-(1ll<<(i-x)));
		}printf("%lld\n",min(as,rs));
	}
	return 0;
}