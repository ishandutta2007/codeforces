#include <bits/stdc++.h>
 
#define endl '\n'
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
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MX = 200005;
int n, mod, a[MX];
ll res = 1;
set<int> st;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> mod;
	forn(i, n) {
		cin >> a[i];
		if (st.count(a[i] % mod)) {
			cout << 0 << endl;
			return 0;
		}
		st.insert(a[i] % mod);
	}

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			(res *= abs(a[i] - a[j])) %= mod;

	cout << res << endl;

	return 0;
}