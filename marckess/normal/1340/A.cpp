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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, p[MX], f[MX], cn[MX];
set<int> sig;
multiset<int> ms;

void solve () {
	sig.clear();
	ms.clear();

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		f[p[i]] = i;
		
		cn[i] = 1;
		sig.insert(i);
		ms.insert(1);
	}

	for (int i = 1; i <= n; i++) {
		int x = f[i];

		if (cn[x] != *ms.rbegin()) {
			cout << "no" << endl;
			return;
		}

		int ant = cn[x];
		ms.erase(ms.find(cn[x]));
		sig.erase(x);

		auto it = sig.upper_bound(x);
		if (it != sig.end()) {
			ms.erase(ms.find(cn[*it]));
			cn[*it] += ant;
			ms.insert(cn[*it]);
		}
	}

	cout << "yes" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}