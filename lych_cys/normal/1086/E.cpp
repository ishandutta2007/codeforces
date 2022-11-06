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
#define mod 998244353
#define N 2009
using namespace std;

int n,now,b[N],c[2][N],a[N][N],dp[N][N],pw[N];
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
void ins(int *c,int x){
	for (; x<=n; x+=x&-x) c[x]++;
}
int getsum(int *c,int x){
	int ans=0; for (; x; x^=x&-x) ans+=c[x]; return ans;
}
void add(int x){
	if (!x) return;
	b[x]++;
	if (b[x]==2){ now++; ins(c[0],x); }	
}
int calc(int x,int y){
	//cerr<<x<<' '<<y<<'\n';
	if (y<0 || y>x) return 0; return dp[x][y];
}
int main(){
	scanf("%d",&n);
	int i,j;
	for (i=1; i<=n; i++)
		for (j=1; j<=n; j++) scanf("%d",&a[i][j]);
	for (i=dp[0][0]=1; i<=n; i++)
		for (j=0; j<=i; j++){
			if (j<=1) dp[i][j]=(ll)dp[i-1][max(0,j-1)]*(i-j)%mod;
			else dp[i][j]=((ll)dp[i-1][j-2]*(j-1)+(ll)dp[i-1][j-1]*(i-j))%mod;
			//cerr<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
		}
	for (i=pw[0]=1; i<=n; i++) pw[i]=(ll)pw[i-1]*dp[n][n]%mod;
	//for (i=1; i<=n; i++) cerr<<i<<' '<<dp[i][i]<<'\n';
	int ans=0;
	for (i=1; i<=n; i++){
		memset(b,0,sizeof(b)); memset(c,0,sizeof(c)); now=0;
		for (j=n; j; j--){
			add(a[i-1][j]); add(a[i][j]);
			ins(c[1],a[i][j]);
			int x=getsum(c[0],a[i][j]-1),y=getsum(c[1],a[i][j]-1)-x;
			//cerr<<i<<' '<<j<<' '<<x<<' '<<y<<' '<<now<<'\n';
			ad(ans,(ll)pw[n-i]*calc(n-j,now-(b[a[i-1][j]]==2)-1)%mod*x);
			//cerr<<ans<<'\n';
			//cerr<<pw[n-i]<<'\n';
			ad(ans,(ll)pw[n-i]*calc(n-j,now-(b[a[i-1][j]]==2))%mod*y);
			if (b[a[i-1][j]]==2 && a[i-1][j] && a[i-1][j]<a[i][j])
				ad(ans,(ll)(mod-pw[n-i])*calc(n-j,now-2));
		}
	}
	printf("%d\n",ans);
	return 0;
}