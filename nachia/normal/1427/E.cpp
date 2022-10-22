#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
	ULL N; cin >> N;
	vector<string> ans;

	while (true) {
		if (N == 1) break;
		
		ULL D = 1; int d = 0; while (D < N) { D *= 2; d++; }

		if (N == D - 1) {
			ULL P = N;
			rep(i, d - 1) {
				ans.push_back(to_string(P) + " + " + to_string(P));
				P = P + P;
			}

			ULL P2 = P;
			ans.push_back(to_string(P2) + " ^ " + to_string(N));
			P2 = P2 ^ N;

			ans.push_back(to_string(P) + " + " + to_string(N));
			P = P + N;
			ans.push_back(to_string(P2) + " + " + to_string(N));
			P2 = P2 + N;
			ans.push_back(to_string(P) + " ^ " + to_string(P2));
			N = P ^ P2;
		}

		else {
			ULL P = N, p = N;
			rep(i, d - 1) {
				ans.push_back(to_string(P) + " + " + to_string(P));
				P = P + P;
				ans.push_back(to_string(p) + " + " + to_string(P));
				p = p + P;
			}

			ans.push_back(to_string(P) + " + " + to_string(P));
			P = P + P;

			for (int i = d * 2 - 1; i >= d - 1; i--) {
				if (!(p & (1ull << i))) continue;
				ans.push_back(to_string(p) + " ^ " + to_string(N << (i - d + 1)));
				p = p ^ (N << (i - d + 1));
			}

			if (p % 2 == 0) {
				while (p * 2 < N) {
					ans.push_back(to_string(p) + " + " + to_string(p));
					p = p + p;
				}
				ans.push_back(to_string(p) + " ^ " + to_string(N));
				p = p ^ N;
			}

			N = p;
		}
	}

	cout << ans.size() << endl;
	for (string& S : ans) cout << S << endl;

	return 0;
}