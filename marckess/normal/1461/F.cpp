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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005, lim = 2 * MX;
int n, a[MX], dp[MX], sig[MX];
string s;
vi v;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n) cin >> a[i];
	cin >> s;
	
	if (s.size() == 1) {
		forn (i, n)	{
			cout << a[i];
			if (i + 1 < n)
				cout << s[0];
		}
		cout << endl;
		return 0;
	}
	
	if (s.size() == 2 && (s[0] == '-' || s[1] == '-')) {
		if (s[0] == '+' || s[1] == '+') {
			forn (i, n) {
				cout << a[i];
				if (i + 1 < n)
					cout << '+';
			}
		} else {
			int f = 1;
			forn (i, n) {
				cout << a[i];
				if (i + 1 < n) {
					if (a[i] == 0 || !f)
						cout << '*';
					else if (a[i + 1] == 0) {
						cout << '-';
						f = 0;
					} else {
						cout << '*';
					}
				}
			}
		}
		cout << endl;
		return 0;
	}
	
	for (int i = n - 1, p = 1; i >= 0; i--) {
		if (a[i] == 0) {
			p = 1;
			sig[i] = i;
			v.clear();
		} else if (a[i] == 1) {
			sig[i] = i;
			dp[i] = dp[i + 1] + 1;
		} else {
			p *= a[i];
			p = min(p, lim);
			
			if (p == lim) {
				sig[i] = v[0];
				dp[i] = lim;
			} else {
				v.pb(i);
				
				for (int j = int(v.size()) - 1, f = 1; j >= 0; j--) {
					f *= a[v[j]];
					
					if (f + dp[v[j] + 1] > dp[i]) {
						dp[i] = f + dp[v[j] + 1];
						sig[i] = v[j];
					}
				}
			}
		}
	}
	
	int to = -1;
	forn (i, n) {
		cout << a[i];
		
		if (to < i)
			to = sig[i];
			
		if (i + 1 < n)
			cout << "+*"[i < to];
	}
	cout << endl;
	
	return 0;
}