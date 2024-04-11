#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
T rand(T a, T b) {
	return uniform_int_distribution<T>(a, b)(rng);
}

const int H = 18;
const int C = 2;
const uint P = (uint)4e9 + 7;
uint hashes[1 << H][H + 1][C];
uint mults[H + 1][C];

bool compare(int i, int j, int h) {
	for (int k = h - 1; k >= 0; --k) {
		bool eq = 1;
		for (int c = 0; c < C; ++c) eq &= (hashes[i][k][c] == hashes[j][k][c]);
		if (eq) {
			i ^= (1 << k);
			j ^= (1 << k);
		}
	}
	return hashes[i][0][0] < hashes[j][0][0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Precompute "hash of prefix of length 2^t, of string xorred by x" for every x, t
	// Then loop all options, and compare

	int h;
	cin >> h;
	int n = (1 << h);

	for (int c = 0; c < C; ++c) {
		mults[0][c] = rand(2u, P - 2);
		for (int j = 1; j <= h; ++j) mults[j][c] = ((ull)mults[j-1][c] * mults[j-1][c]) % P;
	}

	string str;
	cin >> str;
	for (int i = 0; i < n; ++i) {
		for (int c = 0; c < C; ++c) hashes[i][0][c] = str[i];
	}
	for (int k = 1; k <= h; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int c = 0; c < C; ++c) hashes[i][k][c] = ((ull)hashes[i][k - 1][c] * mults[k - 1][c] + hashes[i ^ (1 << (k - 1))][k - 1][c]) % P;
		}
	}

	int i = 0;
	for (int j = 1; j < n; ++j) {
		if (! compare(i, j, h)) i = j;
	}
	for (int j = 0; j < n; ++j) cout << str[i ^ j];
	cout << '\n';
}