#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define infll 1000000000000000000ll
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
#define N 209
using namespace std;

int cnt,len,n,m,pt,gen[N],p[N],b[30009]; ll l,r,ans,dp[N][N]; map<ll,int> mp;
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
ll readll(){
	ll x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
int calc(ll x){
	if (mp[x]) return mp[x]; mp[x]=++pt;
	//cerr<<x<<'\n';
	//x++;
	static int p[N]; static ll f[N][N][2];
	int len=0;
	for (; x; x/=cnt) p[++len]=x%cnt;
	memset(f,0,sizeof(f)); f[0][0][1]=1;
	int i,j,k,l;
	for (i=1; i<=len; i++)
		for (j=0; j<m; j++)
			for (k=0; k<2; k++)
				for (l=0; l<=(k?cnt-1:p[i]); l++)
					f[i][(j+gen[l])%m][k]+=f[i-1][j][k|(l<p[i])];
	for (i=0; i<m; i++) dp[pt][i]=f[len][i][0];
//	for (i=0; i<m; i++) cerr<<f[len][i][0]<<' ';cerr<<'\n';
	return pt;
}
void work(vll f,int k,bool flag){
	//for (ll x:f) cerr<<x<<' ';cerr<<'\n';
	//cerr<<k<<' '<<flag<<'\n';
	int i;
	//cerr<<f.size()<<'\n';
	if (f.size()==1){
		if (f[0]){
			ll tmp=0;
			//cerr<<f[0]<<'\n';
			for (i=len; i>=k; i--) tmp=tmp*cnt+p[i];
			//cerr<<ans<<'\n';
			int now=calc(tmp+flag);
			//cerr<<tmp+flag<<' '<<ans<<'\n';
			for (i=0; i<m; i++) if (f[0]>>i&1) ans+=dp[now][i];
			//cerr<<"ans:"<<ans<<'\n';
		}
		return;
	}
	if (k>len && !flag) return;
	vll g;
	for (i=0; i<cnt; i++){
		g.clear();
		int j=i; ll now=(1ll<<m)-1;
		for (ll x:f){
		//	cerr<<"cnt:"<<cnt<<'\n';
			ll y=x>>gen[j]|(x&(1ll<<gen[j])-1)<<m-gen[j];
		//	cerr<<x<<"->"<<gen[j]<<' '<<y<<'\n';
			if (!j) now=y; else now&=y;
			j=(j+1)%cnt;
			if (!j){ g.pb(now); now=-1; }
		}
		if (now!=-1) g.pb(now);
		//for (ll x: f) cerr<<x<<' ';cerr<<'\n'; cerr<<i<<'\n';
		//for (ll x: g) cerr<<x<<' ';cerr<<'\n';
		//cerr<<'\n';
		work(g,k+1,i==p[k]?flag:i<p[k]);
	}
}
void solve(ll t){
	int i; len=0;
	for (; t; t/=cnt) p[++len]=t%cnt;
	vll f; f.clear();
	for (i=1; i<=n; i++) f.pb((1ll<<b[i]+1)-1);
	work(f,1,0);
}
int main(){
	scanf("%d%d",&cnt,&m);
	int i;
	for (i=0; i<cnt; i++) scanf("%d",&gen[i]);
	scanf("%d",&n);
	for (i=1; i<=n; i++) scanf("%d",&b[i]);
	scanf("%lld%lld",&l,&r); r-=n-1;
	if (l>r){ puts("0"); return 0; }
	//r++;
	ll t=0;
	solve(r); t+=ans; ans=0;
	solve(l-1); t-=ans;
	printf("%lld\n",t);
	return 0;
}