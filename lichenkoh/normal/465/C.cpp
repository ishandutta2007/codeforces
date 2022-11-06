#include <iostream>
#include <algorithm>
#include <stdlib.h>

#define ll long long
using namespace std;

void f(ll *t, ll p, ll n) {
	for (ll i = n-1; i >= 0; i--) {
		t[i] = (t[i] + 1) % p;
		if (t[i] == 0) {
			if (i == 0) {
				cout << "NO" << endl;
				exit(0);
			}
		}
		else {
			break;
		}
	}
	for (ll i = 1; i < n; i++) {
		if (
			(i >= 2 && (t[i] == t[i-1] || t[i] == t[i-2])) ||
			(i == 1 && t[i] == t[i-1])
			)
		{
			f(t, p, i+1);
			for (ll k = i+1; k < n; k++) {
				for (ll c = 0; c < p; c++) {
					if (
						(k >= 2 && (c != t[k-1] && c!= t[k-2])) ||
						(k == 1 && c != t[k-1])
						)
					{
						t[k] = c;
						break;
					}
					else if (c == p-1) {
						cout << "NO" << endl;
						exit(0);
					}
				}
			}
			return;
		}
	}
}

int main() {
	ll n, p;
	cin >> n;
	cin >> p;
	string s;
	cin >> s;
	ll *t = new ll[n];
	for (ll i = 0; i < n; i++) {
		t[i] = s[i] - 'a';
	}
	f(t, p, n);
	for (ll i = 0; i < n; i++) {
		s[i] = t[i] + 'a';
	}
	cout << s << endl;
	return 0;
}