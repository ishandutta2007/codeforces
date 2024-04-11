#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;
int n, a[10 * MX][26];
string s[MX];
vector<pair<string, string>> fi, se;

bool isVowel (char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(a, -1, sizeof(a));

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s[i];

		int t = 0, l;
		for (char c : s[i]) {
			if (isVowel(c)) {
				t++;
				l = c - 'a';
			}
		}

		if (a[t][l] != -1) {
			se.emplace_back(s[a[t][l]], s[i]);
			a[t][l] = -1;
		} else {
			a[t][l] = i;
		}
	}

	for (int i = 0; i < 10 * MX; i++) {
		int f = -1;

		for (int j = 0; j < 26; j++) {
			if (a[i][j] == -1)
				continue;

			if (f != -1) {
				fi.emplace_back(s[f], s[a[i][j]]);
				f = -1;
			} else {
				f = a[i][j];
			}
		}
	}

	if (fi.size() >= se.size()) {
		cout << se.size() << endl;
		for (int i = 0; i < se.size(); i++) {
			cout << fi[i].fi << " " << se[i].fi << endl;
			cout << fi[i].se << " " << se[i].se << endl;
		}
	} else {
		cout << fi.size() + ((int)se.size() - (int)fi.size()) / 2 << endl;
		for (int i = 0; i < fi.size(); i++) {
			cout << fi[i].fi << " " << se[i].fi << endl;
			cout << fi[i].se << " " << se[i].se << endl;
		}
		for (int i = fi.size(); i + 1 < se.size(); i += 2) {
			cout << se[i].fi << " " << se[i+1].fi << endl;
			cout << se[i].se << " " << se[i+1].se << endl;
		}
	}

	return 0;
}