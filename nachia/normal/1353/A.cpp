#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {
public:

	void Solve() {
		UL T; scanf("%d", &T);
		while (T--) {
			UL N, M; scanf("%d%d", &N, &M);
			if (N == 1) printf("0\n");
			else if (N == 2) printf("%d\n", M);
			else printf("%d\n", 2 * M);
		}
	}
};

int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}