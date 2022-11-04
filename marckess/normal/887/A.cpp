#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	string s, res = "no";
	int cant = 0;

	cin >> s;

	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == '0') {
			cant++;
		} else {
			if (cant >= 6) {
				res = "yes";
			}
		}
	}

	cout << res << endl;

	return 0;
}