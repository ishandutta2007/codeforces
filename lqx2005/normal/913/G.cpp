#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef __int128 LL;
const ll mod1 = 762939453125ll, inv = mod1 / 5 * 4;
const int N = 17;
const ll mod2 = 1 << 17;
const LL mod3 = 10000000000000000ll;
ll mod[N + 5], phi[N + 5];
LL power2(LL a, LL b, LL c = 1) {
	for(; b; b >>= 1, a = (LL)a * a % mod3) if(b & 1) c = (LL)c * a % mod3;
	return c;
}
ll power(ll a, ll b, ll c = 1) {
	for(; b; b >>= 1, a = (LL)a * a % mod1) if(b & 1) c = (LL)c * a % mod1;
	return c;
}
ll BSGS(ll x) {
	ll now = 1, res = 0;
	for(int i = 1; i <= 17; i++) {
		ll s = power(2, phi[i - 1]);
		for(int j = 0; j < phi[i] / phi[i - 1]; j++) {
			if(now % mod[i] == x % mod[i]) {
				break;
			}
			now = (LL)now * s % mod[17], res += phi[i - 1];
		}
	}
	return res;
}
void solve() {
	ll a, b;
	cin >> a, b = a;
	a = a * 1000000 % mod2;
	a = (mod2 - a) % mod2;
	if(a % 5 == 0) a = a + mod2;
	ll c = b * 1000000 + a;
	cout << BSGS(c % mod1) << endl;
	return;
}
	// 10 ^ 6a + b % (2 ^ 17) == 0s

int main() {
	phi[0] = 1;
	phi[1] = 4;
	mod[1] = 5;
	for(int i = 2; i <= N; i++) phi[i] = phi[i - 1] * 5;
	for(int i = 2; i <= N; i++) mod[i] = mod[i - 1] * 5;
	int t;
	for(cin >> t; t--; solve());
	return 0;
}