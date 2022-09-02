#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> makeVec(int a, int b, int n) {
	vector<int> vec(n, a);
	vec[n-1] = b;
	return vec;
}

int ask(const vector<int>& as) {
	cout << "?";
	for (int a : as) cout << ' ' << a;
	cout << endl;

	int r;
	cin >> r;
	return r - 1;
}


void solve() {
	int n;
	cin >> n;

	vector<int> pre_ind(n, -1), nxt_ind(n, -1);
	for (int s = 1, cur = n-1; s < n; ++s) {
		vector<int> as = makeVec(1, 1 + s, n);
		int nxt = ask(as);
		if (nxt == -1) break;
		else {
			nxt_ind[cur] = nxt;
			pre_ind[nxt] = cur;
			cur = nxt;
		}
	}

	for (int s = 1, cur = n-1; s < n; ++s) {
		vector<int> as = makeVec(1 + s, 1, n);
		int pre = ask(as);
		if (pre == -1) break;
		else {
			nxt_ind[pre] = cur;
			pre_ind[cur] = pre;
			cur = pre;
		}
	}

	int s = -1;
	for (int i = 0; i < n; ++i) {
		if (pre_ind[i] == -1) s = i;
	}

	vector<int> res(n);
	for (int v = 1; s != -1; s = nxt_ind[s], ++v) res[s] = v;

	cout << "!";
	for (int v : res) cout << ' ' << v;
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}