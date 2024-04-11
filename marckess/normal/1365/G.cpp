#include <bits/stdc++.h>
 
//#define endl '\n'
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

int n;
ll x[15];
vi v;

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	for (int i = 0; i < (1 << 13); i++)
		if (__builtin_popcount(i) == 6)
			v.pb(i);

	cin >> n;

	forn (i, 13) {
		vi w;

		for (int j = 1; j <= n; j++)
			if (v[j] & (1 << i))
				w.pb(j);

		if (w.empty()) continue;

		cout << "? " << w.size();
		for (int x : w)
			cout << " " << x;
		cout << endl;

		cin >> x[i];
		if (x[i] == -1) exit(0);
	}

	cout << "!";
	for (int i = 1; i <= n; i++) {
		ll res = 0;

		forn (j, 13)
			if (!(v[i] & (1 << j)))
				res |= x[j];
		
		cout << " " << res;
	}
	cout << endl;

	return 0;
}