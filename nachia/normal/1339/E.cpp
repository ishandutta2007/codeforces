#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

template<class Ty>
using passive_queue = priority_queue<Ty, vector<Ty>, greater<Ty>>;

struct Problem {
	void Loop() {
		ULL N; cin >> N;
		UL dig = 0; while (1ull << (dig * 2) <= N) dig++;
		dig--;
		N -= (1ull << (dig * 2));
		ULL D = N / 3, I = N % 3;
		ULL ans = (I + 1) << (dig * 2);

		ULL Tb[4][3] = { {0,0,0}, {1,2,3}, {2,3,1}, {3,1,2} };
		rep(i, dig) {
			ans |= Tb[D & 3][I] << (i * 2);
			D >>= 2;
		}
		cout << ans << endl;
	}

	void Solve() {
		UL T; cin >> T;
		rep(t, T) Loop();
	}

	Problem();
};
int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}
Problem::Problem() {
	cout << fixed << setprecision(10);
}