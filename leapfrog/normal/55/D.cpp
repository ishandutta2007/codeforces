#include<bits/stdc++.h>
using namespace std;
const int P=2520;long long l,r,dp[25][2525][55];int T,cnt=0,tot=0,a[25],xd[25],t[2525],pw[25];
inline int gcd(int a,int b) {return a&&b?gcd(b,a%b):a+b;}
inline void A(int x) {xd[++tot]=x,t[x]=tot;}
inline int Q(int x,int q) {int r=1;for(;q;q>>=1,x*=x) if(q&1) r*=x;return r;}
inline long long dfs(int x,int s,int g,int lim,int zero)
{
	long long r=0;int ed;if(!lim&&!zero&&dp[x][s][t[g]]!=-1) return dp[x][s][t[g]];
	if(x==0) {if(s%g==0) return 1;else return 0;}else ed=lim?a[x]:9;
	for(int i=0;i<=ed;i++) r+=dfs(x-1,(s+i*pw[x-1])%P,i?(g*i/gcd(g,i)):g,lim&&i==ed,zero&&!i);
	if(!lim&&!zero) return dp[x][s][t[g]]=r;else return r;
}
inline long long solve(register long long x)
{
	for(cnt=0,memset(dp,-1,sizeof(dp));x;x/=10) a[++cnt]=x%10;
	return dfs(cnt,0,1,1,1);
}
signed main()
{
	for(T=1,pw[0]=1;T<=20;T++) pw[T]=pw[T-1]*10%P;
	for(int _2=0;_2<=3;_2++) for(int _3=0;_3<=2;_3++) for(int _5=0;_5<=1;_5++) for(int _7=0;_7<=1;_7++) A(Q(2,_2)*Q(3,_3)*Q(5,_5)*Q(7,_7));
	for(scanf("%d",&T);T--;) scanf("%lld%lld",&l,&r),printf("%lld\n",solve(r)-solve(l-1));
	return 0;
}