#include <bits/stdc++.h>
using namespace std;

struct State {
	int wa, wb, sa, sb;
};

bool f[5][5][205][205];
State par[5][5][205][205];

bool ok(int a,int b,int t) {
	int lim = (t == 5 ? 15 : 25);
	if (a < b) swap(a, b);
	return (a == lim && a - b >= 2) || (a > lim && a - b == 2);
}

void prep() {
	f[0][0][0][0] = 1;
	for (int wa = 0; wa <= 2; ++wa) {
		for (int wb = 0; wb <= 2; ++wb) {
			for (int sa = 200; sa >= 0; --sa) {
				for (int sb = 200; sb >= 0; --sb) {
					if (f[wa][wb][sa][sb] == 0) continue;
					for (int a = 0; a <= 200 - sa; ++a) {
						for (int b = 0; b <= 200 - sb; ++b) {
							if (!ok(a, b, wa + wb + 1)) continue; 
							int nwa = wa + (a > b), nwb = wb + (b > a);
							int nsa = a + sa, nsb = sb + b;
							if (f[nwa][nwb][nsa][nsb] == 0) {
								f[nwa][nwb][nsa][nsb] = 1;
								par[nwa][nwb][nsa][nsb] = {wa, wb, sa, sb};
							}
						}
					}
				}
			}
		}
	}
}

vector<pair<int,int>> vec;

#define now wa][wb][sa][sb

void brute(int wa,int wb,int sa,int sb) {
	if (wa == 0 && wb == 0) return;
	int nwa = par[now].wa, nwb = par[now].wb, nsa = par[now].sa, nsb = par[now].sb;
	vec.push_back({sa - nsa, sb - nsb});
	brute(nwa, nwb, nsa, nsb);
}

void solve() {
	vec.clear();
	int a, b; 
	cin >> a >> b;
	for (int i = 3; i >= 0; --i) {
		for (int j = 0; j <= 3; ++j) if (max(i, j) == 3) {
			if (f[i][j][a][b] == 0) continue;
			brute(i, j, a, b);
			reverse(vec.begin(), vec.end());
			cout << i << ':' << j << '\n';
			for (auto it : vec) {
				cout << it.first << ':' << it.second << ' ';
			}
			cout << '\n';
			return;
		}
	}
	cout << "Impossible\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	prep();
	int tt; cin >> tt;
	while (tt--) {
		solve();
	}
}