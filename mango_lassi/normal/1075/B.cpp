#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5;
int xs[2*N];
int ts[2*N];
int ans[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> taxis;
	for (int i = 0; i < n+m; ++i) cin >> xs[i];
	for (int i = 0; i < n+m; ++i) {
		cin >> ts[i];
		if (ts[i]) taxis.push_back(xs[i]);
	}

	int j = 0;
	for (int i = 0; i < n+m; ++i) {
		if ((j+1 < m) && (abs(taxis[j] - xs[i]) > abs(taxis[j+1] - xs[i]))) ++j;
		ans[j] += 1 - ts[i];
	}

	for (int i = 0; i < m; ++i) cout << ans[i] << ' '; cout << '\n'; 
}