#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 10;

vector<int> move(vector<int> inds) {
	cout << "next";
	for (auto v : inds) cout << ' ' << v;
	cout << endl;

	int cou = 0;
	vector<int> ans(N, -1);
	for (int j = 0; cou < N; ++j) {
		string str;
		cin >> str;
		for (char c : str) ans[c - '0'] = j;
		cou += str.size();
	}
	return ans;
}

int main() {
	vector<int> all(N);
	for (int i = 0; i < N; ++i) all[i] = i;

	while(true) {
		move({0});
		auto g = move({0, 1});
		if (g[0] == g[1]) break;
	}
	// k - t = 2k - t (mod c)	// Times traveled in the cycle is same for 0 and 1
	// k = 0 (mod c)		// Therefore length of cycle divides the number of steps done
	// k - t + t = 0 = t - t (mod c)// Therefore moving t steps with all will land them at pos 0 of cycle
	while(true) {
		auto g = move(all);
		if (g[0] == g[2]) break;
	}
	cout << "done" << endl;
}