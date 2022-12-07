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

string s;

void main_() {
	cin >> s;
	forn (i, (int)s.size() - 1) {
		if (s[i] == 'Y' && s[i + 1] != 'e') {
			cout << "NO" << endl;
			return;
		}
		if (s[i] == 'e' && s[i + 1] != 's') {
			cout << "NO" << endl;
			return;
		}
		if (s[i] == 's' && s[i + 1] != 'Y') {
			cout << "NO" << endl;
			return;
		}
		
	}
	forn (i, (int)s.size()) {
		if (s[i] != 'Y' && s[i] != 'e' && s[i] != 's') {
			cout << "NO" << endl;
			return;
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