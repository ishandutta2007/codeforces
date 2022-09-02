#include <iostream>
#include <vector>
using namespace std;

const int N = 1e7;
int as[N];
int cou [N];
int zero [N];
int one [N];
int pre[N];
int used = 0;

int make_new(int curr) {
	cou[used] = 0;
	zero[used] = -1;
	one[used] = -1;
	pre[used] = curr;
	++used;
	return used - 1;
}
int go_zero(int i) {
	if (zero[i] == -1) zero[i] = make_new(i);
	return zero[i];
}
int go_one(int i) {
	if (one[i] == -1) one[i] = make_new(i);
	return one[i];
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> as[i];
	}
	int root = make_new(-1);
	for (int i = 0; i < n; ++i) {
		int pat;
		cin >> pat;
		int node = root;
		for (int j = 29; j >= 0; --j) {
			if (pat & (1<<j)) {
				node = go_one(node);
			} else {
				node = go_zero(node);
			}
		}
		while(node != -1) {
			++cou[node];
			node = pre[node];
		}
	}
	for (int i = 0; i < n; ++i) {
		int res = 0;
		int val = as[i];
		int node = root;
		for (int j = 29; j >= 0; --j) {
			if (val & (1<<j)) {
				if (one[node] != -1) {
					node = one[node];
				} else {
					node = zero[node];
					res += (1<<j);
				}
			} else {
				if (zero[node] != -1) {
					node = zero[node];
				} else {
					node = one[node];
					res += (1<<j);
				}
			}
		}
		cout << res << ' ';
		while(node != -1) {
			--cou[node];
			if (zero[node] != -1 && cou[zero[node]] == 0) zero[node] = -1;
			if (one[node] != -1 && cou[one[node]] == 0) one[node] = -1;
			node = pre[node];
		}
	}
	cout << '\n';
}