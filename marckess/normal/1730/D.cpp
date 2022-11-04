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
set<pair<vi, vi>> st;
queue<pair<vi, vi>> q;
string s, t;

void main_() {
	/* cin >> n;
	
	a = b = vi(n);
	iota(all(a), 0);
	iota(all(b), n);	
	
	st.insert({a, b});
	q.push({a, b});
	
	while (q.size()) {
		vi a = q.front().fi;
		vi b = q.front().se;
		q.pop();
		
		forr (k, 1, n) {
			vi x = a;
			vi y = b;
			
			forn (i, k)
				swap(x[i], y[n - k + i]);
			
			if (!st.count({x, y})) {
				q.push({x, y});
				st.insert({x, y});
			}
		}
	}
	
	cout << st.size() << endl;
	for (auto it : st) {
		for (int x : it.fi) cout << x << " "; cout << endl;
		for (int x : it.se) cout << x << " "; cout << endl;
		cout << endl;
	} */
	
	cin >> n >> s >> t;
	map<string, int> mp;
	
	forn (i, n) {
		string k = {s[i], t[n - i - 1]};
		sort(all(k));
		mp[k]++;
	}
	
	int cn = 0;
	for (const auto &it : mp) {
		if (it.se & 1) {
			if (it.fi[0] != it.fi[1]) {
				cout << "NO" << endl;
				return;
			}
			cn++;
		}
	}
	
	if (cn <= 1) cout << "YES" << endl;
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