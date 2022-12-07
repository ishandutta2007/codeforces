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

ll n, s;

bool f (int m) {
	int ptr = 2;
	ll mn = 0;
	
	queue<ii> q;
	q.push({1, 1});
	
	while (q.size()) {
		auto [u, lvl] = q.front();
		q.pop();
		
		mn += lvl;
		
		for (int i = 0; i < m && ptr <= n; i++, ptr++)
			q.push({ptr, lvl + 1});
	}
	
	return mn <= s;
}

void main_() {
	cin >> n >> s;
	
	if (s < 2 * n - 1 || n * (n + 1) / 2 < s) {
		cout << "No" << endl;
		return;
	}
	
	cout << "Yes" << endl;
	
	int i = 1, j = n, rep = 20;
	while (rep--) {
		int m = (i + j) / 2;
		if (f(m)) j = m;
		else i = m;
	}
	
	vi p(n + 1), lvl(n + 1), isfi(n + 1), fi(1);
	int ptr = 2;
	ll mn = 0;
	
	queue<ii> q;
	q.push({1, 1});
	
	while (q.size()) {
		auto [u, l] = q.front();
		q.pop();
		
		mn += l;
		lvl[u] = l;
		if ((int)fi.size() == l) {
			fi.pb(u);
			isfi[u] = l;
		}
		
		for (int i = 0; i < j && ptr <= n; i++, ptr++) {
			q.push({ptr, l + 1});
			p[ptr] = u;
		}
	}
	
	for (int u = n; mn < s; u--) {
		if (isfi[u]) continue;
		int to = fi.size();
		
		if (mn + to - lvl[u] > s)
			to = s - (mn - lvl[u]);
		
		mn += to - lvl[u];
		p[u] = fi[to - 1];
		lvl[u] = to;
		
		if (to == fi.size()) {
			isfi[u] = 1;
			fi.pb(u);
		}
	}
	
	forr (i, 2, n)
		cout << p[i] << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}