#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
void read(pp& x){ scanf("%d%d",&x.first, &x.second); }
void read(pll& x){ scanf("%lld%lld",&x.first, &x.second); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

ll n, m;

const ll mod = int(1e9) + 7;
const int maxn = int(2e6) + 10;
ll fact[maxn];
ll finv[maxn];

ll ipow(ll b, ll e){
	ll ret=1;
	while(e){
		if(e&1) (ret*=b)%=mod;
		(b*=b)%=mod; e>>=1;
	}
	return ret;
}

void build(){
	fact[0]=1;
	const int N = int(2e6);
	for(int i=1; i<=N; ++i) fact[i]=fact[i-1]*i%mod;
	finv[N] = ipow(fact[N], mod-2);
	for(int i=N-1; 1<=i; --i) finv[i]=finv[i+1]*(i+1)%mod;
	finv[0]=1;
}

ll C(ll n, ll r){ if(r<0 || r>n || n<0) return 0; return fact[n] * finv[r] % mod * finv[n-r] % mod; }
ll H(ll n, ll r){ return C(n+r-1, r); }

int main()
{
	build();

	cin >> n >> m;
	ll ans = 0;
	for(ll k=0; k<=n-2; ++k){
		ll c = H(k+1, m-(k+1)) * fact[k] % mod;
		if(k < n-2) (ans += c * (k+2) % mod * ipow(n, n - (k+2) - 1) % mod * ipow(m, (n-1) - (k+1)) % mod * C(n-2, k) % mod) %= mod;
		else (ans += c) %= mod;
	}

	cout << ans << endl;
	return 0;
}