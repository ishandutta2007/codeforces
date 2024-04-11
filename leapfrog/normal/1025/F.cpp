//Coded by leapfrog on 2021.11.04 {{{
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
const int N=2005;const long double Pi=acos(-1),eps=1e-9;
int n,px[N],py[N];ll rs=0;long double an[N*2];
inline ll C(ll a) {return 1ll*a*(a-1)/2;}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(px[i],py[i]);
	for(int k=1,at=0;k<=n;k++,at=0)
	{
		for(int i=1;i<=n;i++) if(k^i) an[++at]=atan2(py[i]-py[k],px[i]-px[k]);
		sort(an+1,an+at+1);for(int i=1;i<n;i++) an[++at]=an[i]+Pi*2;
		for(int i=1,j=1;i<n;i++)
		{
			while(an[j]-an[i]<=Pi) j++;
			int l=j-i-1,r=n-2-l;rs+=1ll*C(l)*C(r);
		}
	}return printf("%lld\n",rs>>1),0;
}