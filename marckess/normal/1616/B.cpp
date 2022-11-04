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
	int n;
	string s;
	
	cin >> n >> s;
	
	if (n > 1 && s[0] == s[1]) {
		cout << s[0] << s[1] << endl;
		return;
	}
	
	forn (i, n - 1)
		if (s[i] < s[i + 1]) {
			string res = s.substr(0, i + 1);
			cout << res;
			reverse(all(res));
			cout << res << endl;
			return;
		}
	
	cout << s;
	reverse(all(s));
	cout << s << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}