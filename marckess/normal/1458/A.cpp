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
int n, m;
ll a[MX], b[MX], g;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	forn (i, n) {
		cin >> a[i];
		if (i) g = __gcd(g, a[i] - a[i - 1]);
	}
	
	forn (i, m) {
		cin >> b[i];
		cout << abs(__gcd(g, b[i] + a[0])) << " ";
	}
	cout << endl;
	
	return 0;
}