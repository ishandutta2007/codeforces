#include <bits/stdc++.h>
#define sz(a) int((a).size())
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
ll n;
void solve() {
	cin >> n;
	n *= 2;
	ll a = n, b = 1;
	while(a % 2 == 0) b *= 2, a /= 2;
	if(a == 1) {
		cout << -1 << endl;
		return;
	}
	if(a > b) cout << b << endl;
	else cout << a << endl;
	return;
}
int main() {
	ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	for(cin >> t; t--; ) solve();
	return 0;
}