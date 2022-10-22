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
#include <bitset>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

const ll base = inf + 7;

int k;

ll f(string & s) {
	vec< ll > dp(k);

	ll cur = 0;

	for(auto i : s) {
		ll val = dp[i - 'a'];
		dp[i - 'a'] = 1 + cur;
		cur = (cur - val + 1 + cur);
		cur = (cur % base + base) % base;
	}

	ll res = 1;
	for(auto i : dp) res = (res + i) % base;
	return res;
}

bool solve() {
	
	int n, m;

	cin >> n >> k;

	string s;
	cin >> s;

	m = (int)s.size();

	vec< int > last(k, -1);
	for(int i = 0;i < m;i++) {
		last[s[i] - 'a'] = i;
	}

	for(int i = m;i < n + m;i++) {
		int tmp = -1;
		for(int j = 0;j < k;j++) {
			if(tmp == -1 || last[tmp] > last[j]) tmp = j;
		}
		s.push_back(char(tmp + 'a'));
		last[tmp] = i;
	}

	cout << f(s) << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();	
	
	return 0;
}