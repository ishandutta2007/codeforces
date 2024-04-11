#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b, l, r;

int main() {
	cin >> a >> b;
	l = 1, r = a;
	l = max(l, b - a);
	r = min(r, b);
	ll ans = (r - l + 1);
	if(b / 2 <= a && b % 2 == 0) ans--;
	cout << max((ll)0, ans / 2) << endl;
	return 0;
}