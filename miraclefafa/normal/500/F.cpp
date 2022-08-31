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

const int N=20100,M=4010;
int dp[10100][M],pd[M];
int n,p,grop,q,c[N],h[N],t[N],a[N],b[N],ret[N];
VI evt[N],qc[N];
vector<PII> rc[N],pc[N],qr[N];
void gao(vector<PII> &a) {
	rep(i,0,p+1) evt[i].clear();
	rep(i,0,SZ(a)) evt[p+1-a[i].fi].pb(a[i].se);
	rep(i,0,4001) dp[0][i]=0;
	rep(i,1,p+1) {
		rep(j,0,4001) dp[i][j]=dp[i-1][j];
		rep(j,0,SZ(evt[i])) {
			int cs=c[evt[i][j]],ch=h[evt[i][j]];
			per(k,cs,4001) dp[i][k]=max(dp[i][k-cs]+ch,dp[i][k]);
		}
	}
}
void gaoo(vector<PII> &a) {
	rep(i,0,p+1) evt[i].clear();
	rep(i,0,SZ(a)) evt[p+1-a[i].fi].pb(a[i].se);
	rep(i,0,4001) pd[i]=0;
	rep(i,1,p+1) {
		rep(j,0,SZ(evt[i])) {
			int cs=c[evt[i][j]],ch=h[evt[i][j]];
			per(k,cs,4001) pd[k]=max(pd[k-cs]+ch,pd[k]);
		}
		rep(j,0,SZ(qr[i])) {
			int id=qr[i][j].se,ct=qr[i][j].fi;
			rep(k,0,b[id]+1) ret[id]=max(ret[id],dp[ct][k]+pd[b[id]-k]);
		}
	}
}

int main() {
	scanf("%d%d",&n,&p);
	grop=0;
	rep(i,0,n) {
		scanf("%d%d%d",c+i,h+i,t+i);
		if (t[i]%p==0) pc[t[i]/p-1].pb(mp(p,i));
		else pc[t[i]/p].pb(mp(t[i]%p,i)),rc[t[i]/p].pb(mp(p-t[i]%p,i));
		grop=max(grop,t[i]/p+2);
	}
	scanf("%d",&q);
	rep(i,0,q) {
		scanf("%d%d",a+i,b+i);
		qc[a[i]/p].pb(i);
	}
	rep(i,0,grop) {
		if (i) gao(pc[i-1]);
		rep(j,0,p+1) qr[j].clear();
		rep(j,0,SZ(qc[i])) {
			int id=qc[i][j],ct=p-a[id]%p,rt=a[id]%p+1;
			qr[rt].pb(mp(ct,id));
		}
		gaoo(rc[i]);
	}
	rep(i,0,q) printf("%d\n",ret[i]);
}