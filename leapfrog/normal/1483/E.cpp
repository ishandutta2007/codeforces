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
ll M,P=1,dp[55][105],debug;
inline char Ask(ll X)
{
#ifdef ONLINE_JUDGE
	if(X>100000000000000) return 0;
	printf("? %lld\n",X),fflush(stdout);char ch[15];
	scanf("%s",ch);if(ch[1]=='i') exit(0);
	if(*ch=='L') return P+=X,1;else return P-=X,0;
#else
	debug++;
	if(X<=M) return P+=X,1;else if(X>M&&P>=X) return P-=X,0;
	puts("OH NO your quertion is wrong!"),exit(0);
#endif
}
inline void Ans(ll x)
{
#ifdef ONLINE_JUDGE
	printf("! %lld\n",x),fflush(stdout);
#else
	if(x==M) puts("Accepted!");else puts("Wrong Answer /ll");
	printf("totally used %lld asks\n",debug);
#endif
}
inline void solve()
{
#ifndef ONLINE_JUDGE
	read(M),debug=0;
#endif
	ll l=1,r=1e14,rs=0;P=1;if(!Ask(1)) return Ans(0);
	for(ll tp=0,v=1;(0^v^0);) if(Ask(tp=P)) l=tp;else {r=tp-1;break;}
	Ask(l);int k=1,w=(P>=r);while(dp[k][w]<=r-l) k++;
	while(l<=r)
	{
		while(r-l>dp[k][w]) Ask(l-1),w++;
		ll md=l+(w?dp[k-1][w-1]:0);while(P<md) Ask(l-1);
		if(Ask(md)) k--,w++,l=md+1,rs=md;else r=md-1,k--,w--;
	}Ans(rs);
}
inline void init()
{
	for(int i=1;i<=50;i++) for(int j=0;j<=100;j++)
		dp[i][j]=(dp[i-1][j+1]+(j?dp[i-1][j-1]+1:0));
}
int main() {int Ca;for(init(),read(Ca);Ca--;) solve();return 0;}