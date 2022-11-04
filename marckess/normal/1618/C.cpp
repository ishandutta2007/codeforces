// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
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
ll a[MX];

void main_() {
	cin >> n;
	forn (i, n)
		cin >> a[i];
	
	ll d = 0;
	for (int i = 0; i < n; i += 2)
		d = __gcd(d, a[i]);
	
	int f = 1;
	for (int i = 1; i < n; i += 2)
		f &= a[i] % d != 0;
	
	if (f) {
		cout << d << endl;
		return;
	}
	
	d = 0;
	for (int i = 1; i < n; i += 2)
		d = __gcd(d, a[i]);
	
	f = 1;
	for (int i = 0; i < n; i += 2)
		f &= a[i] % d != 0;
	
	if (f) cout << d << endl;
	else cout << 0 << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}