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

bool solve() {

	int n;

	cin >> n;

	vec< int > a(n); 
	for(int i = 0;i < n;i++) {
		char x;
		cin >> x;
		a[i] = x - '0';
	}

	vec< vec< int > > dp(n, vec< int >(n + 1));
	vec< vec< int > > lcp(n, vec< int >(n, 0));

	for(int i = n - 1;i >= 0;i--) {
		for(int j = n - 1;j >= 0;j--) {
			if(a[i] != a[j]) lcp[i][j] = 0;
			else lcp[i][j] = 1 + (i + 1 < n && j + 1 < n?lcp[i + 1][j + 1] : 0);
		}
	}

	for(int i = 0;i < n;i++) dp[i][i + 1] = 1;

	for(int i = 0;i < n;i++) {
		for(int j = i;j >= 0;j--) {
			if(a[j] == 0) continue;
			int l = i - j + 1;
			
			int ql, qr;

			qr = j - 1;
			ql = qr - l + 1;

			int ok = 0;

			if(ql >= 0) {
				int _lcp = min(lcp[ql][j], l);
				if(_lcp < l && a[j + _lcp] > a[ql + _lcp]) ok = 1;
			}

			if(ok) dp[i][l] = (dp[i][l] + (j?dp[j - 1][l] : 0)) % base;
			else dp[i][l] = (dp[i][l] + (j?dp[j - 1][l - 1] : 0)) % base;
		}

		for(int l = 1;l <= n;l++) dp[i][l] = (dp[i][l] + dp[i][l - 1]) % base;
	}

	cout << dp[n - 1][n] << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}