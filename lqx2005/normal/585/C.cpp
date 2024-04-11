#include<bits/stdc++.h>

#define sz(a) int((a).size())
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef double db;
const int N = 100 + 20;

void solve(ll x, ll y, char a, char b) {
	if(x < y) return solve(y, x, b, a);
	if(x % y == 0) {
		cout << x - 1 << a;
		return;
	}
	cout << x / y << a;
	return solve(y, x % y, b, a);
}

int main() {
	ll x, y;
	cin >> x >> y;
	if(__gcd(x, y) > 1) {
		cout << "Impossible" << endl;
		return 0;
	}
	solve(x, y, 'A', 'B');
	return 0;
}