#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define M 1<<11
#define LIM 1000005
#define ll long long
#define pb push_back
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
const ll INF=1e18;char *P1,*P2,buf[LIM];
int n,tp,lg[M],cnt1[M];ll m,d,ans=INF,p[N],s1[12],s[M],dp[12][M];
vector<int> vc[M];map<ll,int> cnt;struct Node {int w;ll x;}a[N],a1[N];
bool cmp(Node x,Node y) {return x.w<y.w;}
void W(ll &x,ll y) {x=min(x,y);}
ll gcd(ll x,ll y) {return y?gcd(y,x%y):x;}
ll rd()
{
	ll res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+c-48,c=gc();return res;
}
int main()
{
	n=rd();m=rd();for(int i=1;i<=n;++i) a1[i].x=rd(),d=gcd(d,a1[i].x);
	for(int i=2;1ll*i*i<=d;++i) if(!(d%i)) {p[++p[0]]=i;while(!(d%i)) d/=i;}
	if(d>1) p[++p[0]]=d;for(int i=2;i<1<<p[0];++i) lg[i]=lg[i/2]+1;
	for(int i=1;i<=n;++i)
	{ll t=a1[i].x;for(int j=1;j<=p[0];++j) while(!(t%p[j])) t/=p[j];a1[i].x/=t;}
	for(int i=1;i<=n;++i) a1[i].w=rd();sort(a1+1,a1+n+1,cmp);
	for(int i=1;i<=n;++i) if(cnt[a1[i].x]<p[0]) ++cnt[a1[i].x],a[++tp]=a1[i];
	for(int i=0;i<=p[0];++i) for(int j=0;j<1<<p[0];++j) dp[i][j]=INF;dp[0][0]=0;
	for(int i=1;i<=tp;++i)
	{
		s[0]=1;for(int j=1;j<=p[0];++j) s1[j]=1;
		for(int j=1;j<=p[0];++j) while(!(a[i].x%p[j])) a[i].x/=p[j],s1[j]*=p[j];
		for(int j=1;j<1<<p[0];++j) vc[j].clear();
		for(int j=1;j<1<<p[0];++j)
		{
			s[j]=s[j&j-1]*s1[lg[j&-j]+1];if(s[j]>m || cnt1[j]>=p[0]) continue;
			for(int k=j^(1<<p[0])-1;k;k=(k-1)&(j^(1<<p[0])-1)) vc[j|k].pb(j);
			vc[j].pb(j);++cnt1[j];
		}
		for(int j=p[0];j;--j) for(int k=1;k<1<<p[0];++k) for(auto l:vc[k])
			W(dp[j][k],dp[j-1][k^l]+a[i].w);
	}for(int i=0;i<=p[0];++i) {ll t=dp[i][(1<<p[0])-1];if(t<INF) W(ans,t*i);}
	if(ans<INF) printf("%lld\n",ans);else puts("-1");return 0;
}