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

const int T = 70;
const ll mod = int(1e9)+7;

ll inv[T+2];

ll n, k;

ll ans = 1;

struct mat {
	ll x[T+1][T+1];
	mat(){ memset(x, 0, sizeof(x)); }
	mat operator*(mat r) const {
		mat ret;
		for(int i=0; i<=T; ++i) for(int j=0; j<=T; ++j) for(int k=0; k<=T; ++k){
			(ret.x[i][k] += (x[i][j] * r.x[j][k] % mod)) %= mod;
		}
		return ret;
	}
} A;

ll ipow(ll b, ll e){
	if(e<0) e=(-e)*(mod-2)%(mod-1);
	ll ret = 1;
	while(e){
		if(e&1) (ret*=b)%=mod;
		(b*=b)%=mod; e>>=1;
	}
	return ret;
}

void Work(ll p, ll e){
	ll t = 0;
	for(int i=0; i<=e; ++i){
		(t += ipow(p, i) * A.x[e][i] % mod) %= mod;
	}
	(ans *= t) %= mod;
}

mat I;

mat matpow(mat& b, int e){
	mat ret = I;
	while(e){
		if(e&1) ret = (ret*b);
		b = b*b; e >>= 1;
	}
	return ret;
}

void build(){
	for(int i=0; i<=T; ++i) I.x[i][i] = 1;
	mat b;
	for(int i=0; i<=T; ++i){
		for(int j=0; j<=i; ++j) b.x[i][j] = inv[i+1];
	}
	A = matpow(b, k);
}

int main()
{
	read(n, k);

	rrep(i, T) inv[i] = ipow(i, -1);
	build();

	for(ll i = 2; i * i <= n; ++i) if(n % i == 0){
		int e = 0;
		while(n%i == 0) n/=i, ++e;
		Work(i, e);
	}

	if(n > 1) Work(n, 1);

	printf("%lld\n", ans);
	return 0;
}