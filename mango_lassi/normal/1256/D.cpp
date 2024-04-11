#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

void solve() {
	ll n, k;
	cin >> n >> k;
	string str;
	cin >> str;

	int c = 0;
	for (int i = 0; i < n && k > 0; ++i) {
		if (str[i] == '1') ++c;
		else {
			int d = min((ll)c, k);
			k -= d;
			str[i] = '1';
			str[i-d] = '0';
		}
	}
	cout << str << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		solve();
	}
}