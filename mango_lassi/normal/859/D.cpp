#include <iostream>
#include <iomanip>

typedef __float128 type;

const int N = 7;
const int T = 1<<N;
type win [T][T]; // Team x will defeat team y
int n, t;
type max [T];
type chance [T][N+1]; // Chance player p will win i rounds

// Calculate chance player p wins k rounds, when he is in the bracket starting from s and ending at e with height k
void calc(int p, int k, int s, int e) {
	if (chance[p][k] != -1) return;
	if (k == 0) return;
	chance[p][k] = 0;
	int mid = (s + e) / 2;
	if (p <= mid) {
		calc(p, k-1, s, mid);
		for (int i = mid + 1; i <= e; ++i) {
			calc(i, k-1, mid+1, e);
			chance[p][k] += chance[i][k-1] * win[p][i];
		}
	} else {
		calc(p, k-1, mid+1, e);
		for (int i = s; i <= mid; ++i) {
			calc(i, k-1, s, mid);
			chance[p][k] += chance[i][k-1] * win[p][i];
		}
	}
	chance[p][k] *= chance[p][k-1];
}

void solve(int s, int e, int k, int index) {
	if (s == e) return;
	if (max[index] != 0) return;
	for (int i = s; i <= e; ++i) {
		// Decide i will win this bracket
		calc(i, k, s, e);
		type offer = 0;
		// Add expected value of points from that players wins
		for (int depth = 0; depth < k; ++depth) {
			offer += (1<<depth) * chance[i][depth + 1];
		}
		// Add maximum amount of points from the subcases
		int ts = s;
		int te = e;
		int tindex = index;
		for (int depth = k-1; depth >= 0; --depth) {
			int mid = (ts + te) / 2;
			if (i <= mid) {
				solve(mid+1, te, depth, tindex * 2 + 1);
				offer += max[tindex * 2 + 1];

				tindex = tindex * 2;
				te = mid;
			} else {
				solve(ts, mid, depth, tindex * 2);
				offer += max[tindex * 2];

				tindex = tindex * 2 + 1;
				ts = mid + 1;
			}
		}
		if (offer > max[index]) max[index] = offer;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	t = 1<<n;

	for (int x = 0; x < t; ++x) {
		for (int y = 0; y < t; ++y) {
			long double temp;
			std::cin >> temp;
			win[x][y] = temp / 100.0;
		}
	}

	for (int i = 0; i < t; ++i) {
		chance[i][0] = 1;
		for (int k = 1; k <= n; ++k) {
			chance[i][k] = -1;
		}
	}
	
	solve(0, t-1, n, 1);
	std::cout << std::setprecision(40) << (long double)max[1] << '\n';
}