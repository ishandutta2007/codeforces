#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N); rep(i, N) cin >> A[i];
		sort(A.begin(), A.end());
		int S = 0; rep(i, N) S += A[i];
		if (S == 0) { cout << "NO" << endl; continue; }
		if (S > 0) reverse(A.begin(), A.end());
		cout << "YES" << endl;
		rep(i, N) { if (i) cout << " "; cout << A[i]; } cout << endl;
	}


	return 0;
}