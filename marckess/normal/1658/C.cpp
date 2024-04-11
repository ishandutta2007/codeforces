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

const int MX = 100005;
int n, c[MX];

void main_() {
	cin >> n;
	forn (i, n)
		cin >> c[i];
	
	vi a;
	forn (i, n)
		if (c[i] == 1) {
			forn (j, n)
				a.pb(c[(i + j) % n]);
			break;
		}
	
	if (!a.size()) {
		cout << "NO" << endl;
		return;
	}
	
	for (int i = 1; i < n; i++) {
		if (
			a[i] == 1 ||
			a[i] > a[i - 1] + 1
		) {
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