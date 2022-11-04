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
int n, p[MX];

void main_() {
	cin >> n;
	map<int, vi> mp;
	forn (i, n) {
		int a;
		cin >> a;
		mp[a].pb(i);
	}
	
	for (auto it : mp) {
		if (it.se.size() < 2) {
			cout << -1 << endl;
			return;
		}
		vi &v = it.se;
		forn (i, v.size())
			p[v[i]] = v[(i + 1) % v.size()];
	}
	
	forn (i, n)
		cout << p[i] + 1 << " ";
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