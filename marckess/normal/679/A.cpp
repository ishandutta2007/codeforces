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

vi pr;

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);

	pr.push_back(2);
	for (int i = 3; i < 50; i++) {
		bool f = 0;

		for (int x : pr)
			f |= bool(i % x == 0);

		if (!f)
			pr.push_back(i);
	}

	int cn = 0;
	string s;

	for (int x : pr) {
		cout << x << endl;
		fflush(stdout);
		cin >> s;
		if (s == "yes") {
			cn++;
			if (x < 10) {
				cout << x*x << endl;
				fflush(stdout);
				cin >> s;
				if (s == "yes")
					cn++;
			}
		}
	}

	if (cn <= 1)
		cout << "prime" << endl;
	else
		cout << "composite" << endl;

	return 0;
}