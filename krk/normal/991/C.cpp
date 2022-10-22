#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;

bool Check(ll k)
{
	ll lft = n;
	ll eaten = 0;
	while (lft > 0) {
		ll tk = min(lft, k);
		eaten += tk; lft -= tk;
		lft -= lft / 10;
	}
	return eaten >= n - eaten;
}

int main()
{
	cin >> n;
	ll lef = 1, rig = n;
	while (lef <= rig) {
		ll mid = lef + rig >> 1;
		if (Check(mid)) rig = mid - 1;
		else lef = mid + 1;
	}
	cout << rig + 1 << endl;
	return 0;
}