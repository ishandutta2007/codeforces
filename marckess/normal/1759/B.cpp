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

int n, s, b[55], ex[1111];

void main_() {
	int mx = 0;
	cin >> n >> s;
	memset(ex, 0, sizeof(ex));
	forn (i, n) {
		cin >> b[i];
		ex[b[i]] = 1;
		mx = max(mx, b[i]);
	}
	int tot = 0;
	forr (i, 1, 1000) {
		if (!ex[i])
			tot += i;
		if (i >= mx && tot == s) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}