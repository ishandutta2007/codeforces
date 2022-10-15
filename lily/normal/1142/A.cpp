#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define x first
#define y second
#define mp(a, b) make_pair(a, b)
#define read(a) scanf("%d", &a)


LL n, k, m = 1231231239999999ll, M = -1;
LL gcd(LL a, LL b) {
	if (b) return gcd(b, a % b);
	else return a;
}


void solve(LL a, LL b) {
	LL tot = n * k;
	LL mod = (b - a + k) % k;
	for (int i = 0; i < n; i++) {
		LL tra = i * k + mod; 
		LL g = gcd(tot, tra);
		LL ans = tot / g;
		m = min(ans, m);
		M = max(ans, M);
	}
}
LL a, b;

int main() {
	cin >> n >> k >> a >> b;
	solve(a, b);
	solve(k - a, b);
	solve(a, k - b);
	solve(k - a, k - b);
	cout << m << " " << M << endl;
	return 0;
}