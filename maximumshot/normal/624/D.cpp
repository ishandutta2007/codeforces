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

int gcd(int x, int y) {
	return (x == 0?y : gcd(y % x, x));
}

bool solve() {

	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);

	vec< int > t(n + 1);
	int g = 0;

	for(int i = 1;i <= n;i++) {
		scanf("%d", &t[i]);
		g = gcd(g, t[i]);
	}
	
	if(g > 1) {
		puts("0");
		return true;
	}

	vec< int > pr(n + 1), sf(n + 1);

	pr[1] = t[1];

	for(int i = 2;i <= n;i++) {
		pr[i] = gcd(pr[i - 1], t[i]);
	}

	sf[n] = t[n];

	for(int i = n - 1;i >= 1;i--) {
		sf[i] = gcd(sf[i + 1], t[i]);
	}

	vec< int > tmp;
	ll ans = 1ll * (n - 1) * a;

	for(int d = -1;d <= 1;d++) {
		int value = t[1] + d;
		for(int x = 2;x * x <= value;x++) {
			if(value % x == 0) {
				value /= x;
				tmp.push_back(x--);
			}
		}
		if(value > 1) tmp.push_back(value);
		value = t[n] + d;
		for(int x = 2;x * x <= value;x++) {
			if(value % x == 0) {
				value /= x;
				tmp.push_back(x--);
			}
		}
		if(value > 1) tmp.push_back(value);
	}

	sort(ALL(tmp));
	tmp.resize(unique(ALL(tmp)) - tmp.begin());

	for(auto p : tmp) {
		int L = n, R = 1;
		for(int i = 1;i <= n;i++) {
			if((t[i] - 1) % p != 0 && (t[i] + 1) % p != 0 && t[i] % p != 0) {
				L = min(L, i);
				R = max(R, i);
			}
		}
		
		if(L > R) {
			int cnt = n;
			for(int i = 1;i <= n;i++) {
				if(t[i] % p == 0) cnt--;
			}
			ans = min(ans, 1ll * b * cnt);
		}

		vec< int > c(n + 1);
		for(int cnt = 0, i = 1;i <= n;i++) {
			if((t[i] - 1) % p == 0 || (t[i] + 1) % p == 0) cnt++;
			c[i] = cnt;
		}

		vec< ll > mn(n + 1);
		ll T = inf64;

		for(int r = n;r >= R;r--) {
			T = min(T, 1ll * a * r - 1ll * b * c[r]);
			mn[r] = T;
		}

		for(int l = 1;l <= L;l++) {
			ans = min(ans, 1ll * b * (c[l - 1] + c[n]) + 1ll * a * (1 - l) + mn[max(R, l)]);
		}
	}
	
	cout << ans << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}