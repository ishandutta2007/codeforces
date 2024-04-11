/**
*    author:  Mohamed Abo Okail
*    created: 25/11/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n";
 
int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		deque < ll > a(n), b, c, d;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		c = a;
		ll x;
		while(sz(a)) {
			if(sz(a) == 1) {
				x = a.front();
				a.pop_front();
				break;
			}
			if(a.front() > a.back()) {
				b.push_front(a.front());
				a.pop_front();
			}
			else {
				b.push_back(a.back());
				a.pop_back();
			}
		}
		d = b;
		b.push_front(x);
		d.push_back(x);
		a = c;
		c.clear();
		deque < ll > aa, bb, cc;
		x = 0;
		bb = b;
		cc = d;
		while(sz(b)) {
			if(sz(b) == 1) {
				x = b.front();
				b.pop_front();
				break;
			}
			if(b.front() < b.back()) {
				aa.push_front(b.front());
				b.pop_front();
			}
			else {
				aa.push_back(b.back());
				b.pop_back();
			}
		}
		aa.push_back(x);
		if(a == aa) {
			for (int i = 0; i < sz(bb); i++) {
				cout << bb[i] << ' ';
			}
			cout << endl;
			continue;
		}
		aa.pop_back();
		aa.push_front(x);
		if(a == aa) {
			for (int i = 0; i < sz(bb); i++) {
				cout << bb[i] << ' ';
			}
			cout << endl;
			continue;
		}
		aa.clear();
		x = 0;
		while(sz(d)) {
			if(sz(d) == 1) {
				x = d.front();
				d.pop_front();
				break;
			}
			if(d.front() < d.back()) {
				aa.push_front(d.front());
				d.pop_front();
			}
			else {
				aa.push_back(d.back());
				d.pop_back();
			}
		}
		aa.push_back(x);
		if(a == aa) {
			for (int i = 0; i < sz(cc); i++) {
				cout << cc[i] << ' ';
			}
			cout << endl;
			continue;
		}
		aa.pop_back();
		aa.push_front(x);
		if(a == aa) {
			for (int i = 0; i < sz(cc); i++) {
				cout << cc[i] << ' ';
			}
			cout << endl;
			continue;
		}
		cout << -1 << endl;
	}
}