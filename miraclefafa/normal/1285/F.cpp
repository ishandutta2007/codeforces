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

const int N=101000,M=100000;
int n,x,cnt[N],mu[N],cc[N];
VI d[N];
bool check(ll z,vector<bool> c) { // >=z
	int n=SZ(c)-1;
	ll p=z;
	for (int i=1;i<=n;i++) cc[i]=0;
	for (ll i=p;i<=n;i++) if (c[i]) {
		for (auto j:d[i]) cc[j]+=mu[j];
	}
	for (int w=1;w<=n;w++) {
		ll q=(z+w-1)/w;
		for (ll i=q;i<=n&&i<p;i++) if (c[i]) 
			for (auto j:d[i]) cc[j]+=mu[j];
		p=q;
		if (c[w]) {
			int zz=0;
			for (auto j:d[w]) zz+=cc[j];
			if (zz>0) return 1;
		}
	}
	return 0;
}

int main() {
	scanf("%d",&n);
	for (int i=1;i<=M;i++) for (int j=i;j<=M;j+=i)
		d[j].pb(i);
	for (int i=1;i<=n;i++) scanf("%d",&x),cnt[x]=1;
	mu[1]=1;
	for (int i=2;i<=M;i++) for (auto j:d[i]) if (j!=i) mu[i]-=mu[j];
	ll ret=1;
	for (int z=1;z<=M;z++) {
		vector<bool> p(M/z+1,0);
		for (int i=1;i<=M/z;i++) p[i]=cnt[i*z];
		if (check(ret/z+1,p)) {
			ll l=ret/z+1,r=(ll)(M/z)*(M/z)+1;
			while (l+1<r) {
				ll md=(l+r)>>1;
				if (check(md,p)) l=md; else r=md;
			}
			//printf("%d %lld\n",z,l);
			ret=l*z;
		}
	}
	printf("%lld\n",ret);
}