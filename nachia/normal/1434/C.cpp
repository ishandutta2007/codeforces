#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)


void loop() {
	LL a, b, c, d; cin >> a >> b >> c >> d;

	if (a > b * c) { cout << -1 << endl; return; }

	LL l = 0, r = c + 2;
	while (l + 1 < r) {
		LL m = (l + r) / 2;
		if (d * m * b < a) l = m;
		else r = m;
	}

	LL ans = (l + 1) * a - b * d * l * (l + 1) / 2;
	cout << ans << endl;
}

int main() {
	int T; cin >> T;
	while (T--) loop();

	return 0;
}