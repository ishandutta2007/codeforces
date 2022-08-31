#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=410;
int n,m,cnt[N];
int g[N][N];
VI e[N];
int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) rep(j,1,n+1) {
		g[i][j]=(i==j)?0:n+1;
	}
	rep(i,0,m) {
		int a,b;
		scanf("%d%d",&a,&b);
		g[a][b]=g[b][a]=1;
		e[a].pb(b); e[b].pb(a);
	}
	rep(k,1,n+1) {
		rep(i,1,n+1) rep(j,1,n+1) g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	}
	rep(i,1,n+1) rep(j,1,n+1) {
		int d=g[i][j];
		rep(k,0,d+1) cnt[k]=0;
		rep(k,1,n+1) if (g[i][k]+g[k][j]==d) cnt[g[i][k]]++;
		ll ans=1;
		rep(k,0,d+1) if (cnt[k]!=1) ans=0;
		//printf("vvv %d %d %lld\n",i,j,ans);
		if (ans) {
			rep(k,1,n+1) if (g[i][k]+g[k][j]!=d) {
				int cnt=0;
				for (auto v:e[k]) if (g[i][v]==g[i][k]-1&&g[j][v]==g[j][k]-1) {
					cnt+=1;
				}
				//printf("zz %d %d\n",k,cnt);
				ans=ans*cnt%mod;
			}
		}
		printf("%lld%c",ans," \n"[j==n]);
	}
}