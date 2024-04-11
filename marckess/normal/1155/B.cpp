#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
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

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	string s;
	bitset<100005> ex;

	cin >> n >> s;

	ex.set();
	int i = 0, j = 0, f = 1;
	while (n > 11) {
		if (f) {
			while (i < s.size() && s[i] == '8') i++;
			if (i < s.size()) ex[i++] = 0;
		} else {
			while (j < s.size() && s[j] != '8') j++;
			if (j < s.size()) ex[j++] = 0;
		}

		f = 1 - f;
		n--;
	}

	for (int i = 0; i < s.size(); i++)
		if (ex[i]) {
			if (s[i] == '8') cout << "YES" << endl;
			else cout << "NO" << endl;
			return 0;
		}
	
	return 0;
}