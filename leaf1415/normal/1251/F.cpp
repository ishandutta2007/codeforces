#include <iostream>
#include <map>
#define llint long long

using namespace std;

const llint mod = 998244353;
llint n, k, Q;
llint a[300005], b[5];
map<llint, llint> mp;
llint f[5][1<<19], g[5][1<<19], F[5][1<<19], G[5][1<<19];
llint A, B;

const int FACT_MAX = 600005;
llint fact[FACT_MAX], fact_inv[FACT_MAX];

llint modpow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2) % mod;
	}
}

void make_fact()
{
	llint val = 1;
	fact[0] = 1;
	for(int i = 1; i < FACT_MAX; i++){
		val *= i;
		val %= mod;
		fact[i] = val;
	}
	fact_inv[FACT_MAX-1] = modpow(fact[FACT_MAX-1], mod-2);
	for(int i = FACT_MAX-2; i >= 0; i--){
		fact_inv[i] = fact_inv[i+1] * (i+1) % mod;
	}
}

llint comb(llint n, llint k)
{
	llint ret = 1;
	ret *= fact[n];
	ret *= fact_inv[k], ret %= mod;
	ret *= fact_inv[n-k], ret %= mod;
	return ret;
}

llint modpow(llint a, llint n, llint mod)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1, mod)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2, mod) % mod;
	}
}

int rev(int x, int n)
{
	int ret = 0;
	for(int i = 0; i < n; i++){
		ret <<= 1;
		ret |= (x>>i) & 1;
	}
	return ret;
}

//f[]F[]root12^n
void DFT(llint f[], llint F[], int n, llint mod, llint root)
{
	int N = 1<<n;
	for(int i = 0; i < N; i++) F[rev(i, n)] = f[i];
	
	llint a, b, x, z;
	for(int i = 1; i <= n; i++){
		int l = 1<<i;
		z = modpow(root, 1<<(n-i), mod);
		for(int j = 0; j < N/l; j++){
			x = 1;
			for(int k = 0; k < l/2; k++){
				a = F[j*l+k], b = F[j*l+k+l/2];
				F[j*l+k] = a + x * b % mod, F[j*l+k] %= mod;
				F[j*l+k+l/2] = a - x * b % mod + mod, F[j*l+k+l/2] %= mod;
				x *= z, x %= mod;
			}
		}
	}
}

//f[]F[]root12^n
void IDFT(llint F[], llint f[], int n, llint mod, llint root)
{
	int N = 1<<n;
	for(int i = 0; i < N; i++) f[rev(i, n)] = F[i];
	root = modpow(root, mod-2, mod);
	
	llint a, b, x, z;
	for(int i = 1; i <= n; i++){
		int l = 1<<i;
		z = modpow(root, 1<<(n-i), mod);
		for(int j = 0; j < N/l; j++){
			x = 1;
			for(int k = 0; k < l/2; k++){
				a = f[j*l+k], b = f[j*l+k+l/2];
				f[j*l+k] = a + x * b % mod, f[j*l+k] %= mod;
				f[j*l+k+l/2] = a - x * b % mod + mod, f[j*l+k+l/2] %= mod;
				x *= z, x %= mod;
			}
		}
	}
	llint Ninv = modpow(N, mod-2, mod);
	for(int i = 0; i < N; i++) f[i] *= Ninv, f[i] %= mod;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	make_fact();
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 0; i < k; i++) cin >> b[i];
	for(int i = 1; i <= n; i++) mp[a[i]]++;
	
	llint N = 1<<19;
	llint root = modpow(3, 119*16, mod);
	
	for(int i = 0; i < k; i++){
		A = 0, B = 0;
		for(auto it = mp.begin(); it != mp.end(); it++){
			if(it->first >= b[i]) break;
			if(it->second >= 2) B++;
			else A++;
		}
		for(int j = 0; j <= A; j++) f[i][j] = comb(A, j) * modpow(2, j) % mod;
		for(int j = 0; j <= 2*B; j++) g[i][j] = comb(2*B, j);
		DFT(f[i], F[i], 19, mod, root);
		DFT(g[i], G[i], 19, mod, root);
		for(int j = 0; j < N; j++) F[i][j] *= G[i][j], F[i][j] %= mod;
		IDFT(F[i], f[i], 19, mod, root);
	}
	
	cin >> Q;
	llint x;
	for(int q = 0; q < Q; q++){
		cin >> x;
		llint ans = 0;
		for(int i = 0; i < k; i++){
			llint need = x - 2*b[i] - 2;
			if(need < 0) continue;
			need /= 2;
			ans += f[i][need], ans %= mod;
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}