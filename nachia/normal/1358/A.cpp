#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

int main() {
	UL T; cin >> T;
	while (T--) {
		UL N, M; cin >> N >> M;
		if (N * M % 2 == 0) cout << N * M / 2 << endl;
		else cout << N * M / 2 + 1 << endl;
	}
	return 0;
}