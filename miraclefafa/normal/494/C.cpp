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


bool cmp(const pair<int,pair<int,double> > &a,const pair<int,pair<int,double> > &b) {
	if (a.fi!=b.fi) return a.fi<b.fi;
	else return a.se.fi>b.se.fi;
}
const int N=101000,M=5010;
int n,m,a[N],mv[N];
double dp[M][M];
VI ins;
pair<int,pair<int,double> > p[M];
multiset<PII> hs;
int query(int l,int r) { if (l<=r) return *max_element(a+l,a+r+1); else return 0;}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,n) scanf("%d",a+i);
	rep(i,0,m) scanf("%d%d%lf",&p[i].fi,&p[i].se.fi,&p[i].se.se),--p[i].fi,--p[i].se.fi;
	p[m++]=mp(0,mp(n,0));
	sort(p,p+m,cmp);
	per(i,0,m) {
		ins.clear();
		mv[i]=0;
		while (!hs.empty()&&hs.begin()->fi<=p[i].se.fi) {
			ins.pb(hs.begin()->se);
			hs.erase(hs.begin());
		}
		hs.insert(mp(p[i].se.fi,i));

		for (auto id:ins) mv[i]=max(mv[i],mv[id]);
		
		if (SZ(ins)) {
			mv[i]=max(mv[i],query(p[i].fi,p[ins[0]].fi-1));
			rep(j,0,SZ(ins)-1) mv[i]=max(mv[i],query(p[ins[j]].se.fi+1,p[ins[j+1]].fi-1));
			mv[i]=max(mv[i],query(p[ins.back()].se.fi+1,p[i].se.fi));
		} else {
			mv[i]=max(mv[i],query(p[i].fi,p[i].se.fi));
		}
//		printf("%d %d %d\n",p[i].fi,p[i].se.fi,mv[i]);
		rep(j,0,m+1) dp[i][j]=1;
		for (auto id:ins) rep(j,0,m) if (mv[id]+j>=mv[i]) dp[i][mv[id]+j-mv[i]]*=dp[id][j];
		per(j,0,m+1) {
			dp[i][j]=dp[i][j]*(1-p[i].se.se);
			if (j) dp[i][j]+=(dp[i][j-1]*p[i].se.se);
		}
//		rep(j,0,m+1) printf("%.10f  ",dp[i][j]);
//		puts("");
	}
	double ret;
	rep(j,0,m+1) ret+=1-dp[0][j];
	printf("%.10f\n",ret+mv[0]);
}