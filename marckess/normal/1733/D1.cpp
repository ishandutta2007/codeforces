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

const int MX = 3005;
int n;
ll x, y;
string s, t;

void main_() {
	cin >> n >> x >> y >> s >> t;
	vi a;
	forn (i, n)
		if (s[i] != t[i])
			a.pb(i);
	
	if (a.size() % 2) {
		cout << -1 << endl;
		return;
	}
	
	if (a.size() == 2 && a[0] + 1 == a[1]) {
		cout << min(x, 2 * y) << endl;
		return;
	}
	
	cout << a.size() * y / 2 << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}