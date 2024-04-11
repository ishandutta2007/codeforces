#define  _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#pragma comment (linker, "/STACK:526000000")

#include "bits/stdc++.h"
#define int ll

using namespace std;
typedef string::const_iterator State;
#define eps 1e-9L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()
void init() {
	iostream::sync_with_stdio(false);
	cout << fixed << setprecision(20);
}
int grids[5201][5201];
void solve() {
	int n;
	cin >> n;
	REP(i, n) {
		string s;
		cin >> s;
		REP(q, s.length()) {
			int geko;
			if (s[q] >= 'A' and s[q] <= 'Z') {
				geko = 10 + s[q] - 'A';
			}
			else {
				geko = s[q] - '0';
			}
			int tmp = 0;
			REP(j, 4) {
				if ((1 << j) & geko) {
					grids[i][q * 4 + (3 - j)] = 1;
				}
			}
		}
	}
	REP(i, n) {
		REP(q, n) {
			grids[i][q + 1] += grids[i][q];
		}
	}
	REP(i, n) {
		REP(q, n) {
			grids[i + 1][q] += grids[i][q];
		}
	}
	for (int i = n; i >= 2; --i) {
		if (n % i) continue;
		int ok = 1;
		REP(q, n / i) {
			REP(j, n / i) {
				if (grids[q * i + i - 1][j * i + i - 1] % (i * i)) {
					ok = 0;
					break;
				}
			}
		}
		if (ok == 1) {
			cout << i << endl;
			return;
		}
	}
	cout << 1 << endl;
}
#undef int
int main() {
	init();
	solve();
}