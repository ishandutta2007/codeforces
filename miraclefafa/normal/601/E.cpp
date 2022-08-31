#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
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
const ll mod=1000000007,P=10000000+19;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=30100;
int dp[30][N];
int n,k,st[N],ed[N],ty,it,qur[N],q;
PII p[N];
VI ps;
void query(int d,int l,int r,VI item) {
	rep(i,0,k+1) dp[d][i]=dp[d-1][i];
//	printf("L R %d %d\n",l,r);
//	rep(j,0,SZ(item)) printf("%d ",item[j]); puts("");
	rep(j,0,SZ(item)) if (st[item[j]]<=l&&ed[item[j]]>=r) {
//		printf("Add %d\n",item[j]);
		int v=p[item[j]].fi,w=p[item[j]].se;
		per(i,0,k+1) {
			if (i>=w) dp[d][i]=max(dp[d][i],dp[d][i-w]+v);
		}
	}
	if (l==r) {
		ll ret=0;
	//	rep(i,1,k+1) printf("%d ",dp[d][i]); puts("");
		per(i,1,k+1) ret=(ret*P+dp[d][i])%mod;
		rep(j,0,qur[l]) printf("%d\n",(int)ret);
	} else {
		int md=(l+r)>>1;
		VI lt,rt;
		rep(j,0,SZ(item)) {
			if (st[item[j]]<=l&&ed[item[j]]>=r) continue;
			if (ed[item[j]]<=md) lt.pb(item[j]);//,printf("LL %d\n",item[j]);
			else if (st[item[j]]>md) rt.pb(item[j]);//,printf("RR %d\n",item[j]);
			else lt.pb(item[j]),rt.pb(item[j]);//,printf("LR %d\n",item[j]);
		}
		query(d+1,l,md,lt);
		query(d+1,md+1,r,rt);
	}
}
int main() {
//	freopen("in","r",stdin);
	scanf("%d%d",&n,&k);
	rep(i,1,n+1) scanf("%d%d",&p[i].fi,&p[i].se),st[i]=1;
	scanf("%d",&q);
	int cur=1,im=n;
	rep(i,0,q) {
		scanf("%d",&ty);
		if (ty==3) {
			qur[cur]++;
		} else if (ty==2) {
			scanf("%d",&it);
			ed[it]=cur++;
		} else {
			im++;
			scanf("%d%d",&p[im].fi,&p[im].se);
			st[im]=++cur;
		}
	}
	rep(i,1,im+1) ps.pb(i);
	rep(i,1,im+1) if (ed[i]==0) ed[i]=cur;
//	rep(i,1,im+1) printf("%d %d %d\n",i,st[i],ed[i]);
	query(1,1,cur,ps);
}