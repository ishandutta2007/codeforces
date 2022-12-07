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

const int MX = 200005;
int n;
ll c, d, a[MX];
vi pos[MX];

ll f (int m) {
	ll res = 0;
	priority_queue<int> pq;
	forn (i, n)
		pq.push(a[i]);
	forr (i, 1, d) {
		for (int x : pos[i])
			pq.push(x);
		pos[i].clear();
		if (pq.empty())
			continue;
		int x = pq.top();
		pq.pop();
		res += x;
		if (i + m + 1 <= d)
			pos[i + m + 1].pb(x);
	}
	return res;
}

void main_() {
	cin >> n >> c >> d;
	forn (i, n)
		cin >> a[i];
	int i = 0, j = MX, rep = 20;
	while (rep--) {
		int m = (i + j + 1) / 2;
		if (f(m) >= c) i = m;
		else j = m;
	}
	if (f(i) < c) {
		cout << "Impossible" << endl;
	} else if (i == MX) {
		cout << "Infinity" << endl;
	} else {
		cout << i << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}