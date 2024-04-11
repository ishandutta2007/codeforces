#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int getInd(char c) {
	if (c == 'R') return 0;
	if (c == 'P') return 1;
	if (c == 'S') return 2;
	return -1;
}

const int N = 1<<18;
int fenw[N+1][3];

int fenwGet(int i, int j) {
	int res = 0;
	++i;
	while(i > 0) {
		res += fenw[i][j];
		i -= (i & -i);
	}
	return res;
}

int fenwGetInt(int a, int b, int j) {
	if (b < a) return 0;
	if (a == -1) return fenwGet(b, j);
	return fenwGet(b, j) - fenwGet(a-1, j);
}

void fenwAdd(int i, int v, int j) {
	++i;
	while(i <= N) {
		fenw[i][j] += v;
		i += (i & -i);
	}
}

int pick[N];
set<int> locs[3];

int getLeft(int j, int n) {
	if (locs[j].empty()) return n;
	auto it = locs[j].begin();
	return *it;
}

int getRight(int j, int n) {
	if (locs[j].empty()) return -1;
	auto it = locs[j].end();
	--it;
	return *it;
}

int getCont(int j, int n) {
	int ans = fenwGetInt(0, n-1, j);

	int loss_j = (j + 1) % 3;
	int loss_left = getLeft(loss_j, n);
	int loss_right = getRight(loss_j, n);

	int win_j = (j + 2) % 3;
	int win_left = getLeft(win_j, n);
	int win_right = getRight(win_j, n);

	ans -= fenwGetInt(loss_left + 1, win_left - 1, j);
	ans -= fenwGetInt(win_right + 1, loss_right - 1, j);

	return max(0, ans);
}

int setPick(int i, int j, int n) {
	int pre = pick[i];
	if (pre != -1) {
		locs[pre].erase(i);
		fenwAdd(i, -1, pre);
	}
	if (j != -1) {
		locs[j].insert(i);
		fenwAdd(i, 1, j);
	}
	pick[i] = j;

	int res = 0;
	for (int z = 0; z < 3; ++z) res += getCont(z, n);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	for (int i = 0; i < n; ++i) pick[i] = -1;
	
	string ini;
	cin >> ini;
	int res = 0;
	for (int i = 0; i < n; ++i) {
		res = setPick(i, getInd(ini[i]), n);
	}

	cout << res << '\n';
	for (int t = 0; t < q; ++t) {
		int i;
		char c;
		cin >> i >> c;
		--i;
		res = setPick(i, getInd(c), n);
		cout << res << '\n';
	}
}



















	// RSxxxxx -> R
	// PRxxxxx -> P
	// SRxxxxx -> S

	// RxxxxxS -> RS
	// PxxxxxR -> PR
	// SxxxxxR -> SR

	// A rock wins if on both sides of it, either
	// 	1. Exists a scissors
	// 	2. Exists no paper
	// Same symmetrically.

	// How to calculate amount of winning rocks?
	// find leftmost and rightmost paper, leftmost and rightmost scissors
	// rocks in intervals (leftmost_paper, leftmost_scissors) and (rightmost_scissors, rightmost_paper) don't win.
	// all other rocks win.

	// Fenwick trees for calculating number of rocks / papers / scissors in an interval, and sets for finding left / rightmost ones.