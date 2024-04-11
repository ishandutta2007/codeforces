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

string s;
ll res, n;
char c;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> s;

	c = s.back();
	s.pop_back();
	n = stoll(s);

	if (n % 4 == 0) {
		res = n - 3;
		res += 6 * (n / 4);
		res += 6 * (n / 4 - 1);
	} else if (n % 4 == 1) {
		res = n - 1;
		res += 12 * (n / 4);
	} else if (n % 4 == 2) {
		res = n - 1;
		res += 6 * (n / 4 + 1);
		res += 6 * (n / 4);
	} else {
		res = n - 3;
		res += 12 * (n / 4);
	}

	if (c >= 'd') res += 'f' - c;
	else res += 3 + c - 'a';

	cout << res + 1 << endl;
	
	return 0;
}