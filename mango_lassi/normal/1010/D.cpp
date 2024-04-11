#include <iostream>
#include <string>
using namespace std;

const int N = (int)1e6 + 10;
const int IN = 4;
const int NOT = 3;
const int XOR = 2;
const int OR = 1;
const int AND = 0;

int tp[N];
int cs[N][2]; // Children
int val[N];
int ans[N];

int dfs(int i, int sv, int xv) {
	// cout << "dfs(" << i << ' ' << sv << ' ' << xv << ")\n";
	if (tp[i] == IN) {
		if (sv != -1) {
			ans[i] = sv;
		} else {
			ans[i] = 1 ^ cs[i][0] ^ xv;
		}
	} else if (tp[i] == NOT) {
		dfs(cs[i][0], sv, xv ^ 1);
	} else {
		for (int j = 0; j < 2; ++j) {

			int oth = j^1;
			if (sv != -1) {
				dfs(cs[i][j], sv, xv);
			} else if (tp[i] == XOR) {
				dfs(cs[i][j], sv, xv ^ val[cs[i][oth]]);
			} else {
				if (tp[i] == OR && val[cs[i][oth]] == 1) {
					dfs(cs[i][j], 1 ^ xv, xv);
				} else if (tp[i] == AND && val[cs[i][oth]] == 0) {
					dfs(cs[i][j], 0 ^ xv, xv);
				} else {
					dfs(cs[i][j], sv, xv);
				}
			}
		}
	}
}

int build(int i) {
	if (tp[i] == IN) {
		val[i] = cs[i][0];
	} else if (tp[i] == NOT) {
		val[i] = 1 ^ build(cs[i][0]);
	} else if (tp[i] == XOR) {
		val[i] = build(cs[i][0]) ^ build(cs[i][1]);
	} else if (tp[i] == OR) {
		val[i] = build(cs[i][0]) | build(cs[i][1]);
	} else if (tp[i] == AND) {
		val[i] = build(cs[i][0]) & build(cs[i][1]);
	}
	return val[i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string op;
		cin >> op;
		if (op == "AND") {
			tp[i] = AND;
			cin >> cs[i][0] >> cs[i][1];
		} else if (op == "OR") {
			tp[i] = OR;
			cin >> cs[i][0] >> cs[i][1];
		} else if (op == "XOR") {
			tp[i] = XOR;
			cin >> cs[i][0] >> cs[i][1];
		} else if (op == "NOT") {
			tp[i] = NOT;
			cin >> cs[i][0];
		} else if (op == "IN") {
			tp[i] = IN;
			cin >> cs[i][0];
		}
		if (tp[i] != IN) {
			--cs[i][0]; --cs[i][1];
		}
	}

	build(0);
	dfs(0, -1, 0);

	for (int i = 0; i < n; ++i) {
		if (tp[i] == IN) cout << ans[i];
	}
	cout << '\n';
}