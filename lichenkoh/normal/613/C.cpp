#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl "\n"
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define MAXN 100008
ll a[26];
ll n;
char s[MAXN];

ll solve() {
	ll numodd = 0;
	for (ll i = 0; i < n; i++) {
		if ((a[i]%2) != 0) {
			numodd++;
		}
	}
	if (numodd >= 2) {
		ll ans = 0;
		ll idx = 0;
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < a[i]; j++) {
				s[idx] = 'a'+i;
				idx++;
			}
		}
		s[idx] = '\0';
		return ans;
	}
	else {
		ll idx = 0;
		for (ll i = 0; i < n; i++) {
			if (a[i]%2 == 0) {
				for (ll j = 0; j < a[i]/2; j++) {
					s[idx] = 'a'+i;
					idx++;
				}
			}
		}
		ll k = idx;
		for (ll i = 0; i < k; i++) {
			s[k+i] = s[k-1-i];
			idx++;
		}
		for (ll i = 0; i < n; i++) {
			if ((a[i]%2) != 0) {
				for (ll j = 0; j < a[i]; j++) {
					s[idx] = 'a'+i;
					idx++;
				}
			}
		}
		s[idx] = '\0';
		ll ans = (numodd == 0) ? 2 : 1;
		return ans;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll gcd = a[0];
	for (ll i = 0; i < n; i++) {
		gcd = __gcd(gcd, a[i]);
	}
	if (gcd%2 == 0) gcd/=2;
	for (ll i = 0; i < n; i++) {
		a[i] /= gcd;
	}
	ll final = gcd * solve();
	printf("%I64d\n",final);
	for (ll i = 0; i < gcd; i++) printf("%s",s);
	printf("\n");

}