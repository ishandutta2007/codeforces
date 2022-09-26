#include <bits/stdc++.h>
using namespace std;

const int N = 16;
const int inf = 1e9;
const int SUB = 144;

int n;
char color[N];
int red[N];
int blue[N];
int f[1 << N][SUB];
int sumR, sumB;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> color[i] >> red[i] >> blue[i];
		sumR += red[i];
		sumB += blue[i];
	}
	for (int msk = 0; msk < (1 << n); ++msk) {
		for (int subR = 0; subR < SUB; ++subR) {
			f[msk][subR] = -inf;
		}
	}
	f[0][0] = 0;
	for (int msk = 0; msk < (1 << n); ++msk) {
		int cntR = 0, cntB = 0;
		for (int i = 0; i < n; ++i) {
			if ((msk >> i) & 1) {
				if (color[i] == 'R') {
					++cntR;
				} else {
					++cntB;
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			if (!((msk >> i) & 1)) {
				int nmsk = msk | (1 << i);
				for (int subR = 0; subR < SUB; ++subR) {
					int subB = f[msk][subR];
					if (subB > -inf) {
						int nsubR = subR + min(cntR, red[i]);
						int nsubB = subB + min(cntB, blue[i]);
						f[nmsk][nsubR] = max(f[nmsk][nsubR], nsubB);
					} 
				}
			}
		}
	}
	int ans = inf;
	for (int subR = 0; subR < SUB; ++subR) {
		int subB = f[(1 << n) - 1][subR];
		if (subB > -inf) {
			ans = min(ans, max(sumR - subR, sumB - subB) + n);
		}
	}
	cout << ans << '\n';
}