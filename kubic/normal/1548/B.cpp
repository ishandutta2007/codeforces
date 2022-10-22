#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long
int T,n,ans;ll w[18][N];
ll gcd(ll x,ll y) {return y?gcd(y,x%y):x;}
int slv1(int x)
{
	ll nw=0,t;
	for(int i=17;i>=0;--i) if(x+(1<<i)-1<=n)
	{t=gcd(nw,w[i][x]);if(t>1 || !t) nw=t,x+=1<<i;}return x;
}
void slv()
{
	scanf("%d",&n);ans=1;
	for(int i=1;i<=n;++i) scanf("%lld",&w[0][i]);--n;
	for(int i=1;i<=n;++i) w[0][i]=abs(w[0][i]-w[0][i+1]);
	for(int i=1;i<=17;++i) for(int j=1;j+(1<<i)-1<=n;++j)
		w[i][j]=gcd(w[i-1][j],w[i-1][j+(1<<i-1)]);
	for(int i=1;i<=n;++i)
		ans=max(ans,slv1(i)-i+1);printf("%d\n",ans);
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0; 
}