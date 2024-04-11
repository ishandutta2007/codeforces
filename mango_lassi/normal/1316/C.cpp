#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	ll p;
	cin >> n >> m >> p;

	vector<ll> as(n), bs(m);
	for (ll& v : as) cin >> v;
	for (ll& v : bs) cin >> v;

	int x = 0, y = 0;
	while(as[x] % p == 0) ++x;
	while(bs[y] % p == 0) ++y;
	cout << x + y << '\n';
}