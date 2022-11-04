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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, k, h[MX], res[MX], ex[MX];
priority_queue<ii> pq;

void solve () {
	cin >> n >> k;
	
	forn (i, n) {
		cin >> h[i];
		ex[i] = 0;
		pq.emplace(h[i], i);
	}
	
	while (pq.size()) {
		int r = pq.top().fi;
		int i = pq.top().se;
		pq.pop();
		
		if (ex[i]) continue;
		res[i] = r;
		ex[i] = 1;
		
		if (i) {
			int w = max(h[i - 1], res[i] - k + 1);
			pq.emplace(w, i - 1);
		}
		
		if (i + 1 < n) {
			int w = max(h[i + 1], res[i] - k + 1);
			pq.emplace(w, i + 1);
		}
	}
	
	forn (i, n)
		if (res[i] - h[i] >= k) {
			cout << "no" << endl;
			return;
		}
	
	if (res[0] == h[0] && res[n - 1] == h[n - 1]) {
		cout << "yes" << endl; 
	} else {
		cout << "No" << endl;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}