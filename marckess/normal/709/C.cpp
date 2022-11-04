#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int acu[256], n;
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> s;
	n = s.size();

	for (char c : s) acu[c]++;

	if (acu['a'] == n)
		s.back() = 'z';
	else {
		int f = 1;
		for (char &c : s) {
			if (c == 'a') {
				if (!f)
					break;
			} else {
				c--;
				f = 0;
			}
		}
	}

	cout << s << endl;

	return 0;
}