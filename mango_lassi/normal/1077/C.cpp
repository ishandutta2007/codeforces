#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int V = 1 + (int)1e6;
const int N = 2 * (int)1e5;
int cou[V];
int els[N];

int main() {
	int n;
	cin >> n;
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> els[i];
		++cou[els[i]];
		sum += els[i];
	}

	vector<int> res;
	for (int i = 0; i < n; ++i) {
		sum -= els[i];
		--cou[els[i]];
		if ((sum % 2 == 0) && (sum / 2 < V) && (cou[sum / 2] > 0)) res.push_back(i+1);
		++cou[els[i]];
		sum += els[i];
	}

	cout << res.size() << '\n';
	for (auto it : res) cout << it << ' '; cout << '\n';
}