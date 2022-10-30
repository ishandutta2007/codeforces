//Coded by leapfrog {{{
//Coded on 2021.10.26
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
const int N=505,P=998244353;const double eps=1e-8;
int n,at,cn[N];ll a[N];map<ll,int>mp,fg;
inline ll chk2(ll w) {ll q=sqrt(w)+eps;return q*q==w?q:-1;}
inline ll chk3(ll w)
{
	ll rs=0;for(ll L=0,R=1259922,md=(L+R)>>1;L<=R;md=(L+R)>>1)
		if(md*md*md<=w) rs=md,L=md+1;else R=md-1;
	if(1ll*rs*rs*rs==w) return rs;else return -1;
}
inline ll chk4(ll w) {ll f=chk2(w);return ~f?chk2(f):f;}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	ll v=0;for(int i=1;i<=n;i++)
	{
		if(~(v=chk4(a[i]))) mp[v]+=4;
		else if(~(v=chk3(a[i]))) mp[v]+=3;
		else if(~(v=chk2(a[i]))) mp[v]+=2;
		else a[++at]=a[i],cn[at]=2,fg[a[i]]++;
	}
	for(int abc=2;abc--;) for(int i=1;i<=at;i++) for(int j=i+1;j<=at;j++)
		if((v=__gcd(a[i],a[j]))!=1&&!fg[v]) mp[v];
	for(auto &x:mp) for(int i=1;i<=at;i++) if(a[i]%x.first==0) fg[a[i]]--,mp[a[i]/x.first]++,x.second++,a[i]=1;
	int rs=1;for(auto x:mp) rs=1ll*rs*(x.second+1)%P;
	for(auto x:fg) rs=1ll*rs*(x.second+1)%P*(x.second+1)%P;
	return printf("%d\n",rs),0;
}