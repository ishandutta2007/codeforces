#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"

ll f(char c) {
	if (c == 'N') return 1;
	else if (c == 'S') return -1;
	else if (c == 'E') return 2;
	else if (c == 'W') return -2;
	assert(false);
}

int main() {
	ios_base::sync_with_stdio(false);
	ll n; cin >> n;
	n--;
	string as,bs; cin >> as; cin >> bs;
	ll *a = new ll[n+1];
	ll *b = new ll[n+1];
	a[n] = 0; b[n] = 0;
	for (ll i = 0; i < n; i++) {
		a[i] = f(as[i]);
		b[i] = f(bs[i]);
	}
	bool *xseen = new bool[n+1];
	bool *yseen = new bool[n+1];
	for (ll i = 0; i <= n; i++) {
		xseen[i] = false; yseen[i] = false;
	}
	bool good = false;
	ll x = 0; ll y = 0;
	while(1) {
		while(x < n) {
			if ((!(x >= 1 && b[y] == -a[x-1])) && y < n) y++;
			if (y < n && a[x] == b[y]) y++;
			else if (y >= 1 && a[x] == -b[y-1]) {
				y--;
			}
			x++;
			if ((!(x >= 1 && b[y] == -a[x-1])) && y < n) y++;
		}
		if (x == n && y == n) {
			good = true; break;
		}
		if (yseen[y]) {break;}
		yseen[y] = true;
		while(y < n) {
			if ((!(y >= 1 && a[x] == -b[y-1])) && x < n) x++;
			if (x < n && b[y] == a[x]) x++;
			else if (x >= 1 && b[y] == -a[x-1]) {
				x--;
			}
			y++;
			if ((!(y >= 1 && a[x] == -b[y-1])) && x < n) x++;
		}
		if (x == n && y == n) {
			good = true; break;
		}
		if (xseen[x]) {break;}
		xseen[x] = true;
	}
	if (good == true) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}