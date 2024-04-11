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
vi a, b;

void main_() {
	cin >> n;
	a = b = vi(n);
	forn (i, n) cin >> a[i];
	forn (i, n) cin >> b[i];
	
	int x = 0, y = 0, z = 0;
	for (char c : a) x += c == 0;
	for (char c : b) y += c == 0;
	forn (i, n) z += a[i] != b[i];
	
	if (abs(x - y) >= z) cout << abs(x - y) << endl;
	else cout << abs(x - y) + 1 << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}