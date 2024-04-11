#include <iostream>
#define ll long long
#define COL 100009
using namespace std;
int main() {
	ll n;
	cin >> n;
	ll *x = new ll[n];
	ll *y = new ll[n];
	for (ll i = 0; i < n; i++) {
		cin >> x[i];
		cin >> y[i];
	}
	ll *count = new ll[COL];
	for (ll i = 0; i < COL; i++) {
		count[i] = 0;
	}
	for (ll i = 0; i < n; i++) {
		ll k = x[i];
		count[k]++;
	}
	for (ll i = 0; i < n; i++) {
		ll home = n-1;
		ll away = n-1;
		ll change = count[y[i]];
		home += change;
		away -= change;
		cout << home << " " << away << endl;
	}
	return 0;
}