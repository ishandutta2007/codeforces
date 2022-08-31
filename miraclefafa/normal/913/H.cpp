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
typedef vector<ll> poly;
typedef pair<int,int> PII;
const ll mod=998244353;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=40;
int n;
ll val[N],comb[N][N],inv[N];
double p[N];
map<int,poly> dp[N];
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) {
		scanf("%lf",p+i);
		val[i]=p[i]*1000000+0.1;
		inv[i]=powmod(i,mod-2);
	}
	dp[n][val[n]]=poly{0};
	dp[n][0]=poly{1};
	rep(i,0,n+1) {
		comb[i][0]=comb[i][i]=1;
		rep(j,1,i) comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%mod;
	}
	per(i,1,n) {
		vector<int> cand;
		for (auto p:dp[i+1]) cand.pb(p.fi),cand.pb(max(0,p.fi-1000000));
		cand.pb(val[i]);
		sort(all(cand));
		cand.erase(unique(all(cand)),cand.end());
		for (auto p:cand) {
			if (p==val[i]) {
				dp[i][p]=poly(n-i+1,0);
				break;
			} else {
				// Int dp[i+1][x] ~ dp[i+1][x+1]
				int x=p; int y=p+1000000;
				poly c=poly(n-i+1,0);
				for (auto it=dp[i+1].begin();it!=dp[i+1].end();it++) {
					auto nit=it; ++nit;
					int l=it->fi; int r=1<<30;
					auto pol=it->se;
					if (nit!=dp[i+1].end()) r=nit->fi;
					int vl=l*powmod(1000000,mod-2)%mod,vr=r*powmod(1000000,mod-2)%mod;
					if (x<l&&r<=y) {
						//puts("ty1");
						rep(j,0,SZ(pol)) c[0]=(c[0]+pol[j]*(powmod(vr,j+1)-powmod(vl,j+1))%mod*inv[j+1])%mod;
					} else if (r<=x||y<l) {
						//puts("ty2");
						continue;
					} else if (r<=y) {
//						puts("ty3");
						rep(j,0,SZ(pol))
							c[0]=(c[0]+pol[j]*powmod(vr,j+1)%mod*inv[j+1])%mod,
							c[j+1]=(c[j+1]-pol[j]*inv[j+1])%mod;
					} else if (x<l) {
//						puts("ty4");
						rep(j,0,SZ(pol)) {
							c[0]=(c[0]-pol[j]*powmod(vl,j+1)%mod*inv[j+1])%mod;
							ll coef=pol[j]*inv[j+1]%mod;
							rep(k,0,j+2) c[k]=(c[k]+coef*comb[j+1][k])%mod;
						}						
					} else {
//						puts("ty5");
						rep(j,0,SZ(pol)) {
							ll coef=pol[j]*inv[j+1]%mod;
							rep(k,0,j+2) c[k]=(c[k]+coef*comb[j+1][k])%mod;
							c[j+1]=(c[j+1]-coef)%mod;
						}
					}
				}
				dp[i][x]=c;
			}
		}
		dp[i+1].clear();
	}
	ll prob=0;
	for (auto it=dp[1].begin();it!=dp[1].end();it++) {
		auto nit=it; ++nit;
		int l=it->fi; int r=1<<30;
		auto pol=it->se;
		if (nit!=dp[1].end()) r=nit->fi; else break;
		if (l>=1000000) break; r=min(r,1000000);
		int vl=l*powmod(1000000,mod-2)%mod,vr=r*powmod(1000000,mod-2)%mod;
		rep(j,0,SZ(pol)) prob=(prob+pol[j]*(powmod(vr,j+1)-powmod(vl,j+1))%mod*inv[j+1])%mod;
	}
	if (prob<0) prob+=mod;
	printf("%lld\n",prob);
}