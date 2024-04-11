// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
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

int in[256], no[256];
string s;
vi pos[256];

void main_() {
	cin >> s;
	
	for (int i = 'a'; i <= 'z'; i++) {
		in[i] = 0;
		pos[i].clear();
	}
	
	forn (i, s.size()) {
		in[s[i]] = 1;
		pos[s[i]].pb(i);
	}
	
	for (int i = 'a'; i <= 'z'; i++) {
		forn (j, (int)pos[i].size() - 1) {
			memset(no, 0, sizeof(no));
			
			for (int k = pos[i][j]; k <= pos[i][j + 1]; k++)
				no[s[k]] = 1;
			
			for (int k = 'a'; k <= 'z'; k++)
				if (in[k] && !no[k]) {
					cout << "NO" << endl;
					return;
				}
		}
	}
	
	cout << "YES" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}