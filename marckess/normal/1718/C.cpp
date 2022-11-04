#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, q, a[MX], bs[MX];
vi divi, pos[MX];
multiset<ll> mst;

void main_() {
	cin >> n >> q;
	forn (i, n)
		cin >> a[i];
	
	for (int i = 2; i <= n; i++)
		if (n % i == 0)
			if (!bs[i])
				divi.pb(n / i);
	
	for (int d : divi) {
		pos[d] = vi(d);
		
		forn (i, n)
			pos[d][i % d] += a[i];
		
		forn (i, d)
			mst.insert(d * pos[d][i]);
	}
	cout << *mst.rbegin() << endl;
	
	while (q--) {
		int p, x;
		cin >> p >> x;
		p--;
		
		for (int d : divi) {
			mst.erase(mst.find(d * pos[d][p % d]));
			pos[d][p % d] -= a[p];
			
			pos[d][p % d] += x;
			mst.insert(d * pos[d][p % d]);
		}
		
		a[p] = x;
		cout << *mst.rbegin() << endl;
	}
	
	for (int d : divi)
		pos[d].clear();
	mst.clear();
	divi.clear();
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	for (ll i = 2; i < MX; i++)
		if (!bs[i])
			for (ll j = i * i; j < MX; j += i)
				bs[j] = 1;
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}