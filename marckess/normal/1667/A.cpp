// Powered by CP Editor (https://cpeditor.org)

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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 5005;
int n;
ll a[MX];

void main_() {
	ll res = 1e18;
	
	cin >> n;
	forn (i, n)
		cin >> a[i];
		
	forn (i, n) {
		ll p = 0, act = 0;
		
		for (int j = i + 1; j < n; j++) {
			ll k = (act + a[j] - 1) / a[j];
			if (k * a[j] == act)
				k++;
			p += k;
			act = k * a[j];
		}
		
		act = 0;
		for (int j = i - 1; j >= 0; j--) {
			ll k = (act + a[j] - 1) / a[j];
			if (k * a[j] == act)
				k++;
			p += k;
			act = k * a[j];
		}
		
		res = min(res, p);
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}