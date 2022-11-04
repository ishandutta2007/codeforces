#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
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

const int MX = 100005;
int n, m, x, s[MX];
int h[MX];

void solve () {
	cin >> n >> m >> x;
	forn (i, n) {
		cin >> h[i];
		s[i] = 0;
	}
	
	priority_queue<ii, vii, greater<ii>> pq;
	forn (i, m)
		pq.emplace(0, i);
	
	cout << "YES" << endl;
	forn (i, n) {
		int u = pq.top().se;
		pq.pop();
		
		cout << u + 1 << " ";
		s[u] += h[i];
		
		pq.emplace(s[u], u);
	}
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}