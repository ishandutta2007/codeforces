#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=310;
VI pos;
int n,m,a[N],l[N],pm[N],pl[N],pr[N];
ll dp[N][N][N],ans;
inline void upd(ll &a,ll b) { if (a<b) a=b;}
int main() {
//	freopen("E.in","r",stdin);
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d%d",a+i,l+i);
		pos.pb(a[i]); pos.pb(a[i]+l[i]); pos.pb(a[i]-l[i]);
	}
	sort(all(pos));
	pos.erase(unique(all(pos)),pos.end());
	rep(i,0,n) {
		pm[i]=lower_bound(all(pos),a[i])-pos.begin();
		pl[i]=lower_bound(all(pos),a[i]-l[i])-pos.begin();
		pr[i]=lower_bound(all(pos),a[i]+l[i])-pos.begin();
//		printf("%d %d %d %d\n",i,pm[i],pl[i],pr[i]);
	}
	m=SZ(pos);
	rep(i,0,m) rep(j,0,m) rep(k,0,m) dp[i][j][k]=-(1ll<<60);
	rep(k,0,m) dp[0][0][k]=0;
	rep(i,0,m-1) {
//		printf("%d\n",pos[i+1]-pos[i]);
		int ps=-1;
		rep(j,0,n) if (pm[j]==i) ps=j;
		rep(j,0,m) rep(k,0,m) if (dp[i][j][k]>=0) {
//			printf("%d %d %d %I64d\n",i,j,k,dp[i][j][k]);
			if (ps==-1) {
				upd(dp[i+1][j][k],dp[i][j][k]+(j>=i+1||k<=i?(pos[i+1]-pos[i]):0));
			} else {
				upd(dp[i+1][max(j,pr[ps])][k],dp[i][j][k]+pos[i+1]-pos[i]);
				if (k==pl[ps]) {
					rep(l,k,m) upd(dp[i+1][max(j,i)][l],dp[i][j][k]+((j>=i+1||l<=i)?(pos[i+1]-pos[i]):0));
				}
			}
		}
	}
	ans=0;
	rep(i,0,m) upd(ans,dp[m-1][i][m-1]);
	printf("%I64d\n",ans);
}