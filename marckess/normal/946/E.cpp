#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int t;
string s;

bool men() {
	bool f = s.front() == '1' && s.back() == '1';
	bool d = s.front() == '1' && s.back() == '0';
	
	for (int i = 1; i + 1 < s.size(); i++) {
		f &= s[i] == '0';
		d &= s[i] == '0';
	}

	return f || d;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> t;
	while (t--) {
		cin >> s;

		if (men()) {
			for (int i = 2; i < s.size(); i++)
				cout << '9';
			cout << endl;
			continue;
		}

		int mk = 0;
		for (char &c : s) {
			c -= '0';
			mk ^= 1 << c;
		}

		bool res = 0;
		for (int i = (int)s.size()-1; i >= 0 && !res; i--) {
			mk ^= 1 << s[i];

			for (int j = (int)s[i]-1; j >= 0 && !res; j--) {
				int d = __builtin_popcount(mk ^ (1 << j));
				int m = (int)s.size() - i - 1;

				if (m >= d && (m - d) % 2 == 0) {
					mk ^= 1 << j;
					for (int k = 0; k < i; k++)
						cout << char(s[k]+'0');
					cout << char(j+'0');

					m -= d;
					while (m--)
						cout << '9';

					for (int k = 9; k >= 0; k--)
						if (mk & (1 << k))
							cout << char(k+'0');
					cout << endl;

					res = 1;
				}
			}
		}

		assert(res);
	}

	return 0;
}