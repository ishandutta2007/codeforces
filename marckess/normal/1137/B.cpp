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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 500005;
string s, t;
int f[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> s >> t;

	f[0] = -1;
	for (int i = 0; i < t.size(); i++) {
		f[i+1] = f[i];
		while (f[i+1] >= 0 && t[f[i+1]] != t[i])
			f[i+1] = f[f[i+1]];
		f[i+1]++;
	}

	int a = 0, b = 0;
	for (char c : s)
		if (c == '1') a++;
		else b++;

	for (int i = 0, j = 0; i < s.size(); i++) {
		if (t[j] == '1') {
			if (a) {
				cout << '1';
				a--;
			} else {
				cout << '0';
				while (f[j] >= 0 && t[j] != '0')
					j = f[j];
				b--;
			}
			j++;
			if (j == t.size()) j = f[j];
		} else {
			if (b) {
				cout << '0';
				b--;
			} else {
				cout << '1';
				while (f[j] >= 0 && t[j] != '1')
					j = f[j];
				a--;
			}
			j++;
			if (j == t.size()) j = f[j];
		}
	}
	cout << endl;

	return 0;
}