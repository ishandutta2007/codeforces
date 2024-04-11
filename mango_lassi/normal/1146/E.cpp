#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

// Operations:
// 0: Do nothing
// 1: Flip if positive
// 2: Flip if negative
// 3. Flip

const int N = 1<<17;
int ops[2*N];

int applyOp(int v, int op) {
	if (op == 1) return (v > 0 ? -v : v);
	if (op == 2) return (v < 0 ? -v : v);
	if (op == 3) return -v;
	return v;
}

// Operation a, then b is c = joinOp(a, b)
int joinOp(int a, int b) {
	if (a == 0) return b;
	if (b == 0) return a;
	if (a == 3) {
		if (b == 3) return 0;
		else return b;
	} else if (b == 3) {
		return 3 - a;
	} else {
		if (a == b) return a;
		else return b;
	}
}

void setOp(int i, int op) {
	i += N;
	ops[i] = op;

	for (i >>= 1; i > 0; i >>= 1) {
		ops[i] = joinOp(ops[2*i], ops[2*i+1]);
	}
}

int ans[2*N+1];
int vals[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	for (int i = 0; i < n; ++i) cin >> vals[i];

	vector<pair<pair<int, int>, pair<char, int>>> ques;
	for (int j = 0; j < q; ++j) {
		char dir;
		int v;
		cin >> dir >> v;
		int ab = abs(v);
		if ((dir == '<') == (v < 0)) {
			setOp(j, 0);
			ab += 1;
		} else {
			setOp(j, 3);
		}
		ques.push_back({{ab, v},{dir, j}});
	}
	sort(ques.begin(), ques.end());

	// Apply operations and calculate answers by absolute value
	int v1 = 0;
	ques.push_back({{N+1, -1}, {0, q}});
	for (auto qu : ques) {
		int ab = qu.first.first;
		int v = qu.first.second;
		char dir = qu.second.first;
		int j = qu.second.second;
		while(v1 < ab) {
			ans[N + v1] = applyOp(v1, ops[1]);
			ans[N - v1] = applyOp(-v1, ops[1]);
			++v1;
		}
		if (j == q) break;

		if ((dir == '<') == (v < 0)) {
			if (v < 0) {
				setOp(j, 2);
			} else {
				setOp(j, 1);
			}
		} else {
			if (v < 0) {
				setOp(j, 1);
			} else {
				setOp(j, 2);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << ans[N + vals[i]] << ' ';
	}
	cout << '\n';
}