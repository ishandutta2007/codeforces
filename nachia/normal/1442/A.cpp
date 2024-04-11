#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

void loop() {
	int N; cin >> N;
	vector<LL> A(N); rep(i, N) cin >> A[i];
	vector<LL> D(N);
	rep(i, N - 1) if (A[i] > A[i + 1]) D[i] = A[i] - A[i + 1];
	for (int i = N - 2; i >= 0; i--) D[i] += D[i + 1];
	rep(i, N - 1) A[i] -= D[i];
	bool ok = true;
	rep(i, N) if (A[i] < 0) ok = false;
	cout << (ok ? "YES" : "NO") << endl;
}

int main() {
	int t; cin >> t;
	while (t--) loop();

	return 0;
}