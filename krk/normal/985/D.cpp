#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll lim = 2000000000ll;

ll n, H;

bool Ok(ll x)
{
	if (x <= H)
		if (x >= lim) return true;
		else return x * (x + 1) / 2 >= n;
	if ((x - H) % 2 == 0) {
		ll A = (x - H) / 2 + H;
		if (A >= lim) return true;
		return A * (A + 1) / 2 + (A - 1 + H) * (A - H) / 2 >= n;
	} else {
		ll A = (x - H) / 2 + H;
		if (A >= lim) return true;
		return A * (A + 1) / 2 + (A + H) * (A + 1 - H) / 2 >= n;
	}
}

int main()
{
	cin >> n >> H;
	ll lef = 1, rig = n;
	while (lef <= rig) {
		ll mid = lef + rig >> 1ll;
		if (Ok(mid)) rig = mid - 1;
		else lef = mid + 1;
	}
	cout << rig + 1 << endl;
	return 0;
}