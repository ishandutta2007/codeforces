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

const int MX = 200005;
int n, q;
ll a[MX], acu[MX];

void main_() {
	cin >> n >> q;
	forr (i, 1, n) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	forr (i, 1, n) {
		acu[i] = acu[i - 1] + a[i];
	}
	
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << acu[n - x + y] - acu[n - x] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}