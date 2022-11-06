#include <iostream>
#include <cmath>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

#define LOOP -1000
#define UNHASHED -20
bool **seen;
ll **h;
ll *a;
ll n;
ll recur(ll x, ll b) {
	//cout << "Tr:" << x << endl;
	// Base Case
	if (x <= 0 || x > n) {
		return 0;
	}
	if (seen[b][x] && h[b][x] == UNHASHED) {
		return LOOP;
	}
	if (h[b][x] == LOOP) {
		return LOOP;
	}
	// Memo case
	if (h[b][x] != UNHASHED) {
		return h[b][x];
	}
	// Recursive case
	ll next = -999;
	seen[b][x] = true;
	if (b == 0) { //add
		next = recur(x+a[x],1);
		//cout << "x:" << x << " N:" << next << " NI:" << x+a[x] << endl;
	}
	else { //sub
		assert(b == 1);
		next = recur(x-a[x],0);
		//cout << "x:" << x << " N:" << next << " NI:" << x-a[x] << endl;
	}
	if (next == LOOP) {
		h[b][x] = LOOP;
		return LOOP;
	}
	h[b][x] = a[x] + next;
	return a[x] + next;
}

int main() {
	cin >> n;
	seen = new bool*[2];
	seen[0] = new bool[n+5];
	seen[1] = new bool[n+5];
	h = new ll*[2];
	h[0] = new ll[n+5];
	h[1] = new ll[n+5];
	a = new ll[n+5];
	for (ll i = 0; i < n+5; i++) {
		h[0][i] = UNHASHED;
		h[1][i] = UNHASHED;
	}
	for (ll j = 0; j < n+5; j++) {
		seen[0][j] = false;
		seen[1][j] = false;
	}
	for (ll i = 2; i <= n; i++) {
		cin >> a[i];
	}
	for (ll i = 1; i <= n-1; i++) {
		//cout << "Doing:" << i << endl;
		a[1] = i;
		h[0][1] = UNHASHED;
		seen[0][1] = false;
		ll ans = recur(1,0);
		if (ans == LOOP) {
			cout << -1 << endl;
		}
		else {
			cout << ans << endl;
		}
	}
}