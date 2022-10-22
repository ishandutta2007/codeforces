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

const int base = inf + 7;

void add(int & x, int y) {
	x = (x % base + y % base) % base;
}

int m, d;

int get(string x) {
	int n = (int)x.size();
	vec< vec< int > > dp(n + 1, vec< int >(m));
	vec< int > ten(n + 1);

	ten[0] = 1 % m;
	for(int i = 1;i <= n;i++) {
		ten[i] = ten[i - 1] * 10 % m;
	}

	dp[0][0] = 1;

	if(n % 2) {
		for(int i = 1;i <= n;i++) {
			for(int j = 0;j < 10;j++) {
				if(i % 2 == 1 && j == d) continue;
				if(i % 2 == 0 && j != d) continue;
				for(int mod = 0;mod < m;mod++) {
					int now = (ten[i - 1] * j + mod) % m;
					add(dp[i][now], dp[i - 1][mod]);
				}
			}
		}
	}else {	
		for(int i = 1;i <= n;i++) {
			for(int j = 0;j < 10;j++) {
				if(i % 2 == 0 && j == d) continue;
				if(i % 2 == 1 && j != d) continue;
				for(int mod = 0;mod < m;mod++) {
					int now = (ten[i - 1] * j + mod) % m;
					add(dp[i][now], dp[i - 1][mod]);
				}
			}
		}
	}

	int ans = 0;
	
	for(int ost = 0, i = 0;i < n;i += 2) {
		for(int j = (i == 0);j < x[i] - '0';j++) {
			if(j == d) continue;
			int tmp = (ost * ten[n - i] + j * ten[n - i - 1]) % m;
			tmp = ((m - tmp) % m + m) % m;
			add(ans, dp[n - i - 1][tmp]);
		}
		if(x[i] - '0' == d) break;
		ost = (ost * 10 + x[i] - '0') % m;
		if(i + 1 >= n) break;
		if(x[i + 1] - '0' < d) break;
		ost = (ost * 10 + d) % m;
		if(x[i + 1] - '0' > d) {
			int tmp = ((m - ost * ten[n - i - 2]) % m + m) % m;
			add(ans, dp[n - i - 2][tmp]);
			break;
		}
	}

	int value = 0;
	for(auto i : x) value = (value * 10 + i - '0') % m;

	int ok = 1;

	for(int i = 0;i < n;i++) {
		if(i % 2 == 0 && x[i] - '0' == d) { ok = 0; break; }
		if(i % 2 == 1 && x[i] - '0' != d) { ok = 0; break; }
	}

	if(value == 0) add(ans, ok);

	return ans;
}

bool solve() {
	
	cin >> m >> d;

	string l, r;

	cin >> l >> r;

	int n = (int)l.size(), ans = get(r);

	if(l[0] != '1' || count(ALL(l), '0') != n - 1) {
		int p = n - 1;
		while(l[p] == '0') l[p--] = '9';
		l[p]--;
		ans -= get(l);
		ans = (ans % base + base) % base;
	}
	
	cout << ans << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}