#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;
using ll = long long;

const int N = 100;
int ans[2*N][2*N];

bool ask(int a, int b, int n) {
	--a; --b;
	if (ans[a][b] == -1) {
		cout << "? " << a+1 << ' ' << b+1 << endl;
		char res;
		cin >> res;

		ans[a][b] = (res == '<');
		ans[b][a] = 1 - ans[a][b];
	}
	return ans[a][b];
}

void solve() {
	int n;
	cin >> n;
	for (int a = 0; a < 2*n; ++a) {
		for (int b = 0; b < 2*n; ++b) ans[a][b] = -1;
	}

	vector<int> ord(2*n);
	for (int i = 0; i < 2*n; ++i) ord[i] = i+1;

	random_shuffle(ord.begin(), ord.end()); // No purpose but to make testing easier

	int a = 0;
	int b = 2*n-1;
	while(a == 0 && b >= n) {
		// We need b-a+1 >= 4
		if (ask(ord[a], ord[b], 2*n)) swap(ord[a], ord[b]);
		if (ask(ord[a+1], ord[b-1], 2*n)) swap(ord[a+1], ord[b-1]);
		if (ask(ord[b-1], ord[b], 2*n)) {
			swap(ord[b-1], ord[b]);
		} else {
			swap(ord[a], ord[a+1]);
		}

		// Compare b to all
		vector<int> le, ri;
		for (int i = a; i < b; ++i) {
			if (ask(ord[i], ord[b], 2*n)) ri.push_back(ord[i]);
			else le.push_back(ord[i]);
		}
		ri.push_back(ord[b]);

		for (int j = 0; j < le.size(); ++j) ord[a+j] = le[j];
		for (int j = 0; j < ri.size(); ++j) ord[a+le.size()+j] = ri[j];

		if (a + le.size() <= n) {
			a += le.size();
		} else {
			b -= ri.size();
		}
	}
	if (a != 0) {
		for (int x = a; x < b; ++x) {
			for (int y = x+1; y < b; ++y) ask(ord[x], ord[y], 2*n);
		}
	}
	cout << "!" << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}