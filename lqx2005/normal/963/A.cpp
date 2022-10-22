#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
const int N = 1e5 + 10, P = 1e9 + 9;
int n, a, b, k;
char c[N];
int s[N];

int power(int a, int b, int c = 1) {
	for(; b; b >>= 1, a = 1ll * a * a % P) {
		if(b & 1) {
			c = 1ll * c * a % P;
		}
	}
	return c;
} 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> a >> b >> k;
	cin >> c;
	int ans = 0;
	for(int i = 0, x; i < k; i++) {
		x = (c[i] == '+' ? 1 : -1);
		if(x == 1) (ans += 1ll * power(a, n - i) * power(b, i) % P) %= P;
		else (ans += P - 1ll * power(a, n - i) * power(b, i) % P) %= P;
	}
	int ba = 1ll * b * power(a, P - 2) % P;
	ba = power(ba, k);
	int t = (n + 1) / k;
	if(ba == 1) ans = 1ll * ans * t % P;
	else ans = 1ll * ans * (power(ba, t) - 1 + P) % P * power((ba - 1 + P) % P, P - 2) % P;
	cout << ans << endl;
	return 0;
}