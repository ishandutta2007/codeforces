#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int V = 1 + 2 * (int)1e5;
int cou[V];

vector<int> gen(int s, int k) {
	vector<int> res;
	for (int v = 1; (v < V) && (res.size() < k); ++v) {
		for (int j = s; (j <= cou[v]) && (res.size() < k); j += s) res.push_back(v);
	}
	if (res.size() < k) return {};
	else return res;
}

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		++cou[v];
	}

	int low = 1;
	int high = n;
	while(low != high) {
		int mid = (low + high + 1) >> 1;
		vector<int> lol = gen(mid, k);
		if (lol.size() > 0) low = mid;
		else high = mid - 1;
	}

	vector<int> res = gen(low, k);
	for (auto v : res) cout << v << ' '; cout << '\n';
}