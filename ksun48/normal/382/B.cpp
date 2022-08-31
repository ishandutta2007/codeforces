#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	using ll = long long;
	using i128 = __int128_t;
	ll _a, _b, _w, _x, _c;
	cin >> _a >> _b >> _w >> _x >> _c;
	i128 a, b, w, x, c;
	a = _a; b = _b; w = _w; x = _x; c = _c;
	i128 s = -1;
	i128 e = 1e18;
	auto mmod = [&](i128 r, i128 m) -> i128{
		ll g = r % m;
		if(g < 0) g += m;
		return (r - g) / m;
	};
	while(s + 1 < e){
		i128 m = (s + e) / 2;
		i128 cc = c - m;
		i128 cb = b - m * x;
		i128 ca = a - (mmod(b, w) - mmod(cb, w));
		if(cc <= ca){
			e = m;
		} else {
			s = m;
		}
	}
	cout << (ll)(e) << '\n';
}