#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

void Loop() {
	string S; cin >> S;

	int ans = 1000;
	rep(q, 2) {
		int M[1001] = {};
		UL N = S.size();
		rep(i, N) {
			M[i + 1] = M[i] + ((S[i] == '0') ? 0 : 1);
		}
		rep(i, N + 1) {
			ans = min(ans, (int)i - M[i] + M[N] - M[i]);
		}
		reverse(S.begin(), S.end());
	}
	printf("%d\n", ans);
}

int main() {
	UL T; cin >> T;
	rep(i, T) Loop();
	return 0;
}