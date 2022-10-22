#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

vector<pair<ULL, ULL>> factorize(ULL N) {
	vector<pair<ULL, ULL>> res;
	for (ULL i = 2; i * i <= N; i++) {
		if (N % i) continue;
		res.push_back({ i,0 });
		while (N % i == 0) { N /= i; res.back().second++; }
	}
	if (N != 1) res.push_back({ N,1 });
	return move(res);
}

void loop() {
	ULL p, q; cin >> p >> q;
	ULL ans = 1;
	auto F = factorize(q);
	rep(i, F.size()) {
		ULL f = F[i].first;
		ULL x = p;
		while (x % q == 0) x /= f;
		ans = max(ans, x);
	}
	
	if (p % q != 0) ans = p;
	cout << ans << endl;
}

int main() {
	int t; cin >> t;
	while (t--) {
		loop();
	}
	return 0;
}