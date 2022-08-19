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

const int N=101000;
vector<PII> seg;
char s[N];
int n;
bool check(int g) {
	auto pseg=seg;
	rep(i,0,SZ(pseg)) pseg[i].fi-=g;
	VI ss;
	auto gao=[&](int v) {
		//printf("zz %d %d\n",v,g);
		if (v<=0) return 0;
		if (v==1) return 1;
		if (v==2) return 0;
		if (g==0) return 0;
		if (v==3) {
			ss.pb(1);
			return 1;
		}
		if (v==4) {
			if (g<=1) return 0;
			ss.pb(2);
			return 1;
		}
		if (g==1) {
			if (v%2!=1) return 0;
			rep(j,0,v/2) ss.pb(1);
			return 1;
		}
		if (v%2!=1) ss.pb(2),v-=3;
		rep(j,0,v/2) ss.pb(1);
		return 1;
	};
	if (!gao(pseg[0].fi)) return 0;
	ss.pb(pseg[0].se-pseg[0].fi+1);
	rep(i,1,SZ(pseg)) {
		int x=pseg[i].fi-pseg[i-1].se-1;
		if (!gao(x)) return 0;
		ss.pb(pseg[i].se-pseg[i].fi+1);
	}
	int x=n-pseg.back().se+1-g;
	//printf("xzz %d %d\n",g,x);
	if (!gao(x)) return 0;
	printf("%d\n",SZ(ss));
	for (auto p:ss) printf("%d ",p);
	puts("");
	exit(0);
	return 1;
}

int main() {
	scanf("%s",s);
	n=strlen(s);
	rep(i,0,n) if (s[i]=='#') {
		int r=i;
		while (r<n&&s[r]=='#') ++r;
		seg.pb(mp(i+1,r));
		i=r-1;
	}
	if (seg.empty()) {
		puts("0");
		return 0;
	}
	rep(v,0,5) check(v);
	puts("-1");
}