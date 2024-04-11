#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

bool solve() {
	 
	ll n;

	cin >> n;

	if(n == 0) cout << "0 0\n";
	else if(n == 1) cout << "1 2\n";
	else if(n == 2) cout << "-1 2\n";
	else if(n == 3) cout << "-2 0\n";
	else if(n == 4) cout << "-1 -2\n";
	else if(n == 5) cout << "1 -2\n";
	else if(n == 6) cout << "2 0\n";
	else {
		n++;

		ll s, k;

		ll bl, br, bm;

		bl = 1, br = inf;

		while(br - bl > 1) {
			bm = (bl + br) / 2;
			if(1 + 3 * bm * (bm - 1) <= n) bl = bm;
			else br = bm - 1;
		}

		k = (1 + 3 * br * (br - 1) <= n?br : bl);
		s = 1 + 3 * k * (k - 1);

		if(s == n) {
			cout << (k - 1) * 2ll << " 0\n";
			return true;
		}
		
		ll a = k + 1;
		ll x, y;

		s++;
		x = (k - 1) * 2 + 1;
		y = 2;

		if(s + a - 2 >= n) {
			ll delt = n - s;
			x = x - delt;
			y = y + 2 * delt;
			cout << x << " " << y << "\n";
			return true;
		} 

		x = x - (a - 2);
		y = y + 2 * (a - 2);
		s += a - 2;

		if(s + a - 1 >= n) {
			ll delt = n - s;
			x = x - 2 * delt;
			cout << x << " " << y << "\n";
			return true;
		}

		x = x - 2 * (a - 1);
		s += a - 1;

		if(s + a - 1 >= n) {
			ll delt = n - s;
			x = x - delt;
			y = y - 2 * delt;
			cout << x << " " << y << "\n";
			return true;
		}

		x = x - (a - 1);
		y = y - 2 * (a - 1);
		s += a - 1;

		if(s + a - 1 >= n) {
			ll delt = n - s;
			x = x + delt;
			y = y - 2 * delt;
			cout << x << " " << y << "\n";
			return true;
		}

		x = x + (a - 1);
		y = y - 2 * (a - 1);
		s += a - 1;

		if(s + a - 1 >= n) {
			ll delt = n - s;
			x = x + 2 * delt;
			cout << x << " " << y << "\n";
			return true;
		}

		x = x + 2 * (a - 1);
		s += a - 1;

		if(s + a - 1 >= n) {
			ll delt = n - s;
			x = x + delt;
			y = y + 2 * delt;
			cout << x << " " << y << "\n";
			return true;
		}
	}

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}