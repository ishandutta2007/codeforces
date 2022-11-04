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
	string a, s;
	cin >> a >> s;
	
	vi res;
	int i = (int)a.size() - 1, j = (int)s.size() - 1;
	
	while (i >= 0 && j >= 0) {
		if (a[i] <= s[j])
			res.pb(s[j] - a[i]);
		else if (j) {
			res.pb(10 * int(s[j - 1] - '0') + int(s[j] - '0') - int(a[i] - '0'));
			j--;
		} else {
			res.pb(-1);
		}
		i--, j--;
		
		if (res.back() < 0 || 9 < res.back()) {
			cout << -1 << endl;
			return;
		}
	}
	
	if (i >= 0) {
		cout << -1 << endl;
		return;
	}
	
	while (j >= 0) {
		res.pb(s[j] - '0');
		j--;
	}
	
	while (res.back() == 0)
		res.pop_back();
	
	reverse(all(res));
	for (int x : res)
		cout << x;
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