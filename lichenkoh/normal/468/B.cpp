#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <stdio.h>
#include <assert.h>
#define INTMAX 922337203685477580LL
#define ll long long
using namespace std;

int main() {
	ll n, a, b;
	cin >> n; cin >> a; cin >> b;
	map<ll,ll> s;
	ll *p = new ll[n];
	ll *q = new ll[n];
	for (ll i = 0; i < n; i++) {
		ll g;
		cin >> g;
		p[i] = g;
		s[g] = i;
	}
	for (ll k = 0; k < n; k++) {
		ll x = p[k];
		map<ll,ll>::iterator it = s.find(x);
		if (it != s.end()) {
			ll xi = s[x];
			vector<ll> chain[2];
			s.erase(it);
			for (ll j = 0; j < 2; j++) {
				bool isa = (j == 1);
				ll y = x;
				while(1) {
					if (isa) {y = a-y;}
					else {y = b-y;}
					if (isa) {isa = false;} else {isa = true;}
					it = s.find(y);
					if (it != s.end()) {
						assert(0 <= s[y] && s[y] < n);
						chain[j].push_back(s[y]);
						s.erase(it);
					}
					else {break;}
				}
			}
			
			vector<ll> line;
			for (vector<ll>::reverse_iterator it = chain[0].rbegin(); it != chain[0].rend(); ++it) {
				line.push_back(*it);
			}
			line.push_back(xi);
			for (ll i = 0; i < chain[1].size(); i++) {
				assert(0 <= i && i < chain[1].size());
				line.push_back(chain[1][i]);
			}
			
			bool ok[2];
			ok[0] = false; ok[1] = false;
			for (ll j = 0; j < 2; j++) {
				ll c;
				if (j == 0) {c = a;} else {c = b;}
				ll lsize = line.size();
				if (lsize % 2 == 0) {
					ok[j] = true;
					for (ll i = 0; (i+1) <= (lsize-1); i+=2) {
						assert(0 <= (i+1) && (i+1) < line.size());
						assert(0 <= line[i+1] && line[i+1] < n);
						assert(0 <= line[i] && line[i] < n);
							if (p[line[i+1]] == c - p[line[i]]) {
								q[line[i]] = j;
								q[line[i+1]] = j;
							}
					}
				}
				else {
					ll z = p[line[lsize-1]];
					if (z == a-z || z == b-z) {
						ok[j] = true;
						for (ll i = 0; (i+1) <= (lsize-2); i+=2) {
							assert(0 <= (i+1) && (i+1) < line.size());
							if (p[line[i+1]] == c - p[line[i]]) {
								q[line[i]] = j;
								q[line[i+1]] = j;
							}
						}
						if (z == a-z) {
							q[line[lsize-1]] = 0;
						}
						if (z == b-z) {
							q[line[lsize-1]] = 1;
						}
					}
					z = p[line[0]];
					if (z == a-z || z == b-z) {
						ok[j] = true;
						for (ll i = 1; (i+1) <= (lsize-1); i+=2) {
							assert(0 <= (i+1) && (i+1) < line.size());
							if (p[line[i+1]] == c - p[line[i]]) {
								q[line[i]] = j;
								q[line[i+1]] = j;
							}
						}
						if (z == a-z) {
							q[line[0]] = 0;
						}
						if (z == b-z) {
							q[line[0]] = 1;
						}
					}
				}
			}
			if (ok[0] == false && ok[1] == false) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	cout << q[0];
	for (ll i = 1; i < n; i++) {
		printf(" %ld", (long)q[i]);
	}
	cout << endl;
	return 0;
}