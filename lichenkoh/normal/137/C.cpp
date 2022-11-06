#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <array>
#include <iomanip>
#define ll unsigned long long
#define PI atan(1)*4
using namespace std;
bool myfn( const pair<ll, ll>& i, const pair<ll,ll>& j ) {
    return i.first < j.first;
}

int main() {
	ll n;
	cin >> n;
	pair<ll,ll> *a = new pair<ll,ll>[n];
	for (ll i = 0; i < n; i++) {
		ll x,y;
		cin >> x;
		cin >> y;
		a[i].first = x;
		a[i].second = y;
	}
	sort(a,a+n,myfn);
	ll mend = 0;
	ll ans = 0;

	for (ll i = 0; i < n; i++) {
		//cout << a[i].first << ":" << a[i].second << endl;
		ll end = a[i].second;
		if (end < mend) {
			ans++;
		}
		else {
			mend = end;
		}
	}
	cout << ans << endl;
	return 0;



}