#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;
const ld pi = 3.1415926535897932384626433832795;

int ret = 0;

ll binpow(ll n, ll p) {
	if(p == 0) return 1ll % base;
	ll q = binpow(n, p / 2);
	q = (q * q) % base;
	if(p % 2) return (q * n) % base;
	else return q;
}

ll fast(ll p, ll k) {
	
	if(k == 0) {
		return binpow(p, p - 1);
	}

	vec< ll > c(p + 1);
	vec< char > vis(p, 0);
	queue< ll > q;

	for(ll x = 0;x < p;x++) {
		if(vis[x]) continue;
		vis[x] = 1;
		q.push(x);
		ll cnt = 1;
		while(!q.empty()) {
			ll v = q.front();
			q.pop();
			ll to = v * k % p;
			if(!vis[to]) {
				q.push(to);
				vis[to] = 1;
				cnt++;
			}
		}
		c[cnt]++;
	}

	vec< ll > ans(p + 1, 0);

	for(ll i = 1;i <= p;i++) {
		for(ll j = i;j <= p;j += i) {
			ans[j] = (ans[j] + i * c[i] % base) % base;
		}
	}
	
	ll answer = 1ll;

	for(ll i = 1;i <= p;i++) {
		for(ll j = 0;j < c[i];j++) {
			answer = (answer * ans[i]) % base;
		}
	}

	return answer;
}

bool solve() {

	ll p, k;

	cin >> p >> k;

	if(k == 0) {
		ret = 1;
	}

	cout << fast(p, k) << '\n';

	return true;
} 

int main() {
	
	//while(solve());
	solve();

	return 0;
}