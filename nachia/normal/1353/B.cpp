#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {
public:
	UL N, K;
	int A[30];
	int D[30];

	void Solve() {
		UL T; scanf("%d", &T);
		while (T--) {
			cin >> N >> K;
			rep(i, N) scanf("%d", A + i);
			rep(i, N) scanf("%d", D + i);
			sort(D, D + N);
			reverse(D, D + N);
			sort(A, A + N);
			rep(i, N) D[i] -= A[i];
			rep(i, N) D[i] = max(D[i], 0);
			int ans = 0;
			rep(i, N) ans += A[i];
			rep(i, K) ans += D[i];
			printf("%d\n", ans);
		}
	}
};

int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}