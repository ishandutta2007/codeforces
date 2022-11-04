#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005;
int n, a[MX];
set<int> st;

bool esPos (int m) {
	deque<ii> q;
	vi v;
	
	forn (i, n) {
		while (q.size() && q.back().fi > a[i])
			q.pop_back();
			
		while (q.size() && q.front().se < i - m + 1)
			q.pop_front();
		
		q.emplace_back(a[i], i);
		
		if (i - m + 1 >= 0)
			v.pb(q.front().fi);
	}
	
	sort(all(v));
	if (v[0] != 1 || v.back() != v.size()) return 0;
	
	forn (i, int(v.size()) - 1)
		if (v[i] == v[i + 1])
			return 0;
	
	return 1;
}

void solve () {
	cin >> n;
	
	st.clear();
	
	forn (i, n) {
		cin >> a[i];
		st.insert(a[i]);
	}
	
	if (n == 1) {
		cout << 1 << endl;
		return;
	}
	
	int i = 2, j = n + 1, rep = 20;
	
	while (rep--) {
		int m = (i + j) / 2;
		if (esPos(m)) j = m;
		else i = m;
	}
	
	cout << int(st.size() == n);
	for (int i = 2; i <= n; i++)
		cout << int(i >= j);
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve ();
	
	return 0;
}