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

const int MX = 100005;
int n;
string s;

void main_() {
	cin >> n >> s;
	vi a, b;
	
	forn (i, n) {
		if (s[2 * i] != s[2 * i + 1]) {
			a.pb(2 * i);
			b.pb(s[2 * i] == '1');
		}
	}
	
	if (a.size() % 2) {
		cout << -1 << endl;
		return;
	}
	
	cout << a.size() << endl;
	forn (i, a.size())
		cout << a[i] + (b[i] ^ (i % 2)) + 1 << " ";
	cout << endl;
	
	forn (i, n)
		cout << 2 * i + 1 << " ";
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