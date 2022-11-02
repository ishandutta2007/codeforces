#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int BASE1 = 313;
const int BASE2 = 31;
const ll MOD = 1000 * 1000 * 1000 + 7;

const int N = (int)1e6;

ll pw1[N];
ll pw2[N];

set<pair<ll, ll>> was[N];

ull geth1(string s) {
    ull res = 0;
    for (int i = 0; i < s.length(); i++)
	res = (res * BASE1 + s[i] - 'a' + 1) % MOD;
    return res;
}

ll geth2(string s) {
    ll res = 0;
    for (int i = 0; i < s.length(); i++) 
	res = (res * BASE2 + s[i] - 'a' + 1) % MOD;
    return res;
}


int main() {
    ios_base::sync_with_stdio(0);
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < N; i++) {
	pw1[i] = pw1[i - 1] * BASE1 % MOD;
	pw2[i] = pw2[i - 1] * BASE2 % MOD;
    }
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
	string s;
	cin >> s;
	pair<ll, ll> p = make_pair(geth1(s), geth2(s));
	was[s.length()].insert(p);
    }
    for (int i = 0; i < m; i++) {
	string s;
	cin >> s;
	int len = s.length();
	bool ok = false;
	ll h1 = geth1(s);
	ll h2 = geth2(s);
	for (int j = 0; j < s.length() && !ok; j++) {
	    for (int c = 'a'; c <= 'c' && !ok; c++) {
		if (c == s[j])
		    continue;
		ll nh1 = ((h1 + pw1[len - 1 - j] * (c - s[j])) % MOD + MOD) % MOD;
		ll nh2 = ((h2 + pw2[len - 1 - j] * (c - s[j])) % MOD + MOD) % MOD;
		if (was[len].count(make_pair(nh1, nh2)))
		    ok = true;
	    }
	}
	if (ok)
	    cout << "YES\n";
	else
	    cout << "NO\n";
    }
    return 0;
}