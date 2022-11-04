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

const int MX = 200005, lim = 5;
int n;
ll a[MX];
map<ll, int> mp;

bool valid (vi &a, int i, int cn, ll s) {
	if (cn == 3) return mp.count(s);
	if (i == a.size()) return 1;
	return valid(a, i + 1, cn, s) && valid(a, i + 1, cn + 1, s + a[i]);
}

void main_() {
	cin >> n;
	mp.clear();
	
	forn (i, n) {
		cin >> a[i];
		mp[a[i]]++;
	}
	
	if (mp.size() > lim) {
		cout << "NO" << endl;
		return;
	}
	
	vi a;
	for (auto it : mp)
		forn (i, min(it.se, 3))
			a.pb(it.fi);
	
	if (valid(a, 0, 0, 0)) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}