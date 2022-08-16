#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	long long n, q;
	cin >> n >> q;
	for (int i=0; i<q; ++i) {
		long long u, x;
		string s;
		cin >> u >> s;
		x = 1LL << __builtin_ctzll(u);
		for (char si: s) {
			if (si=='L')
				if (x != 1)
					x/=2, u -= x;
			if (si=='R')
				if (x != 1)
					x/=2, u += x;
			if (si=='U')
				if (x*2 != n+1)
					u^=x, x*=2, u|=x;
		}
		cout << u << endl;
	}
	return 0;
}