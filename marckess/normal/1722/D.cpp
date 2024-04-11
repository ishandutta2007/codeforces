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
string s;
vi a;

void main_() {
	cin >> n >> s;
	ll tot = 0;
	a.clear();
	forn (i, n) {
		if (s[i] == 'L') {
			tot += i;
			a.pb((n - i - 1) - i);
		} else {
			tot += n - i - 1;
			a.pb(i - (n - i - 1));
		}
	}
	
	sort(all(a), greater<int>());
	forn (i, n) {
		tot = max(tot, tot + a[i]);
		cout << tot << " ";
	}
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