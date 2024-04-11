#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define INF 99999999999999999
//ll a[1000][1000];
ld e[1000],r[1000],p[1000][1000], s[1000];
bool seen[1000], touched[1000];
ll a[1000][1000];
int main() {
	ios_base::sync_with_stdio(false);
	std::cout << std::fixed;
  	std::cout << std::setprecision(100);
	ll n; cin >> n;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			cin >> a[i][j];
			p[i][j] = ((ld)a[i][j])/(ld(100));
		}
	}
	for (ll i = 0; i < n; i++) {
		touched[i] = false;
		s[i] = 0;
		r[i] = 1;
		e[i] = INF;
	}
	ll x = n-1;
	e[x] = 0;
	r[x] = 0;
	touched[x] = true;
	while (1) {
		seen[x] = true;
		ll y = -1;
		ld best = INF;
		for (ll i = 0; i < n; i++) {
			if (!seen[i]) {
				ld rhs = s[i];
				ld rem = r[i];
				rhs += e[x] * rem * p[i][x];
				s[i] = rhs;
				rem -= rem * p[i][x];
				r[i] = rem;
				if (a[i][x] > 0) {touched[i] = true;}
				if (touched[i]) {
					e[i] = (rhs+1) / (1-rem);
					if (e[i] < best) {
						best = e[i];
						y = i;
					}
				}
			}
		}
		if (y == -1) break;
		x=y;
	}
	//if (n == 1) {e[0] = 1;}
	cout << e[0] << endl;
}