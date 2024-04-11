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
typedef long long ll;
typedef vector<ll> VI;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int M=100;
const ll inf=1ll<<60;
int x,k,n,q,cur,m,p,w,ed;
int st[400],ps[400],c[100];
ll cost[M][M],g[40][M][M];
map<int,VI> dp;
map<int,int> hs;
int cc[10];
vector<PII> e;
void jumpto(int x) {
	x=min(x,ed);
	if (cur>=x) return;
	VI p=dp[cur];
	int d=x-cur;
	per(k,0,30) if (d&(1<<k)) {
		VI q(m,inf);
		rep(i,0,m) rep(j,0,m) q[j]=min(q[j],p[i]+g[k][i][j]);
		p=q;
	}
	dp[x]=p;
	cur=x;
}
void moveto(int x) {
	x=min(x,ed);
	if (cur>=x) return;
	VI p=dp[cur];
	rep(y,cur,x) {
		VI q(m,inf);
		rep(j,1,k+1) if (hs.count(y+j)) cc[j]=hs[y+j]; else cc[j]=0;
		rep(i,0,m) {
			int S=st[i];
			if (S%2==0) q[ps[S>>1]]=min(q[ps[S>>1]],p[i]);
			else {
				rep(j,1,k+1) {
					S=st[i]^1; int cs=c[j]+cc[j];
					if ((S&(1<<j))==0) {
						S|=(1<<j); S>>=1;
						q[ps[S]]=min(q[ps[S]],p[i]+cs);
					}
				}
			}
		}
		p=q;
	}
	dp[x]=p;
	cur=x;
}
int main() {
	scanf("%d%d%d%d",&x,&k,&n,&q);
	rep(S,0,(1<<k)) if (__builtin_popcount(S)==x) st[ps[S]=m++]=S;
	rep(i,1,k+1) scanf("%d",c+i);
	rep(i,0,m) rep(j,0,m) cost[i][j]=inf;
	rep(i,0,m) {
		if (st[i]%2==0) cost[i][ps[st[i]>>1]]=0;
		else rep(j,1,k+1) {
			int S=st[i]; S^=1;
			if ((S&(1<<j))==0) {
				S|=(1<<j); S>>=1;
				cost[i][ps[S]]=c[j];
			}
		}
	}
	ed=n-x+1;
	rep(it,0,30) {
		if (it==0) {
			rep(i,0,m) rep(j,0,m) g[it][i][j]=cost[i][j];
		} else {
			rep(i,0,m) rep(j,0,m) g[it][i][j]=inf;
			rep(k,0,m) {
				rep(i,0,m) rep(j,0,m) rep(k,0,m) g[it][i][j]=min(g[it][i][j],g[it-1][i][k]+g[it-1][k][j]);
			}
		}
	}
	rep(i,0,q) {
		scanf("%d%d",&p,&w); e.pb(mp(p,w));
		hs[p]=w;
	}
	sort(all(e));
	dp[1]=VI(m,inf); dp[1][0]=0;
	cur=1;
	rep(i,0,q) {
		jumpto(e[i].fi-k);
		moveto(e[i].fi+1);
	}
	jumpto(n-x+1);
	printf("%lld\n",dp[n-x+1][0]);
}