/**
 *    author:  Mohamed.Abo_Okail
 *    created: 30/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"
 
int main()
{
	std::ios_base::sync_with_stdio(0);
	ll a, b, c, d, x, y, ans = 0;
	cin >> a >> b >> c >> d >> x >> y;
	if(x < y) {
		ll f = min(b, min(c, d));
		ans += (f * y);
		b -= f; c -= f; d -= f;
		f = min(a, d);
		ans += (f * x);
	}
	else {
		ll f = min(a, d);
		ans += (f * x);
		d -= f;
		f = min(b, min(c, d));
		ans += (f * y);
	}
	cout << ans << endl;
}