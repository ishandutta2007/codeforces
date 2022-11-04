#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
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
ll n;
vi pr, pw;

void solve () {
	cin >> n;
	ll aux = n;
	
	pr.clear();
	pw.clear();
	int res = 0, ind = -1;
	
	for (ll i = 2; i * i <= n; i++)
		if (n % i == 0) {
			pr.pb(i);
			pw.pb(0);
			while (n % i == 0) {
				n /= i;
				pw.back()++;
			}
			if (pw.back() > res) {
				res = pw.back();
				ind = (int)pw.size() - 1;
			}
		}
	
	if (n > 1) {
		pr.pb(n);
		pw.pb(1);
		if (1 > res) {
			res = 1;
			ind = (int)pw.size() - 1;
		}
	}
	
	n = aux;
	cout << res << endl;
	forn (i, res - 1) {
		cout << pr[ind] << " ";
		n /= pr[ind];
	}
	cout << n << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}