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

int n, x, y;
string a, b;

bool query (int a, int b, int c, int d) {
	string res;
	cout << '?' << " " << a << " " << b
		 << " " << c << " " << d << endl;
	fflush(stdout);
	cin >> res;
	assert(res != "BAD");
	return res == "YES";
}

void print (string s) {
	cout << '!' << " " << s << endl;
	fflush(stdout);
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	x = y = 1;
	while (x + y <= n) {
		if (query(y, x+1, n, n)) {
			x++;
			a.push_back('R');
		} else {
			y++;
			a.push_back('D');
		}
	}

	x = y = n;
	while (x + y > n+1) {
		if (query(1, 1, y-1, x)) {
			y--;
			b.push_back('D');
		} else {
			x--;
			b.push_back('R');
		}
	}

	reverse(ALL(b));
	print(a+b);

	return 0;
}