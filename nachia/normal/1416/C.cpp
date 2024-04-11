#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using ULL=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

ULL N;
vector<vector<ULL>> A;
ULL ans = 0;
ULL ansinv = 0;

int main() {
	scanf("%llu", &N); A.emplace_back(N);
	rep(i, N) scanf("%llu", &A[0][i]);

	for (ULL d = 30; d != ~0ull; d--) {
		ULL D = 1 << d;

		ULL inv0 = 0, inv1 = 0;
		for (auto& iA : A) {
			ULL c0 = 0, c1 = 0;
			for(ULL a : iA) {
				if (a & D) { inv1 += c0; c1++; }
				else { inv0 += c1; c0++; }
			}
		}
		if (inv0 <= inv1) { ansinv += inv0; }
		else { ans |= D; ansinv += inv1; }

		vector<vector<ULL>> buf;
		for (auto& iA : A) {
			vector<ULL> x[2];
			for (ULL a : iA) {
				if (a & D) x[1].push_back(a);
				else x[0].push_back(a);
			}
			rep(i, 2) if (x[i].size()) buf.push_back(move(x[i]));
		}

		A = move(buf);
	}

	printf("%llu %llu\n", ansinv, ans);

	return 0;
}