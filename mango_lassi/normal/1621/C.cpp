#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
T rand(T a, T b) {
	return uniform_int_distribution<T>(a, b)(rng);
}
template<class T>
T rand() {
	return uniform_int_distribution<T>()(rng);
}

vector<int> p, q, tmp;
*/

int ask(int i) {
	/*
	int res = q[i];
	for (int j = 0; j < tmp.size(); ++j) tmp[j] = q[p[j]];
	swap(tmp, q);
	*/

	cout << "? " << i + 1 << endl;
	int res;
	cin >> res;
	--res;
	return res;

}
void answer(const vector<int>& vec) {
	/*
	for (int i = 0; i < vec.size(); ++i) {
		assert(vec[i] == p[i]);
	}
	*/
	cout << "!";
	for (int v : vec) cout << ' ' << v + 1;
	cout << endl;
}

void solve() {
	int n;
	cin >> n;

	/*
	p.resize(n);
	q.resize(n);
	tmp.resize(n);
	for (int i = 0; i < n; ++i) p[i] = i;
	for (int i = 0; i < n; ++i) q[i] = i;
	for (int i = 0; i < n; ++i) tmp[i] = i;
	shuffle(p.begin(), p.end(), rng);
	shuffle(q.begin(), q.end(), rng);
	*/

	int s = 0; // # Operations made so far
	vector<int> cyc_pos(n, -1); // This value appeared as the ith value in its cycle
	vector<int> cyc_ind(n, -1); // This value appeared in the ith cycle
	vector<int> cyc_len; // This cycle is this long
	vector<int> cyc_s0; // s when we first handled this cycle
	vector<vector<int>> pos;
	for (int i = 0; i < n; ++i) {
		int v = ask(i);
		++s;
		if (cyc_pos[v] == -1) {
			int ind = 0;
			int ci = cyc_s0.size();
			cyc_len.push_back(0);
			cyc_s0.push_back(s);
			while(cyc_pos[v] == -1) {
				cyc_pos[v] = ind;
				cyc_ind[v] = ci;
				++cyc_len.back();
				++ind;

				v = ask(i);
				++s;
			}
			pos.emplace_back(cyc_len.back(), -1);
		}

		int ci = cyc_ind[v];
		int shift = (s - cyc_s0[ci]) % cyc_len[ci]; // Steps elapsed since we started reading the cycle
		int ind = (cyc_pos[v] + cyc_len[ci] - shift) % cyc_len[ci];

		// Value appeared t'th on the cycle
		pos[ci][ind] = i;
	}

	vector<int> res(n, -1);
	for (int ci = 0; ci < pos.size(); ++ci) {
		for (int j = 0; j < pos[ci].size(); ++j) {
			int i = pos[ci][j];
			int t = pos[ci][(j + 1) % cyc_len[ci]];
			assert(i != -1);
			res[i] = t;
		}
	}
	answer(res);
}

int main() {
	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}