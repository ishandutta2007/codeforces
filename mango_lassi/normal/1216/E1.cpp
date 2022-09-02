#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 7 + (ll)1e18;

ll mult(ll a, ll b) {
	if (a == 0 || b == 0) return 0;
	if (a >= INF || b >= INF || INF / a < b) return INF;
	return a * b;
}
ll arith(ll a, ll b) {
	if ((a + b) & 1) return mult(a + b, (b - a + 1) / 2);
	else return mult((a + b) / 2, b - a + 1);
}
ll count(ll v) {
	ll res = 0;
	for (ll m = 1, num = 1; num <= v; ++m, num = mult(num, 10)) {
		if (mult(10, num) <= v) res += mult(9*m, num);
		else res += mult(m, v - num + 1);
		if (res >= INF) return INF;
	}
	return res;
}
ll count2(ll v) {
	ll res = 0;
	for (ll m = 1, num = 1; num <= v; ++m, num = mult(num, 10)) {
		if (mult(10, num) <= v) res += mult(m, arith(v - (10*num-1) + 1, v - num + 1));
		else res += mult(m, arith(1, v - num + 1));
		if (res >= INF) return INF;
	}
	return res;
}
string strnum(ll v) {
	if (v == 0) return "0";
	string num;
	for (; v > 0; v /= 10) num.push_back('0' + (v % 10));
	reverse(num.begin(), num.end());
	return num;
}

void solve() {
	ll k;
	cin >> k;
	
	ll low = 0;
	ll high = 1e18;
	while(low != high) {
		ll mid = (low + high + 1) >> 1;
		ll off = count2(mid);
		if (off >= k) high = mid - 1;
		else low = mid;
	}
	k -= count2(low);

	low = 0;
	++high;
	while(low != high) {
		ll mid = (low + high + 1) >> 1;
		ll off = count(mid);
		if (off >= k) high = mid - 1;
		else low = mid;
	}
	k -= count(low);

	cout << strnum(high + 1)[k-1] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) solve();
}