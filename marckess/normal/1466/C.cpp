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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n;
string s;

void solve () {
	cin >> s;
	n = s.size();
	
	int res = 0;
	
	forn (i, n) {
		if (i >= 1 && s[i] && s[i - 1] && s[i] == s[i - 1]) {
			s[i] = 0;
			res++;
		} else if (i >= 2 && s[i] && s[i - 2] && s[i] == s[i - 2]) {
			s[i] = 0;
			res++;
		}
	}
	
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}