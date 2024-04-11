#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 10 + 2 * (int)1e5;
const int M = 10 + 2 * (int)1e5;
const int L = 18;
int perm[N];
int rev_perm[N];
int as[M];
int nxt[M][L];
int itvs[M];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, q;
	cin >> n >> m >> q;

	for (int i = 0; i < n; ++i) {
		cin >> perm[i];
		--perm[i];
		rev_perm[perm[i]] = i;
	}
	for (int i = 0; i < m; ++i) {
		cin >> as[i];
		--as[i];
	}

	vector<int> pos(n, m);
	for (int i = m-1; i >= 0; --i) {
		int nv = perm[(rev_perm[as[i]] + 1) % n];
		nxt[i][0] = pos[nv];
		pos[as[i]] = i;
	}
	nxt[m][0] = m;

	for (int l = 1; l < L; ++l) {
		for (int i = 0; i <= m; ++i) {
			nxt[i][l] = nxt[nxt[i][l-1]][l-1];
		}
	}
	for (int i = 0; i <= m; ++i) {
		itvs[i] = i;
		int d = n-1;
		for (int j = 0; (1<<j) <= d; ++j) {
			if (d & (1<<j)) {
				itvs[i] = nxt[itvs[i]][j];
			}
		}
	}
	for (int i = m-1; i >= 0; --i) {
		itvs[i] = min(itvs[i], itvs[i+1]);
	}

	for (int qi = 0; qi < q; ++qi) {
		int l, r;
		cin >> l >> r;
		--l; --r;
		if (itvs[l] <= r) {
			cout << "1";
		} else {
			cout << "0";
		}
	}
	cout << '\n';
}