#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
using ll = long long;

const int N = 2000;

// Solves Mx = t, where + is xor.  Returns {} on failure.
// The vectors x, t don't have to be 0-1 valued, but if t is, so is x.
// O(N^2 m / log N)
vector<int> binaryGaussian(vector<bitset<N>> mat, vector<int> tar) {
	int m = tar.size();
	vector<int> used(m, 0), perm(N, -1);
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < m; ++y) {
			if (! mat[y][x] || used[y]) continue;
			if (perm[x] == -1) perm[x] = y;
			else {
				mat[y] ^= mat[perm[x]];
				tar[y] ^= tar[perm[x]];
			}
		}
		if (perm[x] != -1) used[perm[x]] = 1;
	}

	for (int y = 0; y < m; ++y) {
		if (!used[y] && tar[y]) return {}; // fail
	}
	vector<int> res(N, 0);
	for (int x = N-1; x >= 0; --x) {
		if (perm[x] != -1) res[x] = tar[perm[x]];
		for (int y = 0; y < m; ++y) {
			if (mat[y][x]) tar[y] ^= res[x];
		}
	}
	return res;
}

int mapChar(char c) {
	for (int i = 0; i < 4; ++i) {
		if ("WRYB"[i] == c) return i;
	}
	return -1;
}
char mapInd(int i) {
	return ".RYB"[i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<vector<int>> perm(n);
	for (int i = 0; i < n; ++i) perm[i] = {0, 1, 2, 3}; // Colors: .RYB, . = 0, R = 1, Y = 2, B = 3

	vector<bitset<N>> mat;
	vector<int> tar;

	for (int j = 0; j < q; ++j) {
		string op;
		cin >> op;
		if (op == "mix") {
			int j = mat.size();
			mat.emplace_back();
			mat.emplace_back();

			int m;
			cin >> m;
			for (; m; --m) {
				int i;
				cin >> i;
				--i;

				vector<int> rev(4);
				for (int t = 0; t < 4; ++t) rev[perm[i][t]] = t;

				mat[j][2*i] = (bool)(rev[1] & 1);
				mat[j+1][2*i] = (bool)(rev[1] & 2);
				mat[j][2*i+1] = (bool)(rev[2] & 1);
				mat[j+1][2*i+1] = (bool)(rev[2] & 2);
			}

			char tc;
			cin >> tc;
			tar.push_back((bool)(mapChar(tc) & 1));
			tar.push_back((bool)(mapChar(tc) & 2));
		} else {
			int m;
			cin >> m;
			for (; m; --m) {
				int i;
				cin >> i;
				--i;
				if (op == "RY") swap(perm[i][1], perm[i][2]);
				if (op == "RB") swap(perm[i][1], perm[i][3]);
				if (op == "YB") swap(perm[i][2], perm[i][3]);
			}
		}
	}


	vector<int> res = binaryGaussian(mat, tar);
	if (res.empty()) cout << "NO\n";
	else {
		cout << "YES\n";
		for (int i = 0; i < n; ++i) cout << mapInd(res[2*i] + 2*res[2*i+1]);
		cout << '\n';
	}
}