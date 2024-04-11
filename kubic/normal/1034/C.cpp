#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define LIM 1000005
#define MOD 1000000007
#define ll long long
#define pb push_back
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
char *P1,*P2,buf[LIM];
int n,ans,w[N],dp[N];ll s[N];vector<int> e[N];
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+c-48,c=gc();return res;
}
int add(int x,int y) {x+=y;return x<MOD?x:x-MOD;}
ll gcd(ll x,ll y) {return y?gcd(y,x%y):x;}
void dfs(int u,int f) {for(auto v:e[u]) dfs(v,u),s[u]+=s[v];}
int main()
{
	n=rd();dp[1]=1;for(int i=1;i<=n;++i) s[i]=rd();
	for(int i=2,f;i<=n;++i) f=rd(),e[f].pb(i);dfs(1,0);
	for(int i=1;i<=n;++i) {ll t=s[1]/gcd(s[i],s[1]);if(t<=n) ++w[t];}
	for(int i=n;i;--i) for(int j=i*2;j<=n;j+=i) w[j]+=w[i];
	for(int i=1;i<=n;++i) if(w[i]>=i) for(int j=i*2;j<=n;j+=i)
		if(w[j]>=j) dp[j]=add(dp[i],dp[j]);
	for(int i=1;i<=n;++i) if(w[i]>=i) ans=add(ans,dp[i]);
	printf("%d\n",ans);return 0;
}