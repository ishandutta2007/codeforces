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

const int MX = 1000015;
int n, q, f[MX], sig[MX][26];
string s;

void main_() {
	cin >> s >> q;
	n = s.size();
	
	{
		int j = 0;
		forn (i, n) {
			f[i + 1] = j = sig[j][s[i] - 'a'];
			
			sig[i][s[i] - 'a'] = i + 1;
			forn (c, 26)
				sig[i + 1][c] = sig[j][c];
		}
	}
	
	while (q--) {
		string t;
		cin >> t;
		
		for (int c : t)
			s.pb(c);
		
		int i = n, j = f[n];
		int ant[26];
		
		forn (c, 26)
			ant[c] = sig[n][c];
		
		while (i < s.size()) {
			f[i + 1] = j = sig[j][s[i] - 'a'];
			
			sig[i][s[i] - 'a'] = i + 1;
			forn (c, 26)
				sig[i + 1][c] = sig[j][c];
			
			cout << j << " ";
			i++;
		}
		
		cout << endl;
		
		forn (c, 26)
			sig[n][c] = ant[c];
		
		for (int c : t)
			s.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}