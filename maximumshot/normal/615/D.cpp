#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

const ll base = inf + 7;

ll binpow(ll n, ll p) {
	if(p == 0) return 1ll;
	ll q = binpow(n, p / 2);
	q = (q * q) % base;
	if(p % 2) q = (q * n) % base;
	return q;
}

bool solve() {

	int n;
	scanf("%d", &n);

	vec< int > p(n);
	for(int i = 0;i < n;i++) {
		scanf("%d", &p[i]);
	}

	sort(ALL(p));

	vec< int > T;
	vec< pii > a;
	
	for(int i = 0;i < n;i++) {
		int j = i;
		while(j < n && p[i] == p[j]) j++; j--;
		T.push_back(j - i + 2);
		a.push_back(mp(p[i], j - i + 1));
		i = j;
	}

	ll ans = 1;
	ll value = 1;

	vec< ll > ost;

	for(auto i : a) {
		ll ch = i.first;
		ll st = i.second;
		if(st % 2 == 0) {
			st /= 2;
			value = (value * binpow(ch, st)) % base;
		}else {
			st /= 2;
			value = (value * binpow(ch, st)) % base;
			ost.push_back(ch);
		}
	}

	for(int i = 0;i < (int)T.size();i++) {
		value = binpow(value, T[i]);
	}

	ans = (ans * value) % base;

	for(int i = 0;i < (int)T.size();i++) {
		if(T[i] % 2 == 0) {
			T[i] /= 2;
			break;
		}
	}

	value = 1ll;

	for(auto i : ost) value = (value * i) % base;
 
	for(int i = 0;i < (int)T.size();i++) {
		value = binpow(value, T[i]);
	}

	ans = (ans * value) % base;

	cout << ans << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}