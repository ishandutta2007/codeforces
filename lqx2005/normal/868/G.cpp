#include<bits/stdc++.h>

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define mp make_pair
#define x first
#define y second

using namespace std;

typedef pair<int, int> par;
typedef long long ll;
typedef double db;
const int P = 1e9 + 7, K = 21, inv2 = (P + 1) / 2;
int n;

int qpow(int a, ll b) {
	int res = 1;
	for(; b; b >>= 1, a = 1ll * a * a % P) if(b & 1) res = 1ll * res * a % P;
	return res;
}

struct node {
	ll c1, c2;
	int s, si, sj;
	node() { c1 = c2 = s = si = sj = 0; }
	const friend node operator * (const node a, const node b) {
		node c;
		c.c1 = (a.c1 + b.c1), c.c2 = (a.c2 + b.c2);
		c.s = (a.s + 1ll * b.s * qpow(inv2, a.c1) % P) % P;
		c.si = (a.si + 1ll * (b.si + 1ll * b.s * (a.c1 % P) % P) % P * qpow(inv2, a.c1) % P) % P;
		c.sj = (a.sj + 1ll * (b.sj + 1ll * b.s * (a.c2 % P) % P) % P * qpow(inv2, a.c1) % P) % P;
		return c;
	}
	const friend node operator ^ (node a, ll b) {
		node res;
		for(; b; b >>= 1, a = a * a) if(b & 1) res = res * a;
		return res;	
	}
};

template<typename T> T asgcd(ll a, ll b, ll c, ll n, T U, T R) {
	if(a >= c) return asgcd(a % c, b, c, n, U, (U ^ a / c) * R);
	if(b >= c) return (U ^ b / c) * asgcd(a, b % c, c, n, U, R);
	ll m = ((ll)a * n + b) / c;
	if(m == 0) return R ^ n;
	swap(U, R);
	return (U ^ (c - b - 1) / a) * R * asgcd(c,(c - b - 1) % a, a, m - 1, U, R) * (U ^ (n - ((ll) m * c - b - 1) / a));
}

int main() {
	int T;
	cin >> T;
	for(; T--; ) {
		ll n, k;
		cin >> n >> k;
		node U, R;
		U.c1 = 1, R.c2 = R.s = 1;
		node ans = R * asgcd(k, 0, n, n - 1, U, R);
		int s = ans.s, si = ans.si, sj = ans.sj;
		int res = 0;
		int inv = qpow((1 - qpow(inv2, k) + P) % P, P - 2);
		(res += 1ll * s * inv % P * n % P) %= P;
		int sum = (1ll * sj * k % P - 1ll * si * n % P + P) % P;
//		for(int i = 0; i < n; i++) {
//			(sum += 1ll * i * k % n * qpow(inv2, i * k / n) % P) %= P;
//		}
		sum = 1ll * sum * inv2 % P * inv % P;
		(res += P - sum) %= P; 
		res = 1ll * res * qpow(n, P - 2) % P;
		cout << res << endl;
	} 
	
	return 0;
}