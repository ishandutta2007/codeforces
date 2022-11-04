#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 2000005;
int n, a[MX], res, cn[MX];
bitset<MX> bs;
vi r;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	bs.set();
	bs[0] = bs[1] = 0;

	for (ll i = 2; i < MX; i++)
		if (bs[i])
			for (ll j = i * i; j < MX; j += i)
				bs[j] = 0;

	cin >> n;
	forn (i, n) {
		cin >> a[i];
		res = 1;
		r = {a[i]};
		cn[a[i]]++;
	}

	forn (i, n) forn (j, i) {
		if (!bs[a[i] + a[j]]) continue;

		int p = 2;
		if (a[i] == 1 || a[j] == 1)
			p = cn[1] + (a[i] != 1 || a[j] != 1);
		
		if (p > res) {
			res = p;
			r = {a[i], a[j]};
		}
	}

	sort(all(r));
	r.erase(unique(all(r)), r.end());

	cout << res << endl;
	for (int x : r) {
		if (x == 1) {
			while (cn[x]--)
				cout << x << " ";
		} else {
			cout << x << " ";
		}
	}
	cout << endl;

	return 0;
}