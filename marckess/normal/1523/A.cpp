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

string s;
int n, m;

void solve () {
	cin >> n >> m >> s;
	
	forn (kk, min(n, m)) {
		string t = s;
		
		forn (j, n) {
			if (s[j] == '1')
				continue;
			
			int cn = 0;
			if (j && s[j - 1] == '1')
				cn++;
			if (j + 1 < n && s[j + 1] == '1')
				cn++;
			
			if (cn == 1)
				t[j] = '1';
		}
		
		s = t;
	}
	
	cout << s << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
 
	return 0;
}