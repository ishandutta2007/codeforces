#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

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
	cin >> n >> s;
	
	reverse(all(s));
	
	int cn = 0, p = 0, res = 0;
	
	while (s.size()) {
		res++;
		
		char act = s.back();
		cn = 0;
		
		while (s.size() && s.back() == act) {
			cn++;
			s.pop_back();
		}
		
		p++;
		p -= min(p, cn - 1);
	}
	
	while (p > 1) {
		res--;
		p -= 2;
	}
	
	cout << res << endl; 
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		solve();	
	
	return 0;
}