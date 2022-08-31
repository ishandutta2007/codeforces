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
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

vector<array<int,3>> dp[40];

struct Hash_table {
	static const int V=10000003;
	int fst[V],nxt[V];
	int ctm,ptm[V],T;
	ll key[V];
	void init() { T=0; ctm++;}
	bool insert(ll s) {
		int S=s%V;
		if (ptm[S]!=ctm) ptm[S]=ctm,fst[S]=-1;
		for (int j=fst[S];j!=-1;j=nxt[j]) if (key[j]==s) {
			return 0;
		}
		nxt[T]=fst[S],fst[S]=T,key[T]=s;
		T++;
		return 1;
	}
}Hash;

int n;
db x,y;

string construct(int i,array<int,3> p) {
	if (i==0) return "";
	//printf("%d %d %d %d\n",i,p[0],p[1],p[2]);
	for (auto p1:dp[i-1]) if (array<int,3>{p1[0]+p1[2]+(2*i-1)*i,p1[1]+3*p1[2]+3*(i-1)+1,p1[2]+2*i-1}==p) {
		return "("+construct(i-1,p1)+")";
	}
	for (int j=1;j<i;j++) {
		for (auto p1:dp[j]) for (auto p2:dp[i-j]) {
			if (array<int,3>{p1[0]+j*2*p2[2]+p2[0],p1[1]+p2[1],p1[2]+p2[2]}==p) {
				return construct(j,p1)+construct(i-j,p2);
			}
		}
	}
	assert(0);
}

int main() {
	dp[0].pb({0,0,0});
	for (int i=1;i<=18;i++) {
		int s=0;
		Hash.init();
		auto add=[&](array<int,3> val) {
			ll key=val[0]*(1ll<<40)+val[1]*(1ll<<20)+val[2];
			if (Hash.insert(key)) dp[i].pb(val);
		};
		for (int j=1;j<i;j++) {
			for (auto p1:dp[j]) for (auto p2:dp[i-j]) {
				add({p1[0]+j*2*p2[2]+p2[0],p1[1]+p2[1],p1[2]+p2[2]});
			}
			s+=SZ(dp[j])*SZ(dp[i-j]);
			//printf("%d %d\n",j,dp[i].size());
		}
		for (auto p1:dp[i-1]) {
			add({p1[0]+p1[2]+(2*i-1)*i,p1[1]+3*p1[2]+3*(i-1)+1,p1[2]+2*i-1});
		}
		s+=SZ(dp[i-1]);
		//printf("%d %d %d\n",i,SZ(dp[i]),s);
	}
	scanf("%d%lf%lf",&n,&x,&y);
	for (auto p:dp[n/2]) {
		db a=1.*p[0]/p[2],b=1./3*p[1]/p[2];
		if (fabs(a-x)+fabs(b-y)<=1e-8) {
			printf("%s\n",construct(n/2,p).c_str());
			return 0;
		}
	}
}