#include <bits/stdc++.h>

//#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 105;
int n;
vii x, y;

void ans (int b, vii &v) {
	cout << b << " " << v.back().fi << " " << v.back().se << endl;
	v.pop_back();
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if ((i + j) % 2) x.pb({i, j});
			else y.pb({i, j});
		}
	
	forn (kk, n * n) {
		int a;
		cin >> a;
		
		if (a == 1) {
			if (y.size()) ans(2, y);
			else ans(3, x);
		} else if (a == 2) {
			if (x.size()) ans(1, x);
			else ans(3, y);
		} else {
			if (x.size()) ans(1, x);
			else ans(2, y);
		}
	}

	return 0;
}