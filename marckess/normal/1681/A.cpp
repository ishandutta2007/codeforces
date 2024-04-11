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

const int MX = 55;
int n, m, a[MX], b[MX];

void main_() {
	cin >> n;
	forn (i, n) cin >> a[i];
	cin >> m;
	forn (i, m) cin >> b[i];
	sort(a, a + n, greater<int>());
	sort(b, b + m, greater<int>());
	if (a[0] >= b[0]) cout << "Alice" << endl;
	else cout << "Bob" << endl;
	if (a[0] <= b[0]) cout << "Bob" << endl;
	else cout << "Alice" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}