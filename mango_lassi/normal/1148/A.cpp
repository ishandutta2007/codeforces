#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll a, b, ab;
	cin >> a >> b >> ab;
	if (a == b) cout << 2*ab + a + b << '\n';
	else cout << 2*ab + min(a, b) + min(a, b) + 1 << '\n';
}