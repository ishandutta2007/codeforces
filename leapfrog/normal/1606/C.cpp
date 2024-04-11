#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
__int128 pw[105],vl[105],nw[105],la[105];int n,K,a[105];char fg[105];
inline void solve()
{
	read(n,K),K++;for(int i=1;i<=n;i++) read(a[i]);
	memset(fg,0,sizeof(fg));for(int i=1;i<=n;i++) fg[a[i]]=1;
	__int128 qwq=1,rs=0;vl[0]=1;
	for(int i=1;i<=30;vl[i]=qwq,i++) if(fg[i]) qwq=1;else qwq*=10;
	int tp=K,ls=0;
	for(int i=0;i<=30;i++)
		if(9*vl[i]>tp) {nw[i]=(tp+vl[i]-1)/vl[i],ls=i;break;}
		else nw[i]=9,tp-=nw[i]*vl[i],la[i]=(i?la[i-1]:0)+nw[i]*vl[i];
	for(int i=ls;i;i--) {int tp=(K-la[i-1]+vl[i]-1)/vl[i];rs+=tp*pw[i],K-=tp*vl[i];}
	ll temp=rs;printf("%lld\n",temp+K);
}
int main()
{
	pw[0]=1;for(int i=1;i<=30;i++) pw[i]=pw[i-1]*10;
	int Ca;for(read(Ca);Ca--;) solve();return 0;
}