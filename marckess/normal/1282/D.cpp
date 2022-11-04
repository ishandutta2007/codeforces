#include <bits/stdc++.h>
 
//#define endl '\n'
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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int n, in, mn;
string s;
vi a;

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	srand(time(0));

	cout << "a" << endl;
	cin >> in;
	if (!in) return 0;
	n = in + 1;

	if (n <= 300) {
		s.assign(n, 'a');
		cout << s << endl;
		cin >> in;
		if (!in) return 0;
		mn = in;
	}

	if (n > 300 || mn >= n) {
		s.assign(n - 1, 'b');
		cout << s << endl;
		cin >> in;
		return 0;
	}

	a.resize(n);
	iota(all(a), 0);

	for (int i : a) {
		s[i] = 'b';
		cout << s << endl;
		cin >> in;

		if (in < mn)
			mn = in;
		else
			s[i] = 'a';

		if (!in)
			return 0;
	}

	return 0;
}