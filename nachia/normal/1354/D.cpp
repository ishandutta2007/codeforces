#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Set {
	static const UL N = 1048576;
	UL V[N + N - 1] = {};
	void ins(UL i) {
		i = N + i; V[i]++;
		do {
			i = (i - 1) >> 1;
			V[i]++;
		} while (i);
	}
	UL pop(UL k) {
		UL i = 0;
		while (i < N) {
			if (V[(i << 1) + 1] >= k) { i = (i << 1) + 1; }
			else { i = (i << 1) + 2; k -= V[i - 1]; }
		}
		UL result = i - N;
		V[i]--;
		do {
			i = (i - 1) >> 1;
			V[i]--;
		} while (i);
		return result;
	}
	UL size() { return V[0]; }
};

struct Problem {
public:

	Set S;

	void Solve() {
		UL N, Q; scanf("%d%d", &N, &Q);
		rep(i, N) {
			UL A; scanf("%d", &A);
			S.ins(A);
		}
		rep(i, Q) {
			int K; scanf("%d", &K);
			if (K < 0) {
				S.pop(-K);
			}
			else {
				S.ins(K);
			}
		}
		if (S.size()) printf("%d\n", S.pop(1));
		else printf("0\n");
	}
};

int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}