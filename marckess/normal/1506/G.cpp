#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n, ex[256], cn, last[256], sig[256];
string s;

void solve () {
	cin >> s;
	n = s.size();
	
	memset(ex, 0, sizeof(ex));
	memset(last, -1, sizeof(last));
	
	for (char c : s)
		ex[c] = 1;
	
	forn (i, n)
		last[s[i]] = i;
	
	cn = 0;
	forn (i, 'z' + 1)
		cn += ex[i];
	
	int act = 0;
	while (cn--) {
		memset(sig, -1, sizeof(sig));
		for (int i = act; i < n; i++)
			if (sig[s[i]] == -1)
				sig[s[i]] = i;
		
		for (char i = 'z'; i >= 'a'; i--) {
			int f = ex[i];
			
			for (char j = 'z'; j >= 'a'; j--)
				if (ex[j])
					f &= sig[i] <= last[j];
			
			if (f) {
				act = sig[i];
				cout << i;
				ex[i] = 0;
				break;
			}
		}
	}
	
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}