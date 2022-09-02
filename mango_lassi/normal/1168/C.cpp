#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 3 * (int)1e5;
const int M = 19; // 1<<M > 300 000
int dist[M][M];
int offer[M];
int val[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; ++i) cin >> val[i];

	// At every node, for every pair of bits, store how far forward you have to go to get to that bit
	// To answer queries, check for every bit of first number how far you have to go to get to every bit of second number.
	// If some distance is short enough, answer YES. otherwise answer NO.
	
	vector<pair<int, pair<int, int>>> que(q);
	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		que[i] = {a, {b, i}};
	}
	sort(que.begin(), que.end());

	for (int a = 0; a < M; ++a) {
		for (int b = 0; b < M; ++b) {
			dist[a][b] = n;
		}
	}

	vector<bool> ans(q, false);

	int i = n;
	for (int qi = q-1; qi >= 0; --qi) {
		int a = que[qi].first;
		int b = que[qi].second.first;
		int ans_ind = que[qi].second.second;
		while(i > a) {
			--i;
			for (int jb = 0; jb < M; ++jb) {
				dist[jb][jb] = i;
				offer[jb] = n;
			}
			for (int ja = 0; ja < M; ++ja) {
				if (val[i] & (1<<ja)) {
					for (int jb = 0; jb < M; ++jb) {
						offer[jb] = min(offer[jb], dist[ja][jb]);
					}
				}
			}
			for (int ja = 0; ja < M; ++ja) {
				if (val[i] & (1<<ja)) {
					for (int jb = 0; jb < M; ++jb) {
						dist[ja][jb] = offer[jb];
					}
				}
			}
		}
		/*
		cout << i << ":\n";
		for (int ja = 0; ja < 3; ++ja) {
			cout << "\t" << ja << ": ";
			for (int jb = 0; jb < 3; ++jb) {
				cout << dist[ja][jb] << ' ';
			}
			cout << '\n';
		}
		*/
		int res = n;
		for (int ja = 0; ja < M; ++ja) {
			for (int jb = 0; jb < M; ++jb) {
				if ((val[a] & (1<<ja)) && (val[b] & (1<<jb))) {
					res = min(res, dist[ja][jb]);
				}
			}
		}
		ans[ans_ind] = (res <= b);
	}

	for (int j = 0; j < q; ++j) {
		if (ans[j]) cout << "Shi\n";
		else cout << "Fou\n";
	}
}