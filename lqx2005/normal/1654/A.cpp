#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define x first
#define y second
typedef long long ll;
typedef unsigned long long ull;
void solve() {
	int n;
	cin >> n;
	int f = 0, s = 0;
	for(int i = 0, x; i < n; i++) {
		cin >> x;
		if(f < x) s = f, f = x;
		else s = max(s, x);
	}
	cout << f + s << endl;
	return;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	for(cin >> t; t--; ) {
		solve();
	}
    return 0;
}