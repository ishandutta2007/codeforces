#include <bits/stdc++.h>
#include <complex>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define MOD 1000000007LL
#define PB push_back
#define UNDEF -1
int main() {
	ll n;
	cin >> n;
	ll *b = new ll[n];
	string *s = new string[n];
	bool **a = new bool*[n];
	for (ll i = 0; i < n; i++) {
		a[i] = new bool[26];
		for (ll j = 0; j < 26; j++) {
			a[i][j] = false;
		}
	}
	for (ll i = 0; i < n; i++) {
		cin >> s[i];
		b[i] = s[i].length();
	}
	for (ll i = 0; i < n; i++) {
		ll len = s[i].length();
		for (ll j = 0; j < len; j++) {
			ll k = s[i][j] - 'a';
			a[i][k] = true;
		}
	}
	ll best = 0;
	for (ll x = 0; x < 26; x++) {
		for (ll y = x+1; y < 26; y++) {
			ll cand = 0;
			for (ll i = 0; i < n; i++) {
				bool good = true;
				for (ll k = 0; k < 26; k++) {
					if (k == x || k == y) continue;
					if (a[i][k] == true) {
						good = false; break;
					}
				}
				if(good) cand+=b[i];
			}
			best = max(best,cand);
		}
	}
	cout << best << endl;
}