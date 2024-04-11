#include <bits/stdc++.h>
using namespace std;
#define N 4005
#define MOD 998244353
#define pb push_back
#define pct __builtin_popcount
int n,m;char a[N][N];
void W(int &x,int y) {x+=y;if(x>=MOD) x-=MOD;}
int add(int x,int y) {x+=y;return x<MOD?x:x-MOD;}
int qPow(int x,int y)
{
	int res=1;
	for(;y;y/=2,x=1ll*x*x%MOD) if(y&1)
		res=1ll*res*x%MOD;return res;
}
namespace Sub1
{
	int t;
	void slv()
	{
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j) t+=a[i][j]=='?';
		printf("%d\n",qPow(2,t));
	}
}
namespace Sub2
{
	int t,fl,cnt[N],w[N];
	void slv()
	{
		for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
			if(a[i][j]=='?') ++cnt[i];
			else w[i]^=a[i][j]-48;
		for(int i=1;i<=n;++i) if(cnt[i]) t+=cnt[i]-1;
		for(int i=1;i<=n;++i) if(!cnt[i]) fl|=1<<w[i];
		printf("%lld\n",1ll*qPow(2,t)*(2-pct(fl))%MOD);
	}
}
namespace Sub3
{
	int t,fl,cnt[N],w[N];
	void slv()
	{
		for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
			if(a[i][j]=='?') ++cnt[j];
			else w[j]^=a[i][j]-48;
		for(int i=1;i<=m;++i) if(cnt[i]) t+=cnt[i]-1;
		for(int i=1;i<=m;++i) if(!cnt[i]) fl|=1<<w[i];
		printf("%lld\n",1ll*qPow(2,t)*(2-pct(fl))%MOD);
	}
}
namespace Sub4
{
	int t,fl,w[N];bool vs[N];vector<int> e[N];
	int dfs(int u)
	{
		if(vs[u]) return 0;vs[u]=1;int res=w[u];
		for(auto v:e[u]) res^=dfs(v);return res;
	}
	void slv()
	{
		t=-n-m;
		for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
			if(a[i][j]=='?') ++t,e[i].pb(n+j),e[n+j].pb(i);
			else w[i]^=a[i][j]-48,w[n+j]^=a[i][j]-48;
		for(int i=1;i<=n+m;++i) if(!vs[i]) fl|=dfs(i),++t;
		for(int i=1;i<=n+m;++i) vs[i]=0,w[i]^=1;
		for(int i=1;i<=n+m;++i) if(!vs[i]) fl|=dfs(i)*2;
		printf("%lld\n",1ll*qPow(2,t)*(2-pct(fl))%MOD);
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%s",a[i]+1);
	if(!(n&1) && !(m&1)) Sub1::slv();
	if(!(n&1) && m&1) Sub2::slv();
	if(n&1 && !(m&1)) Sub3::slv();
	if(n&1 && m&1) Sub4::slv();return 0;
}