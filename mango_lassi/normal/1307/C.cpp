#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int C = 26;
ll cou[C][C+1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;

	for (auto ch : str) {
		int c = ch - 'a';
		for (int pc = 0; pc < C; ++pc) cou[pc][c+1] += cou[pc][0];
		++cou[c][0];
	}

	ll res = 0;
	for (int pc = 0; pc < C; ++pc) {
		for (int c = 0; c <= C; ++c) res = max(res, cou[pc][c]);
	}
	cout << res << '\n';
}