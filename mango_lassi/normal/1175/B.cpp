#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MAXV = (1ll<<32);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	ll res = 0;
	vector<ll> stack = {1};
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		if (str == "add") {
			res += stack.back();
		} else if (str == "for") {
			ll k;
			cin >> k;
			stack.push_back(min(MAXV, k*stack.back()));
		} else if (str == "end") {
			stack.pop_back();
		}
	}
	if (res >= MAXV) cout << "OVERFLOW!!!\n";
	else cout << res << '\n';
}