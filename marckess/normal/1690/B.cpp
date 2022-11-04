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

const int MX = 500005;
int n, a[MX], b[MX];

void main_() {
	cin >> n;
	forn (i, n) cin >> a[i];
	int mx = 0;
	forn (i, n) {
		cin >> b[i];
		mx = max(mx, a[i] - b[i]);
	}
	forn (i, n) a[i] = max(0, a[i] - mx);
	forn (i, n)
		if (a[i] != b[i]) {
			cout << "NO" << endl;
			return;
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