#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	string s;
	int n, m, l, r;
	char a, b;

	cin >> n >> m >> s;

	while (m--) {
		cin >> l >> r >> a >> b;
		l--, r--;

		while (l <= r) {
			if (s[l] == a)
				s[l] = b;
			l++;
		}
	}

	cout << s << endl;

	return 0;
}