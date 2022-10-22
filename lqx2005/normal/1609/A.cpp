#include <bits/stdc++.h>
#define broken cerr << "running on " << __FUNCTION__ <<" "<< __LINE__ << endl
#define x first
#define y second
#define sz(a) int((a).size())
#define ll long long
#define ull unsigned long long
using namespace std;
const int N = 1e5 + 10;
int t;
int n, a[N];

void solve() {
	cin >> n;
	ll p2 = 1;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		while(a[i] % 2 == 0) p2 *= 2, a[i] /= 2;
	}
	sort(a + 1, a + n + 1);
	ll sum = p2 * a[n];
	for(int i = 1; i < n; i++) sum += a[i];
	cout << sum << endl;
	return;
}

int main() {
	for(cin >> t; t--; solve());
	return 0;
}