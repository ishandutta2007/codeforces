#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200000 + 10;
const int mod = 1000000007;

void add(int &a, int b){
	a += b;
	if (a >= mod)
		a -= mod;
}

int modpow(int a, int n){
	int ans = 1;
	while (n){
		if (n & 1)
			ans = 1LL * ans * a % mod;
		a = 1LL * a * a % mod;
		n >>= 1;
	}
	return ans;
}

int fact[maxn], inv[maxn];

int comb(int n, int k){
	return 1LL * fact[n] * inv[k] % mod * inv[n - k] % mod;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int f, w, h;
	cin >> f >> w >> h;
	h++;

	if (w == 0){
		cout << 1 << endl;
		return 0;
	}

	fact[0] = inv[0] = 1;

	for (int i = 1; i < maxn; ++i)
		fact[i] = 1LL * fact[i - 1] * i % mod, inv[i] = modpow(fact[i], mod - 2);


	int q = comb(f + w, f);
	int p = 0;

	for (int u = 1; h * u <= w && u - 1 <= f; ++u){
		int a = 1LL * comb(f + 1, u) * comb(u - 1 + w - h * u, u - 1) % mod;
		add(p, a);
	}

	int ans = 1LL * p * modpow(q, mod - 2) % mod;

	cout << ans << endl;


	return 0;
}