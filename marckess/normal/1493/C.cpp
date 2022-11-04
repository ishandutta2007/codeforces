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

const int MX = 100005;
int n, k, cn[256];
string s;

void solve () {
	cin >> n >> k >> s;
	
	if (n % k) {
		cout << -1 << endl;
		return;
	}
	
	memset(cn, 0, sizeof(cn));
	for (char c : s)
		cn[c]++;
	
	int f = 1;
	for (char c : s)
		f &= cn[c] % k == 0;
	
	if (f) {
		cout << s << endl;
		return;
	}
	
	for (int i = n - 1; i >= 0; i--) {
		cn[s[i]]--;
		
		for (int c = s[i] + 1; c <= 'z'; c++) {
			cn[c]++;
			
			int acu = 0;
			for (int j = 'a'; j <= 'z'; j++)
				acu += (k - cn[j] % k) % k;
			
			if (acu <= n - 1 - i) {
				string res;
				
				for (int j = 'z'; j >= 'a'; j--) {
					int lim = (k - cn[j] % k) % k;
					while (lim--)
						res.pb(j);
				}
				
				while (res.size() < n - 1 - i)
					res.pb('a');
				res.pb(c);
				
				i--;
				while (i >= 0) {
					res.pb(s[i]);
					i--;
				}
				
				reverse(all(res));
				cout << res << endl;
				return;
			}
			
			cn[c]--;
		}
	}
	
	cout << -1 << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
		
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}