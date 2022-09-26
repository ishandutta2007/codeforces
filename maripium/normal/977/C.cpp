#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;

int n, k;
vector<int> a;
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0;i < n;++i) {
		int xx; cin >> xx;
		a.push_back(xx);
	}
	sort(a.begin(), a.end());
	if (k == 0 && a[0] == 1) cout << -1 << endl; 
	else if (k == 0) cout << 1 << endl;
	else if (k == n) cout << a[n - 1];
	else if (a[k - 1] == a[k]) return cout << -1 << endl,0;
	else cout << a[k - 1];
	// int p1 = lower_bound(a.begin(), a.end(), a[k]) - a.begin();
	// int p2 = upper_bound(a.begin(), a.end(), a[k]) - a.begin();
}