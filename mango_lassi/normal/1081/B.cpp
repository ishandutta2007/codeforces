#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

const int N = 1e5;
int group[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> inp(n);
	for (int i = 0; i < n; ++i) {
		cin >> inp[i].first;
		inp[i].second = i;
	}
	sort(inp.begin(), inp.end());

	bool fail = false;
	int gs = (inp[0].first == n-1 ? 1 : 0);;
	int cc = (inp[0].first == n-1 ? 0 : 1);
	for (int i = 1; i < n; ++i) {
		if (inp[i].first != inp[i-1].first) {
			if (cc != 0) fail = true;
			cc = 0;
			++gs;
		}

		group[inp[i].second] = gs;
		++cc;
		if (cc == n - inp[i].first) {
			cc = 0;
			++gs;
		}
	}
	if (cc != 0) fail = true;


	if (fail) {
		cout << "Impossible\n";
	} else {
		cout << "Possible\n";
		for (int i = 0; i < n; ++i) {
			cout << group[i] + 1 << ' ';
		}
		cout << '\n';
	}
}