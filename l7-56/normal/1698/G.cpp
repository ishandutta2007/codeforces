#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vl;
#define fir first
#define sec second

const ll T = 2e5;
ll s;
int n, m;

ll pmod(ll t) {
	if ((t >> (n - 1)) & 1) t ^= s;
	return t;
} // t % s

ll mul(ll a, ll b) {
	ll res = 0;
	for (int i = 0; i <= 35; ++i) {
		if ((a >> i) & 1) res ^= b;
		b = pmod(b << 1);
	}
	return res;
} // a * b % s;

map <ll, ll> mp;

void input() {
	char str[100];
	scanf("%s", str);
	int len = strlen(str);
	for (int i = 0; i < len; ++i)
		s |= ll(str[i] - '0') << i;
}

int main() {
	input();
	if (!s) return printf("-1\n"), 0;
	while (!(s & 1)) s >>= 1, ++m;
	while (s >> n) ++n;
	ll a = 1;
	for (int i = 0; i < T; ++i)
		mp[a] = i, a = pmod(a << 1);
	ll b = a;
	for (int i = 1; i < T; ++i) {
		auto it = mp.find(b);
		if (it != mp.end()) return printf("%d %lld\n", m + 1, m + i * T - it -> sec + 1), 0;
		b = mul(a, b);
	}
	return 0;
}