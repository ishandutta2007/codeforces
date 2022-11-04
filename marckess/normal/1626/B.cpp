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

void main_() {
	string s;
	cin >> s;
	int n = s.size();
	
	for (int i = n - 2; i >= 0; i--) {
		if (s[i] + s[i + 1] - 2 * '0' >= 10) {
			forn (j, i)
				cout << s[j];
			cout << s[i] + s[i + 1] - 2 * '0';
			forr (j, i + 2, n - 1)
				cout << s[j];
			cout << endl;
			return;
		}
	}
	
	
	cout << s[0] + s[1] - 2 * '0';
	forr (j, 2, n - 1)
		cout << s[j];
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}