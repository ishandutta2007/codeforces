#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

void loop() {
	int N, K; cin >> N >> K;
	vector<int> B(K);
	{
		vector<int> I(N); rep(i, N) { int a; cin >> a; I[a - 1] = i; }
		rep(i, K) { int b; cin >> b; B[i] = I[b - 1]; }

	}

	vector<int> F(N);
	rep(i, K) F[B[i]] = 1;
	ULL ans = 1;
	for (int b : B) {
		ULL tmp = 0;
		if (0 < b) if (F[b - 1] == 0) tmp++;
		if (b < N - 1) if (F[b + 1] == 0) tmp++;
		ans = ans * tmp % 998244353;
		F[b] = 0;
	}
	cout << ans << endl;
}

int main() {
	int t; cin >> t;
	while (t--) loop();

	return 0;
}