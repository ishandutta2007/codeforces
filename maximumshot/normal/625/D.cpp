#include <iostream>
#include <vector>
#include <algorithm>
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

int rev(int x) {
	int y = 0;
	while(x) y = y * 10 + x % 10, x /= 10;
	return y;
}

string s, t;
int n;

vec< vec< vec< char > > > dp, vis;

int f(int sum) {
	return min(9, sum);
}

bool rec(int i, int l, int r) {
	if(vis[i][l][r]) return dp[i][l][r];
	vis[i][l][r] = 1;

	int j = n - 1 - i;
	
	if(i == j) {
		for(int x = 0;x < 10;x++) {
			if(i == 0 && x == 0) continue;
			if((x + x + r) / 10 != l) continue;
			if((x + x + r) % 10 != s[i] - '0') continue;
			t[i] = char(x + '0');
			dp[i][l][r] = 1;
			return true;
		}	
		dp[i][l][r] = 0;
		return false;
	}else if(i + 1 == j) {
		for(int x = 0;x < 19;x++) {
			if(i == 0 && x == 0) continue;
			if((x + r) % 10 != s[j] - '0') continue;
			int push = (x + r) / 10;
			if((x + push) % 10 != s[i] - '0') continue;
			if((x + push) / 10 != l) continue;
			t[i] = char(f(x) + '0');
			t[j] = char(x - f(x) + '0');
			dp[i][l][r] = 1;
			return true;
		}
		dp[i][l][r] = 0;
		return false;
	}else {
		
		for(int x = 0;x < 19;x++) {
			if(i == 0 && x == 0) continue;
			if((x + r) % 10 != s[j] - '0') continue;
			if(x % 10 == s[i] - '0') {
				if(x / 10 != l) continue;
				if(rec(i + 1, 0, (x + r) / 10)) {
					dp[i][l][r] = 1;
					t[i] = char(f(x) + '0');
					t[j] = char(x - f(x) + '0');
					return true;
				}
			}
			if((x + 1) % 10 == s[i] - '0') {
				if((x + 1) / 10 != l) continue;
				if(rec(i + 1, 1, (x + r) / 10)) {
					dp[i][l][r] = 1;
					t[i] = char(f(x) + '0');
					t[j] = char(x - f(x) + '0');
					return true;
				}
			}
		}

		dp[i][l][r] = 0;

		return false;
	}
}

bool solve() {

	cin >> s;

	n = (int)s.size();

	dp.resize(n, vec< vec< char > >(2, vec< char >(2, 0)));
	vis = dp;

	t = string(n, '?');

	if(rec(0, 0, 0)) {
		cout << t << '\n';
	}else {
		if(s[0] != '1' || n == 1) {
			cout << 0 << '\n';
		}else {
			
			reverse(ALL(s));
			s.pop_back();

			reverse(ALL(s));
			n--;

			t = string(n, '?');

			dp = vec< vec< vec< char > > >(n, vec< vec< char > >(2, vec< char >(2)));
			vis = dp;

			if(rec(0, 1, 0)) {
				cout << t << '\n';
			}else {
				cout << 0 << '\n';
			}

		}
	}

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}