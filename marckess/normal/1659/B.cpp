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

int n, k;
string s;

void main_() {
	cin >> n >> k >> s;
	vi res(n);
	
	if (k % 2) {
		forn (i, n) {
			if (k && s[i] == '1') {
				res[i]++;
				k--;
			} else {
				s[i] ^= 1;
			}
		}
	} else {
		forn (i, n) {
			if (k && s[i] == '0') {
				res[i]++;
				s[i] = '1';
				k--;
			}
		}
	}
	
	if (k) {
		res[n - 1] += k;
		if (k % 2)
			s[n - 1] ^= 1;
	}
	
	 cout << s << endl;
	 forn (i, n) cout << res[i] << " ";
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