#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxm = 1000005;

int n, m;
ll k;
int m1[Maxm], m2[Maxm];

void gcd(ll A, ll &x, ll B, ll &y, ll &G)
{
	if (A == 0) { x = 0; y = 1; G = B; }
	else {
		ll xx, yy;
		gcd(B % A, xx, A, yy, G);
		x = yy - B / A * xx;
		y = xx;
	}
}

ll Same(ll D)
{
	if (D == 0) return 0;
	ll X, Y, G; gcd(n, X, m, Y, G);
	ll lcm = n / G * m;
	ll res = 0;
	for (int i = 0; i < Maxm; i++) if (m1[i] != -1 && m2[i] != -1)
		if (m1[i] == m2[i]) {
			ll fir = m1[i];
			if (fir + 1 > D) continue;
			res += 1 + (D - fir - 1) / lcm;
		} else {
			ll myX = X, myY = Y;
			ll myn = n, mym = m;
			ll nd = m2[i] - m1[i];
			if (nd < 0) {
				swap(myX, myY);
				swap(myn, mym);
				nd = -nd;
			}
			if (nd % G) continue;
			myX *= (nd / G);
			myX %= (mym / G);
			if (myX < 0) myX += (mym / G);
			ll fir = myn * myX + min(m1[i], m2[i]);
			if (fir + 1 > D) continue;
			res += 1 + (D - fir - 1) / lcm;
		}
	return res;
}

int main()
{
	scanf("%d %d %I64d", &n, &m, &k);
	fill(m1, m1 + Maxm, -1);
	fill(m2, m2 + Maxm, -1);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		m1[a] = i;
	}
	for (int i = 0; i < m; i++) {
		int a; scanf("%d", &a);
		m2[a] = i;
	}
	ll lef = 0, rig = 4000000000000000000ll;
	while (lef <= rig) {
		ll mid = lef + rig >> 1;
		if (mid - Same(mid) >= k) rig = mid - 1;
		else lef = mid + 1;
	}
	cout << lef << endl;
    return 0;
}