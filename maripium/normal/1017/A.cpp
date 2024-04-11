#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n;
pair<int,int> aa[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		aa[i] = {-a - b - c - d, i};
	}
	sort(aa + 1, aa + 1 + n);
	for (int i = 1; i <= n; ++i) {
		if (aa[i].second == 1) {
			cout << i << '\n';
		}
	}
}