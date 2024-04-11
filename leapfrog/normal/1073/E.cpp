//Coded by leapfrog {{{
//Gened on 2021.10.25
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
const int P=998244353;
ll l,r,dp[20][2049][2][2];int K,vl[20],ln,sm[20][2049][2][2],pw[20];
inline ll rc(ll w) {int r=0;while(w) w/=10,r++;return r;}
inline void sp(ll x) {for(int i=ln=rc(x);i;i--) vl[i]=x%10,x/=10;}
inline int bitc(int w) {int r=0;for(;w;r++,w-=w&(-w));return r;}
inline ll count(int x,int w,int lim,int zr)
{
	ll &r=dp[x][w][lim][zr];if(~r) return r;
	int &s=sm[x][w][lim][zr];s=0,r=0;
	if(x==ln+1) return r=(bitc(w)<=K)&&zr;
	for(int i=0,ed=lim?vl[x]:9;i<=ed;i++)
		r+=count(x+1,w|((zr||i)<<i),lim&(i==ed),zr||i),
		s=(s+dp[x+1][w|((zr||i)<<i)][lim&&(i==ed)][zr||i]%P*i*pw[ln-x]+sm[x+1][w|((zr||i)<<i)][lim&&(i==ed)][zr||i])%P;
	return r;
}
inline ll solve(ll w)
{
	if(!w) return 0;else sp(w),memset(dp,-1,sizeof(dp));
	return count(1,0,1,0),sm[1][0][1][0];
}
int main()
{
	pw[0]=1;for(int i=1;i<20;i++) pw[i]=1ll*pw[i-1]*10%P;
	return read(l,r,K),printf("%lld\n",(solve(r)-solve(l-1)+P)%P),0;
}