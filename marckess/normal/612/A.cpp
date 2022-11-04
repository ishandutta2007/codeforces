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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 105;
int n, p, q;
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> p >> q >> s;

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			if (i * p + j * q == n) {
				cout << i + j << endl;
				for (int k = 0; k < n;) {
					if (i) { 
						forn (kk, p) {
							cout << s[k];
							k++;
						}
						i--;
					} else {
						forn (kk, q) {
							cout << s[k];
							k++;
						}
						j--;
					}
					cout << endl;
				} 

				return 0;
			}

	cout << -1 << endl;

	return 0;
}