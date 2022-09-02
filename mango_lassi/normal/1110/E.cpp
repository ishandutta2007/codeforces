#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	bool a_match = true;
	vector<ll> src(n);
	vector<ll> tar(n);
	for (int i = 0; i < n; ++i) cin >> src[i];
	for (int i = 0; i < n; ++i) cin >> tar[i];
	if (src[0] != tar[0]) a_match = false;

	for (int i = 0; i+1 < n; ++i) src[i] = src[i+1] - src[i];
	for (int i = 0; i+1 < n; ++i) tar[i] = tar[i+1] - tar[i];
	src.pop_back();
	tar.pop_back();
	sort(src.begin(), src.end());
	sort(tar.begin(), tar.end());

	if (src == tar && a_match) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}