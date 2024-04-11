#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
#include <iomanip>
#include <queue>
#define ll long long
#define MAX_INT 922337203685477580LL
using namespace std;

int main() {
	string s;
	cin >> s;
	ll n = s.length();
	ll h = 0;
	ll sharp = 0;
	ll lastsharp = -1;
	for (ll i = 0; i < n; i++) {
		if (s[i] == '(') {
			h++;
		}
		else if (s[i] == ')') {
			h--;
		}
		else if (s[i] == '#') {
			h--;
			sharp++;
			lastsharp = i;
		}
		if (h < 0) {
			cout << -1 << endl;
			return 0;
		}
	}
	ll lastsharpminus = 1 + h;
	h = 0;
	for (ll i = 0; i < n; i++) {
		if (i == lastsharp) {
			h -= lastsharpminus;
		}
		else if (s[i] == '(') {
			h++;
		}
		else if (s[i] == ')') {
			h--;
		}
		else if (s[i] == '#') {
			h--;
		}
		if (h < 0) {
			cout << -1 << endl;
			return 0;
		}
	}
	for (ll i = 0; i < (sharp-1); i++) {
		cout << 1 << endl;
	}
	cout << lastsharpminus << endl;
	return 0;
}