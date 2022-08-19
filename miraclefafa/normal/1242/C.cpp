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
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=16;
int k;
ll s,sm[N];
VI v[N];
PII pr[N][5010];
vector<PII> way[(1<<N)+10];
int pre[(1<<N)+10];
bool dp[(1<<N)+10],mask[(1<<N)+10];
map<ll,PII> hs;
PII sol[N];

int main() {
	scanf("%d",&k);
	for (int i=0;i<k;i++) {
		int x;
		scanf("%d",&x);
		v[i].resize(x);
		rep(j,0,x) {
			scanf("%d",&v[i][j]);
			s+=v[i][j];
			sm[i]+=v[i][j];
			hs[v[i][j]]=mp(i,j);
		}
	}
	if (s%k!=0) {
		puts("No");
		return 0;
	}
	ll z=s/k;
	rep(i,0,k) rep(j,0,SZ(v[i])) {
		pr[i][j]=hs.count(z-(sm[i]-v[i][j]))?hs[z-(sm[i]-v[i][j])]:mp(-1,-1);
	}
	rep(i,0,k) rep(j,0,SZ(v[i])) {
		auto fz=mp(i,j);
		vector<PII> cyc;
		set<int> ds;
		int msk=0;
		while (1) {
			cyc.pb(fz);
			ds.insert(fz.fi);
			msk|=1<<fz.fi;
			fz=pr[fz.fi][fz.se];
			if (fz==mp(-1,-1)) break;
			if (ds.count(fz.fi)) {
				if (fz!=mp(i,j)) fz=mp(-1,-1);
				break;
			}
		}
		if (fz==mp(-1,-1)) continue;
//		printf("gg %d %d\n",i,j);
//		for (auto p:cyc) printf("%d ",v[p.fi][p.se]); puts("");
		way[msk]=cyc;
		mask[msk]=1;
	}
	dp[0]=1;
	rep(S,1,(1<<k)) {
		int nS=S;
		while (nS) {
			if (mask[nS]&&dp[S^nS]) {
				dp[S]=1;
				pre[S]=nS;
				break;
			}
			nS=(nS-1)&S;
		}
	}
	if (!dp[(1<<k)-1]) {
		puts("No");
		return 0;
	}
	int S=(1<<k)-1;
	while (S) {
		vector<PII> c=way[pre[S]];
		//printf("gg %d %d\n",S,pre[S]);
		rep(i,0,SZ(c)) {
			//printf("zz %d %d\n",c[i].fi,c[i].se);
			sol[c[i].fi]=mp(v[c[i].fi][c[i].se],c[(i+SZ(c)-1)%SZ(c)].fi);
		}
		S^=pre[S];
	}
	puts("Yes");
	rep(i,0,k) printf("%d %d\n",sol[i].fi,sol[i].se+1);
}