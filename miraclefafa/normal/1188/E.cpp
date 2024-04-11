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
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=1310000;
const int M=110000;

ll fac[N],fnv[N],inv[N],ans;
int n,a[M],cnt[M];

ll comb(int x,int y) {
	if (y<0||y>x) return 0;
	return fac[x]*fnv[y]%mod*fnv[x-y]%mod;	
}

void gao(int step) {
	rep(i,0,n) if (a[i]<step) cnt[a[i]]++;
	rep(i,1,step) cnt[i]+=cnt[i-1];
	ll ans=1;
	rep(i,1,step) {
		ans+=comb(i-cnt[i-1]+n-1,n-1);
	}
	printf("%lld\n",ans%mod);
}

int main() {
	fac[0]=fnv[0]=inv[0]=inv[1]=1;
	rep(i,1,1200001) {
		fac[i]=fac[i-1]*i%mod;
		if (i>=2) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
		fnv[i]=fnv[i-1]*inv[i]%mod;
	}
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a+i);
	sort(a,a+n);
	// 1,1,1
	rep(i,0,n-1) if (a[i+1]<=i) {
		gao(i+1);
		return 0;
	}
	int ext=0;
	rep(i,0,n) {
		ext+=a[i]/n;
		cnt[a[i]%n]++;
	}
	rep(i,0,n) {
		ans+=comb(ext+n-1,n-1);
//		printf("%d %lld\n",ext,comb(ext+n-1,n-1));
		ext++; ext-=cnt[i];
	}
	printf("%lld\n",ans%mod);
}