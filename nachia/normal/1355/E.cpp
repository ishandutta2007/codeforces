#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {
public:

	UL N, A, R, M;
	ULL H[100000];

	void F(ULL h, ULL* AN, ULL* RN) {
		*AN = *RN = 0;
		rep(i, N) {
			if (H[i] < h) *AN += h - H[i];
			else *RN += H[i] - h;
		}
	}
	ULL FF(ULL h) {
		ULL AN, RN, MN = 0;
		F(h, &AN, &RN);
		MN = min(AN, RN);
		AN -= MN; RN -= MN;
		ULL ans = AN * A + RN * R + MN * M;
		return ans;
	}

	void Solve() {
		scanf("%d%d%d%d", &N, &A, &R, &M);
		M = min(M, A + R);
		rep(i, N) scanf("%lld", H + i);
		sort(H, H + N);
		for (UL i = 1; i < N; i++) H[i] -= H[0];
		H[0] = 0;
		ULL p;
		{
			ULL l, r; l = 0; r = H[N - 1] + 1;
			while (l + 1 < r) {
				ULL m = (l + r) >> 1;
				ULL AN, RN; AN = RN = 0;
				F(m, &AN, &RN);
				if (AN <= RN) l = m; else r = m;
			}
			p = l;
		}
		ULL ans[2];
		{
			ULL l, r;

			l = (ULL)-1; r = p + 1;
			while (r - l > 2) {
				ULL m1 = (l + l + r) / 3;
				ULL m2 = (l + r + r) / 3;
				if (FF(m1) < FF(m2)) r = m2;
				else l = m1;
			}
			ans[0] = FF(l + 1);

			l = p; r = H[N - 1] + 1;
			while (r - l > 2) {
				ULL m1 = (l + l + r) / 3;
				ULL m2 = (l + r + r) / 3;
				if (FF(m1) < FF(m2)) r = m2;
				else l = m1;
			}
			ans[1] = FF(l + 1);
		}

		printf("%lld\n", min(ans[0], ans[1]));
	}
};

int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}