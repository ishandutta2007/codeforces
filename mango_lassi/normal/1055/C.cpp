#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 1 2 4
	// 0 0 6

	ll al, ar, at;
	ll bl, br, bt;
	cin >> al >> ar >> at;
	cin >> bl >> br >> bt;
	
	ll gd = gcd(at, bt);
	
	ll a_cou = al / gd;
	al -= a_cou * gd;
	ar -= a_cou * gd;
	
	ll b_cou = bl / gd;
	bl -= b_cou * gd;
	br -= b_cou * gd;

	ll res = 0;
	res = max(res, min(ar, br) - max(al, bl) + 1);
	res = max(res, min(ar + gd, br) - max(al + gd, bl) + 1);
	res = max(res, min(ar, br + gd) - max(al, bl + gd) + 1);
	cout << res << '\n';
}