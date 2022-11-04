#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
#define MOD(n,k) ((((n) % (k)) + (k)) % (k))
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int n, d1, d2, pos1 = -1, pos0 = -1;
char c, g;

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);


	cin >> n;
	string s(n, '0');

	cout << "? " << s << endl;
	fflush(stdout);
	cin >> d1;

	s[0] = '1';
	cout << "? " << s << endl;
	fflush(stdout);
	cin >> d2;

	if (d1 < d2) {
		c = '0';
		g = '1';
		pos0 = 0;
	} else {
		c = '1';
		g = '0';
		pos1 = 0;
	}

	s = string(n, c);
	cout << "? " << s << endl;
	fflush(stdout);
	cin >> d1;

	int i = 1, j = n + 1, m = (i+j)/2, rep = 10;
	while (rep--) {
		string s1(m, g);
		string s2(n-m, c);
		string s = s1+s2;

		cout << "? " << s << endl;
		fflush(stdout);
		cin >> d2;

		if (d2 - d1 == m)
			i = m;
		else
			j = m;
		m = (i+j)/2;
	}

	if (pos0 == -1)
		pos0 = m;
	else
		pos1 = m;

	cout << "! " << pos0 + 1 << " " << pos1 + 1 << endl;
	fflush(stdout);

	return 0;
}