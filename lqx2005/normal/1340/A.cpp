#include <bits/stdc++.h>
#define sz(a) int((a).size())
typedef long long i64;
using namespace std;
const int N = 1e5 + 10;
int T, n;
int a[N];

void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 2; i <= n; i++) {
		if(a[i] > a[i - 1] && a[i] != a[i - 1] + 1) {
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
	return;	
}

int main() {
	for(cin >> T; T--; ) {
		solve();
	}
	return 0;
}