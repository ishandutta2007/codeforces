#include<cstdio>

#define rep(i,a,n) for (int i=(int)a; i<(int)n; i++)
#define per(i,a,n) for (int i=((int)n-1); i>=(int)a; i--)
typedef long long ll;
ll mod = 1000000007;
ll powmod(ll a, ll b){
	ll res=1;
	a %= mod;
	for(;b;b>>=1){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
	}
	return res;
}

namespace polysum{
	const int D = 101111;
	ll a[D], f[D], g[D], p[D], p1[D], p2[D], b[D], h[D][2], C[D];
	ll calcn(int d,ll*a,ll n){
		if(n<=d)return a[n];
		p1[0] = p2[0] = 1;
		rep(i, 0, d+1){
			ll t = (n-i+mod)%mod;
			p1[i+1] = p1[i] * t % mod;
		}
		rep(i, 0, d+1){
			ll t = (n-d+i+mod)%mod;
			p2[i+1] = p2[i] * t % mod;
		}
		ll ans = 0;
		rep(i, 0, d+1){
			ll t = g[i] * g[d-i] % mod * p1[i] % mod * p2[d-i]%mod * a[i] % mod;
			if((d-i)&1)ans = (ans - t + mod)%mod;else
				ans = (ans + t)%mod;
		}
		return ans;
	}
	void init(int M){
		f[0] = f[1] = g[0] = g[1] = 1;
		rep(i, 2, M+5)f[i] = f[i-1] * i % mod;
		g[M+4] = powmod(f[M+4], mod-2);
		per(i, 1, M+4) g[i] = g[i+1] * (i+1) % mod;
	}
	ll polysum(ll n, ll *a, ll m){
		a[m+1] = calcn(m,a,m+1);
		rep(i, 1, m+2)a[i] = (a[i-1]+a[i])%mod;
		return calcn(m+1, a, n-1);
	}
	ll qpolysum(ll R,ll n,ll *a,ll m){//a[0] .. a[m] \sum_{i=0}^{n-1} a[i] * R^i
		if(R == 1)return polysum(n,a,m);
		a[m+1] = calcn(m, a, m+1);
		ll r = powmod(R, mod-2), p3 = 0, p4 = 0, c, ans;
		h[0][0] = 0;
		h[0][1] = 1;
		rep(i, 1, m+2){
			h[i][0] = (h[i-1][0]+a[i-1])*r%mod;
			h[i][1] = h[i-1][1]*r%mod;
		}
		rep(i, 0, m+2){
			ll t = g[i] * g[m+1-i]%mod;
			if(i&1) p3 = ((p3-h[i][0]*t)%mod+mod)%mod,p4=((p4-h[i][1]*t)%mod+mod)%mod;
			else p3 = (p3+h[i][0]*t)%mod, p4 = (p4+h[i][1]*t)%mod;
		}
		c = powmod(p4, mod-2)*(mod-p3)%mod;
		rep(i,0,m+2)h[i][0] = (h[i][0]+h[i][1]*c)%mod;
		rep(i,0,m+2)C[i] = h[i][0];
		ans = ((calcn(m,C,n)*powmod(R,n)-c)%mod+mod)%mod;
		return ans;
	}
}

/*#### modular_arithmetic */
class modular_arithmetic{
public:
	int mod, range;

	modular_arithmetic(){
		mod = 1000000007;
	}
	//No specific settings.
	void set_mod(int _mod){mod = _mod;}
	int add(int x,int y){return (x+y)%mod;}
	int sub(int x,int y){return (x-y+mod)%mod;}
	int mul(int x,int y){return (int)((long long int)x*y%mod);}
	int pw(int x,int y){
		int r = 1;
		while(1){
			if(y&1)r=mul(r,x);
			if(y>>=1)x=mul(x,x);else
				break;
		}
		return r;
	}
	//mod must be a prime.
	int inv(int x){
		return pw(x, mod-2);
	}
} ma;
/*####*/

int c[5555][5555],p[5555];
long long int res[5555];
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0; i<=k+1; i++)
		for(int j=0; j<=i; j++)
			c[i][j] = j==0||j==i?1:ma.add(c[i-1][j],c[i-1][j-1]);
	for(int j=1; j<=k+1; j++)
		p[j] = ma.pw(j,k);
	for(int i=1; i<=k+1; i++){
		for(int j=1; j<=i; j++)
			res[i] = ma.add(res[i], ma.mul(c[i][j], p[j]));
		if(n == i){
			printf("%d\n",res[i]);
			return 0;
		}
		if(i == k+1)
			res[i] = ma.mul(res[i], ma.inv(2));
		else
			res[i] = ma.mul(res[i], ma.pw(2, k-i));
	}
	polysum::init(k);
	printf("%d\n",ma.mul(polysum::calcn(k, res+1, n-1), ma.pw(2,n-k)));
	return 0;
}