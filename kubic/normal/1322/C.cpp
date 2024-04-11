#include <bits/stdc++.h>
using namespace std;
#define N 500005
#define ll long long
#define ull unsigned long long
mt19937_64 rand1(time(0));
int T,n,m;ll ans,a[N];ull w1[N],w[N];map<ull,ll> s;
ll gcd(ll x,ll y) {return y?gcd(y,x%y):x;}
void slv()
{
	scanf("%d %d",&n,&m);ans=0;s.clear();
	for(int i=1;i<=n;++i)
		w[i]=0,w1[i]=rand1(),scanf("%lld",&a[i]);
	for(int i=1,u,v;i<=m;++i)
		scanf("%d %d",&u,&v),w[v]^=w1[u];
	for(int i=1;i<=n;++i)  s[w[i]]+=a[i];
	for(auto i:s) if(i.first) ans=gcd(ans,i.second);
	printf("%lld\n",ans);
}
int main() {scanf("%d",&T);while(T--) slv();}