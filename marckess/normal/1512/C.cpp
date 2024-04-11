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

int a, b;
string s;

void solve () {
	cin >> a >> b >> s;
	
	int i = 0, j = (int)s.size() - 1;
	while (i <= j) {
		if (s[i] != '?' && s[j] != '?' && s[i] != s[j]) {
			cout << -1 << endl;
			return;
		}
		
		if (s[i] != '?') {
			s[j] = s[i];
			
			if (s[i] == '0')
				a -= 2 - (i == j);
			else
				b -= 2 - (i == j);
		} else if (s[j] != '?') {
			s[i] = s[j];
			
			if (s[i] == '0')
				a -= 2 - (i == j);
			else
				b -= 2 - (i == j);
		}
		
		i++, j--;
	}
	
	i = 0, j = (int)s.size() - 1;
	while (i <= j) {
		if (s[i] == '?') {
			if (a >= 2 || (a >= 1 && i == j)) {
				s[i] = s[j] = '0';
				a -= 2 - (i == j);
			} else {
				s[i] = s[j] = '1';
				b -= 2 - (i == j);
			}
		}
		i++, j--;
	}
	
	if (a < 0 || b < 0 || (a % 2 && b % 2)) {
		cout << -1 << endl;
		return;
	}
	
	cout << s << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}