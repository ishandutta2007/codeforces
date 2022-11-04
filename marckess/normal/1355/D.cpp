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
 
int n, s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	cin >> n >> s;

	if (n == s) {
		cout << "NO" << endl;
		return 0;
	}

	if (n != 1 && s < 2 * n) {
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
	forn (i, n - 1) {
		cout << 2 << " ";
		s -= 2;
	}

	cout << s << endl << 1 << endl;

	return 0;
}