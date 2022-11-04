#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1000005, mod = 1000000007;
int n, sig[MX], f, suf;
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> s;
	n = s.size();

	sig[n] = -1;
	for (int i = n - 1; i >= 0; i--) {
		sig[i] = sig[i + 1];
		if (s[i] == '1') sig[i] = i, f = 1;
	}

	if (!f) {
		cout << n << endl;
		return 0;
	}

	for (int i = n - 1; i >= 0 && s[i] == '0'; i--, suf++);

	ll acu = 0, last = 0, cn = 0;
	stack<ii> st;

	for (int i = n - 1 - suf; i >= sig[0]; i--) {		
		(acu += last) %= mod;
		
		if (s[i] == '0') {
			cn++;

			if (st.size()) {
				(acu -= st.top().se) %= mod;
				if (cn == st.top().fi) st.pop();
			}
		} else {
			ll t = acu;

			if (cn) st.emplace(cn, last);
			(acu -= last) %= mod;

			last = (t + suf + 1) % mod; 

			cn = 0;
		}

		if (i == sig[0]) cout << MOD((i + 1) * last, mod) << endl;
	}

	return 0;
}