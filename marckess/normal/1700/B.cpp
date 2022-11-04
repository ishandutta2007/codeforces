// Powered by CP Editor (https://cpeditor.org)

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

int n;
string s;

void main_() {
	cin >> n >> s;
	
	if (s[0] == '9') {
		string res(n, '0');
		for (int i = n - 1, c = 0; i >= 0; i--) {
			if (s[i] - '0' + 9 + c < 11) {
				res[i] = '0' + 1 - c - (s[i] - '0');
				c = 0;
			} else {
				res[i] = '0' + 11 - c - (s[i] - '0');
				c = 1;
			}
		}
		cout << res << endl;
	} else {
		forn (i, n)
			cout << int('9' - s[i]);
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}