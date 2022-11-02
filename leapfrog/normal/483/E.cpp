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
long double rs=0,dp[(1<<20)+5];ll wk[(1<<20)+5];
int n,m,vl[55],stp[(1<<20)+5],vs[(1<<20)+5];char ch[55][25];
inline void solve(int wh)
{
	for(int i=1;i<=n;i++) if(i==wh) vl[i]=(1<<m)-1;else
		{vl[i]=0;for(int j=1;j<=m;j++) vl[i]|=(ch[i][j]!=ch[wh][j])<<(j-1);}
	for(int i=1;i<=n;i++) wk[vl[i]^((1<<m)-1)]|=(1ll<<(wh-1));
	//printf("! %d\n",wh);for(int i=1;i<=n;i++) printf("%d%c",vl[i],i==n?'\n':' ');
}
/*inline long double work(int S)
{
	if(v[S]==id) return dp[S];else v[S]=id,dp[S]=0;
	char fg=0;for(int i=1;i<=n;i++) if(!(S&vl[i])) fg=1;
	int cnt=0;if(!fg) return dp[S]=0.0;
	for(int i=0;i<m;i++) if(!((S>>i)&1)) cnt++,dp[S]+=work(S|(1<<i))+1;
	return dp[S]/=cnt;
}*/
inline long double dfs(int S)
{
	int cnt=0;if(stp[S]==n) return dp[S]=0;else if(vs[S]) return dp[S];else vs[S]=1;
	for(int i=0;i<m;i++) if(!((S>>i)&1)) cnt++,dp[S]+=dfs(S|(1<<i))+(n-stp[S]);
	return dp[S]/=cnt;
}
int main()
{
	read(n);if(n==1) return puts("0.000000000000000"),0;
	for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	m=strlen(ch[1]+1);for(int i=1;i<=n;i++) solve(i);
	//for(int i=0;i<(1<<m);i++) printf("%d%c",stp[i],i==(1<<m)-1?'\n':' ');
	//for(int i=0;i<(1<<m);i++) printf("%lld%c",wk[i],i==(1<<m)-1?'\n':' ');
	for(int i=0;i<m;i++) for(int d=(1<<m)-1;~d;d--) if((d>>i)&1) wk[d^(1<<i)]|=wk[d];
	//for(int i=0;i<(1<<m);i++) printf("%lld%c",wk[i],i==(1<<m)-1?'\n':' ');
	for(int i=0;i<(1<<m);i++) {stp[i]=n;for(int j=0;j<n;j++) stp[i]-=(wk[i]>>j)&1;}
	//for(int i=0;i<(1<<m);i++) printf("%d%c",stp[i],i==(1<<m)-1?'\n':' ');
	return printf("%.15Lf\n",dfs(0)/n),0;
}